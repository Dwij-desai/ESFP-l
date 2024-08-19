#include <windows.h>
#include <tchar.h>
#include <string>

// Window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND nameEdit, usernameEdit;
    static TCHAR name[100], username[100];

    switch (msg) {
    case WM_CREATE:
        CreateWindow(TEXT("static"), TEXT("Name:"), WS_VISIBLE | WS_CHILD, 10, 10, 100, 20, hwnd, NULL, NULL, NULL);
        nameEdit = CreateWindow(TEXT("edit"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 10, 200, 20, hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("static"), TEXT("Username:"), WS_VISIBLE | WS_CHILD, 10, 40, 100, 20, hwnd, NULL, NULL, NULL);
        usernameEdit = CreateWindow(TEXT("edit"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 40, 200, 20, hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("button"), TEXT("OK"), WS_VISIBLE | WS_CHILD, 120, 70, 80, 25, hwnd, (HMENU)1, NULL, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            GetWindowText(nameEdit, name, 100);
            GetWindowText(usernameEdit, username, 100);
            std::string message = "Name: " + std::string(name) + "\nUsername: " + std::string(username);
            MessageBox(hwnd, message.c_str(), TEXT("Result"), MB_OK);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = TEXT("MyWindow");

    RegisterClass(&wc);

    CreateWindow(wc.lpszClassName, TEXT("Name and Username"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 350, 150, NULL, NULL, hInstance, NULL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}