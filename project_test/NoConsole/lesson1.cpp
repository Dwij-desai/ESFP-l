//
// Lesson-1 :- Make a blank window
//

#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst , LPSTR args ,int ncmdshow) {

    MessageBox(NULL , "This the test for api" , "Header", MB_OK);        // just a basic massage box

    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW ;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst ;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc)) {
        cout<<"system fail";
        return -1;
    }else if(RegisterClassW(&wc)) {
        cout<<"system working...";
    }
    CreateWindowW(L"myWindowClass",L"My Window",WS_OVERLAPPEDWINDOW | WS_VISIBLE , 100,100,500,500,NULL,NULL,NULL,NULL);

    MSG msg = {0};

    while ( GetMessage(&msg,NULL,NULL,NULL) ) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp) {

    switch(msg) {

        case WM_DESTROY:
            PostQuitMessage(0);
        break;

        default:
            return DefWindowProcW(hWnd,msg,wp,lp);
    }
}