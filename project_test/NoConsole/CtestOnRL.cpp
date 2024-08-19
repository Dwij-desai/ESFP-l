#include <windows.h>
#include <commctrl.h>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

HWND hMainWnd, hRegistrationWnd, hLoginWnd, hChoiceWnd, hChoiceButton, hAttendanceWnd;
map<wstring, wstring> registeredUsers;
wstring registrationData;
bool shouldExit = false; // Flag to indicate when the program should exit

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);  //Main login page 
LRESULT CALLBACK RegistrationWndProc(HWND, UINT, WPARAM, LPARAM); // registration page for teachers
LRESULT CALLBACK LoginWndProc(HWND, UINT, WPARAM, LPARAM); // Login page for teachers
LRESULT CALLBACK AttendanceWndProc(HWND, UINT, WPARAM, LPARAM); //Main Attendance page for students

void LoadRegistrationData() {
    wifstream file("registration_data.txt");
    wstring line;
    registrationData.clear();
    while (getline(file, line)) {
        registrationData += line + L"\n";
    }
    file.close();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    for (;;)
    {
        LoadRegistrationData(); // Load registration data from file

        WNDCLASSW wc = { 0 };
        wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hInstance = hInstance;
        wc.lpszClassName = L"MainWndClass";
        wc.lpfnWndProc = MainWndProc;
        RegisterClassW(&wc);

        wc.lpszClassName = L"RegistrationWndClass";
        wc.lpfnWndProc = RegistrationWndProc;
        RegisterClassW(&wc);

        wc.lpszClassName = L"LoginWndClass";
        wc.lpfnWndProc = LoginWndProc;
        RegisterClassW(&wc);

        wc.lpszClassName = L"AttendanceWndClass";
        wc.lpfnWndProc = AttendanceWndProc;
        RegisterClassW(&wc);

        hMainWnd = CreateWindowW(L"MainWndClass", L"Student Registration/Login", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT, CW_USEDEFAULT, 700, 500, NULL, NULL, hInstance, NULL);

        MSG msg = { 0 };
        while (GetMessageW(&msg, NULL, 0, 0)) {
            if (shouldExit) {
                break; // Exit the message loop
            }
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }

        // Exit the program when the message loop is exited
        break;
    }
    return 0;
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_CREATE: {
        CreateWindowW(L"button", L"Register", WS_VISIBLE | WS_CHILD, 150, 150, 300, 50, hWnd, (HMENU)1, NULL, NULL);
        CreateWindowW(L"button", L"Login", WS_VISIBLE | WS_CHILD, 150, 250, 300, 50, hWnd, (HMENU)2, NULL, NULL);
        CreateWindowW(L"button", L"Attendance", WS_VISIBLE | WS_CHILD, 150, 350, 300, 50, hWnd, (HMENU)4, NULL, NULL); // Add Attendance button
        CreateWindowW(L"button", L"Exit", WS_VISIBLE | WS_CHILD, 150, 450, 300, 50, hWnd, (HMENU)3, NULL, NULL);
        break;
    }
    case WM_COMMAND:
        if (LOWORD(wp) == 1) { // Register button clicked
            hRegistrationWnd = CreateWindowW(L"RegistrationWndClass", L"Student Registration", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT, CW_USEDEFAULT, 600, 500, NULL, NULL, GetModuleHandle(NULL), NULL);
            ShowWindow(hWnd, SW_HIDE);
        }
        else if (LOWORD(wp) == 2) { // Login button clicked
            hLoginWnd = CreateWindowW(L"LoginWndClass", L"Student Login", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT, CW_USEDEFAULT, 600, 400, NULL, NULL, GetModuleHandle(NULL), NULL);
            ShowWindow(hWnd, SW_HIDE);
        }
        else if (LOWORD(wp) == 3) { // Exit button clicked
            shouldExit = true; // Set the exit flag
            DestroyWindow(hWnd); // Destroy the main window
        }
        else if (LOWORD(wp) == 4) { // Attendance button clicked
            hAttendanceWnd = CreateWindowW(L"AttendanceWndClass", L"Student Attendance", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, GetModuleHandle(NULL), NULL);
            ShowWindow(hWnd, SW_HIDE);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0); // Post WM_QUIT message to exit message loop
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

LRESULT CALLBACK RegistrationWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    static HWND hNameEdit, hEmailEdit, hDobEdit, hCourseEdit, hPasswordEdit, hRegisterButton;
    switch (msg) {
    case WM_CREATE: {
        CreateWindowW(L"static", L"Name:", WS_VISIBLE | WS_CHILD, 50, 80, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hNameEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 170, 80, 300, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);

        CreateWindowW(L"static", L"Email:", WS_VISIBLE | WS_CHILD, 50, 130, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hEmailEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 170, 130, 300, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);

        CreateWindowW(L"static", L"Date of Birth:", WS_VISIBLE | WS_CHILD, 50, 180, 150, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hDobEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 220, 180, 200, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        CreateWindowW(L"static", L"Course:", WS_VISIBLE | WS_CHILD, 50, 230, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
hCourseEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 170, 230, 300, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);

CreateWindowW(L"static", L"Password:", WS_VISIBLE | WS_CHILD, 50, 280, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
hPasswordEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 170, 280, 300, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);

hRegisterButton = CreateWindowW(L"button", L"Register", WS_VISIBLE | WS_CHILD, 200, 350, 200, 50, hWnd, (HMENU)2, GetModuleHandleW(NULL), NULL);
CreateWindowW(L"button", L"Back", WS_VISIBLE | WS_CHILD, 50, 350, 100, 50, hWnd, (HMENU)3, GetModuleHandleW(NULL), NULL); // Add back button
        break;
    }
    case WM_COMMAND:
        if (LOWORD(wp) == 2) { // Register button clicked
            wstring name, email, dob, course, password;
            WCHAR nameBuffer[100], emailBuffer[100], dobBuffer[100], courseBuffer[100], passwordBuffer[100];
            GetWindowTextW(hNameEdit, nameBuffer, 100);
            GetWindowTextW(hEmailEdit, emailBuffer, 100);
            GetWindowTextW(hDobEdit, dobBuffer, 100);
            GetWindowTextW(hCourseEdit, courseBuffer, 100);
            GetWindowTextW(hPasswordEdit, passwordBuffer, 100);
            name = nameBuffer;
            email = emailBuffer;
            dob = dobBuffer;
            course = courseBuffer;
            password = passwordBuffer;
            // Save registration data to file
            wofstream file("registration_data.txt", ios::app);
            if (file.is_open()) {
                file << "--------------------------------------" << L"\n";
                file << L"Name: " << name << L"\n";
                file << L"Password: " << password << L"\n";
                file << L"Email: " << email << L"\n";
                file << L"Date of Birth: " << dob << L"\n";
                file << L"Course: " << course << L"\n\n";
                file.close();
                registeredUsers[name] = password; // Store name-password pair in map
                LoadRegistrationData(); // Reload registration data after updating the file
            }
            // Clear form fields
            SetWindowTextW(hNameEdit, L"");
            SetWindowTextW(hEmailEdit, L"");
            SetWindowTextW(hDobEdit, L"");
            SetWindowTextW(hCourseEdit, L"");
            SetWindowTextW(hPasswordEdit, L"");
        }
        else if (LOWORD(wp) == 3) { // Back button clicked
            ShowWindow(hRegistrationWnd, SW_HIDE); // Hide registration window
            ShowWindow(hMainWnd, SW_SHOW); // Show main window
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

LRESULT CALLBACK LoginWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    static HWND hNameEdit, hPasswordEdit, hLoginButton;
    switch (msg) {
    case WM_CREATE: {
        CreateWindowW(L"static", L"Name:", WS_VISIBLE | WS_CHILD, 100, 100, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hNameEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 220, 100, 300, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        CreateWindowW(L"static", L"Password:", WS_VISIBLE | WS_CHILD, 100, 150, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hPasswordEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 220, 150, 300, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hLoginButton = CreateWindowW(L"button", L"Login", WS_VISIBLE | WS_CHILD, 250, 250, 150, 50, hWnd, (HMENU)3, GetModuleHandleW(NULL), NULL);
        CreateWindowW(L"button", L"Back", WS_VISIBLE | WS_CHILD, 50, 250, 150, 50, hWnd, (HMENU)4, GetModuleHandleW(NULL), NULL); // Add back button
        break;
    }
    case WM_COMMAND:
        if (LOWORD(wp) == 3) { // Login button clicked
            wstring name, password;
            WCHAR nameBuffer[100], passwordBuffer[100];
            GetWindowTextW(hNameEdit, nameBuffer, 100);
            GetWindowTextW(hPasswordEdit, passwordBuffer, 100);
            name = nameBuffer;
            password = passwordBuffer;

            // Check if the name-password pair exists in the registeredUsers map and registration data
            auto it = registeredUsers.find(name);
            bool isValidUser = (it != registeredUsers.end() && it->second == password);
            wstring pattern = L"Name: " + name + L"\nPassword: " + password;
            if (registrationData.find(pattern) != wstring::npos) {
                isValidUser = true;
            }

            if (isValidUser) {
                MessageBoxW(hWnd, L"Login successful!", L"Login", MB_OK);
            } else {
                MessageBoxW(hWnd, L"Invalid name or password.", L"Login", MB_OK);
            }
        }
        else if (LOWORD(wp) == 4) { // Back button clicked
            ShowWindow(hLoginWnd, SW_HIDE); // Hide login window
            ShowWindow(hMainWnd, SW_SHOW); // Show main window
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

void WriteStudentDataToFile(const std::vector<std::wstring>& studentData) {
    std::wofstream file("student_data.txt", std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        for (const auto& data : studentData) {
            file << data << L"\n";
        }
        file.close();
    } else {
        MessageBoxW(NULL, L"Failed to open the file for writing.", L"Error", MB_OK | MB_ICONERROR);
    }
}

LRESULT CALLBACK AttendanceWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) 
{
    static HWND hNameEdit, hRollNoEdit, hBatchNoEdit, hAttendanceEdit, hAddButton, hClearButton;
    static HWND hListView;
    static std::vector<std::wstring> studentNames, studentRollNos, studentBatchNos, studentAttendance;
    static std::vector<std::wstring> studentData;

    switch (msg) {
    case WM_CREATE: {
        CreateWindowW(L"static", L"Name:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hNameEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 170, 50, 200, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);

        CreateWindowW(L"static", L"Roll No.:", WS_VISIBLE | WS_CHILD, 50, 100, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hRollNoEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 170, 100, 200, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);

        CreateWindowW(L"static", L"Batch No.:", WS_VISIBLE | WS_CHILD, 50, 150, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hBatchNoEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 170, 150, 200, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);

        CreateWindowW(L"static", L"Attendance:", WS_VISIBLE | WS_CHILD, 50, 200, 100, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);
        hAttendanceEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 170, 200, 200, 30, hWnd, NULL, GetModuleHandleW(NULL), NULL);

        hAddButton = CreateWindowW(L"button", L"Add", WS_VISIBLE | WS_CHILD, 100, 250, 100, 50, hWnd, (HMENU)1, GetModuleHandleW(NULL), NULL);
        hClearButton = CreateWindowW(L"button", L"Clear", WS_VISIBLE | WS_CHILD, 250, 250, 100, 50, hWnd, (HMENU)2, GetModuleHandleW(NULL), NULL);

        HWND hListView = CreateWindowW(WC_LISTVIEWW, NULL, WS_VISIBLE | WS_CHILD | LVS_REPORT | LVS_SINGLESEL, 50, 300, 600, 200, hWnd, (HMENU)100, GetModuleHandleW(NULL), NULL);

        LV_COLUMNW col;
        col.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
        col.fmt = LVCFMT_LEFT;
        col.cx = 150;

        col.pszText = L"Name";
        ListView_InsertColumn(hListView, 0, &col);

        col.pszText = L"Roll No.";
        ListView_InsertColumn(hListView, 1, &col);

        col.pszText = L"Batch No.";
        ListView_InsertColumn(hListView, 2, &col);

        col.pszText = L"Attendance";
        ListView_InsertColumn(hListView, 3, &col);

        break;
    }
    case WM_COMMAND:
        if (LOWORD(wp) == 1) { // Add button clicked
            std::wstring name, rollNo, batchNo, attendance;
            WCHAR nameBuffer[100], rollNoBuffer[100], batchNoBuffer[100], attendanceBuffer[100];
            GetWindowTextW(hNameEdit, nameBuffer, 100);
            GetWindowTextW(hRollNoEdit, rollNoBuffer, 100);
            GetWindowTextW(hBatchNoEdit, batchNoBuffer, 100);
            GetWindowTextW(hAttendanceEdit, attendanceBuffer, 100);
            name = nameBuffer;
            rollNo = rollNoBuffer;
            batchNo = batchNoBuffer;
            attendance = attendanceBuffer;

            studentNames.push_back(name);
            studentRollNos.push_back(rollNo);
            studentBatchNos.push_back(batchNo);
            studentAttendance.push_back(attendance);

            SetWindowTextW(hNameEdit, L"");
            SetWindowTextW(hRollNoEdit, L"");
            SetWindowTextW(hBatchNoEdit, L"");
            SetWindowTextW(hAttendanceEdit, L"");

            std::wstring studentInfo = L"Name: " + name + L", Roll No.: " + rollNo + L", Batch No.: " + batchNo + L", Attendance: " + attendance;
            studentData.push_back(studentInfo);

            HWND hListView = GetDlgItem(hWnd, 100);
            LVITEMW item;
            item.mask = LVIF_TEXT;
            item.iItem = studentNames.size() - 1;

            item.iSubItem = 0;
            item.pszText = (LPWSTR)name.c_str();
            ListView_InsertItem(hListView, &item);

            item.iSubItem = 1;
            item.pszText = (LPWSTR)rollNo.c_str();
            ListView_SetItem(hListView, &item);

            item.iSubItem = 2;
            item.pszText = (LPWSTR)batchNo.c_str();
            ListView_SetItem(hListView, &item);

            item.iSubItem = 3;
            item.pszText = (LPWSTR)attendance.c_str();
            ListView_SetItem(hListView, &item);

            WriteStudentDataToFile(studentData); // Write student data to file
        } else if (LOWORD(wp) == 2) { // Clear button clicked
            SetWindowTextW(hNameEdit, L"");
            SetWindowTextW(hRollNoEdit, L"");
            SetWindowTextW(hBatchNoEdit, L"");
            SetWindowTextW(hAttendanceEdit, L"");

            studentNames.clear();
            studentRollNos.clear();
            studentBatchNos.clear();
            studentAttendance.clear();
            studentData.clear();

            HWND hListView = GetDlgItem(hWnd, 100);
            ListView_DeleteAllItems(hListView);
        }
        break;
    case WM_DESTROY:
        WriteStudentDataToFile(studentData); // Save student data before destroying the window
        PostQuitMessage(0); // PostQuitMessage(0)
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}