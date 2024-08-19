#include <windows.h>
#include <commctrl.h>
#include <string>
#include <fstream>

using namespace std;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

HWND hNameEdit, hEmailEdit, hDobEdit, hCourseEdit, hRegisterButton;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

    WNDCLASSW wc = { 0 };
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"RegistrationForm";
    wc.lpfnWndProc = WindowProcedure;
    RegisterClassW(&wc);

    HWND hWnd = CreateWindowW(L"RegistrationForm", L"Student Registration", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 400, 300, NULL, NULL, hInst, NULL);

    CreateWindowW(L"static", L"Name:", WS_VISIBLE | WS_CHILD, 10, 10, 50, 20, hWnd, NULL, hInst, NULL);
    hNameEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 70, 10, 200, 20, hWnd, NULL, hInst, NULL);

    CreateWindowW(L"static", L"Email:", WS_VISIBLE | WS_CHILD, 10, 40, 50, 20, hWnd, NULL, hInst, NULL);
    hEmailEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 70, 40, 200, 20, hWnd, NULL, hInst, NULL);

    CreateWindowW(L"static", L"Date of Birth:", WS_VISIBLE | WS_CHILD, 10, 70, 80, 20, hWnd, NULL, hInst, NULL);
    hDobEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 70, 100, 20, hWnd, NULL, hInst, NULL);

    CreateWindowW(L"static", L"Course:", WS_VISIBLE | WS_CHILD, 10, 100, 50, 20, hWnd, NULL, hInst, NULL);
    hCourseEdit = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 70, 100, 200, 20, hWnd, NULL, hInst, NULL);

    hRegisterButton = CreateWindowW(L"button", L"Register", WS_VISIBLE | WS_CHILD, 150, 150, 100, 30, hWnd, (HMENU)1, hInst, NULL);

    MSG msg = { 0 };
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    MessageBox(NULL , "***Code complition successfully ***" , "Run-Code", MB_OK);        // just a basic massage box

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_COMMAND:
        if (LOWORD(wp) == 1) { // Register button clicked
            wstring name, email, dob, course;
            WCHAR nameBuffer[100], emailBuffer[100], dobBuffer[100], courseBuffer[100];
            GetWindowTextW(hNameEdit, nameBuffer, 100);
            GetWindowTextW(hEmailEdit, emailBuffer, 100);
            GetWindowTextW(hDobEdit, dobBuffer, 100);
            GetWindowTextW(hCourseEdit, courseBuffer, 100);
            name = nameBuffer;
            email = emailBuffer;
            dob = dobBuffer;
            course = courseBuffer;

            // Save registration data to file
            wofstream file("registration_data.txt", ios::app);
            if (file.is_open()) {
                file<<"--------------------------------------"<<L"\n";
                file << L"Name: " << name << L"\n";
                file << L"Email: " << email << L"\n";
                file << L"Date of Birth: " << dob << L"\n";
                file << L"Course: " << course << L"\n\n";
                file.close();
            }

            // Clear form fields
            SetWindowTextW(hNameEdit, L"");
            SetWindowTextW(hEmailEdit, L"");
            SetWindowTextW(hDobEdit, L"");
            SetWindowTextW(hCourseEdit, L"");
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}