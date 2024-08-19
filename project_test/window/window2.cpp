#include <windows.h>
#include <string>

// Dialog procedure for the custom input dialog
BOOL CALLBACK InputDialogProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the focus to the edit control
        SetFocus(GetDlgItem(hwndDlg, IDC_INPUT));
        return FALSE; // Return FALSE to set the focus manually
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            {
                char buffer[256];
                GetDlgItemText(hwndDlg, IDC_INPUT, buffer, sizeof(buffer));
                EndDialog(hwndDlg, IDOK); // End the dialog and return IDOK
            }
            return TRUE;
        case IDCANCEL:
            EndDialog(hwndDlg, IDCANCEL); // End the dialog and return IDCANCEL
            return TRUE;
        }
        break;
    }
    return FALSE;
}

std::string InputBox(HWND hwnd, const std::string& prompt, const std::string& title)
{
    // Create the custom input dialog
    int result = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_INPUT_DIALOG), hwnd, InputDialogProc);
    if (result == IDOK)
    {
        // Get the text from the edit control
        char buffer[256];
        GetDlgItemText(hwnd, IDC_INPUT, buffer, sizeof(buffer));
        return std::string(buffer);
    }
    else
    {
        return ""; // Return an empty string if the user cancels the dialog
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    std::string inputUsername = InputBox(NULL, "Enter your username:", "Login");
    std::string inputPassword = InputBox(NULL, "Enter your password:", "Login");

    const char* username = "your_username";
    const char* password = "your_password";

    // Check if username and password match
    if (inputUsername == username && inputPassword == password) {
        MessageBox(NULL, "Login successful!", "Login", MB_OK);
    } else {
        MessageBox(NULL, "Invalid username or password.", "Login", MB_OK);
    }

    return 0;
}
