LRESULT CALLBACK AttendanceWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) 
{
    static HWND hNameEdit, hRollNoEdit, hBatchNoEdit, hAttendanceEdit, hAddButton, hClearButton;
    static HWND hListView;
    static vector<wstring> studentNames, studentRollNos, studentBatchNos, studentAttendance;
    static vector<wstring> studentData; // Modify the vector to store concatenated strings

    

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

        // Create a listview to display student information
        HWND hListView = CreateWindowW(WC_LISTVIEWW, NULL, WS_VISIBLE | WS_CHILD | LVS_REPORT | LVS_SINGLESEL,50, 300, 600, 200, hWnd, (HMENU)100, GetModuleHandleW(NULL), NULL);


        // Add columns to the listview
        LV_COLUMNW col;
        col.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
        col.fmt = LVCFMT_LEFT;
        col.cx = 150;

        // Set column text for each column
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
            wstring name, rollNo, batchNo, attendance;
            WCHAR nameBuffer[100], rollNoBuffer[100], batchNoBuffer[100], attendanceBuffer[100];
            GetWindowTextW(hNameEdit, nameBuffer, 100);
            GetWindowTextW(hRollNoEdit, rollNoBuffer, 100);
            GetWindowTextW(hBatchNoEdit, batchNoBuffer, 100);
            GetWindowTextW(hAttendanceEdit, attendanceBuffer, 100);
            name = nameBuffer;
            rollNo = rollNoBuffer;
            batchNo = batchNoBuffer;
            attendance = attendanceBuffer;

            // Add the student information to the respective vectors
            studentNames.push_back(name);
            studentRollNos.push_back(rollNo);
            studentBatchNos.push_back(batchNo);
            studentAttendance.push_back(attendance);

            // Clear the edit fields
            SetWindowTextW(hNameEdit, L"");
            SetWindowTextW(hRollNoEdit, L"");
            SetWindowTextW(hBatchNoEdit, L"");
            SetWindowTextW(hAttendanceEdit, L"");

            // Concatenate the student information into a single string
            wstring studentInfo = L"Name: " + name + L", Roll No.: " + rollNo + L", Batch No.: " + batchNo + L", Attendance: " + attendance;

            // Add the concatenated string to the studentData vector
            studentData.push_back(studentInfo);


            // Update the listview with the new student information
            HWND hListView = GetDlgItem(hWnd, 100); // Assuming the list view ID is 100
            LVITEMW item;
            item.mask = LVIF_TEXT;
            item.iItem = studentNames.size() - 1; // Index of the new item

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
        } else if (LOWORD(wp) == 2) { // Clear button clicked
            // Clear the edit fields
            SetWindowTextW(hNameEdit, L"");
            SetWindowTextW(hRollNoEdit, L"");
            SetWindowTextW(hBatchNoEdit, L"");
            SetWindowTextW(hAttendanceEdit, L"");

            // Clear the vectors
            studentNames.clear();
            studentRollNos.clear();
            studentBatchNos.clear();
            studentAttendance.clear();

            // Clear the listview
            HWND hListView = GetDlgItem(hWnd, 100); // Assuming the list view ID is 100
            ListView_DeleteAllItems(hListView);
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
