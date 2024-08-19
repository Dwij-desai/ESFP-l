#include <WinCon.h>
#ifndef _O_U16TEXT
#define _O_U16TEXT 0x20000
#endif
#ifndef _O_U16TEXT
#define _O_U16TEXT 0x20000
#endif

#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include <iostream>
#include <WinCon.h>

#ifndef UNICODE
#define UNICODE
#endif

#pragma comment(lib, "User32.lib")

class ConsolePX {
public:
    wchar_t source;
    COLORREF foreground, background;

    ConsolePX(wchar_t _what, COLORREF foregroundColor, COLORREF backgroundColor) {
        source = _what;
        foreground = foregroundColor;
        background = backgroundColor;
    }

    void Draw() {
        HANDLE outH = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFOEX curr, newBuff;
        curr.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
        GetConsoleScreenBufferInfoEx(outH, &curr);
        curr.srWindow.Bottom++;
        newBuff = curr;
        newBuff.ColorTable[0] = background;
        newBuff.ColorTable[1] = foreground;
        SetConsoleScreenBufferInfoEx(outH, &newBuff);
        SetConsoleTextAttribute(outH, 1);
        _setmode(_fileno(stdout), _O_U16TEXT); // Sets console mode to 16-bit Unicode
        std::wcout << source << std::endl;
        _setmode(_fileno(stdout), _O_TEXT); // Restores to defaults
        SetConsoleTextAttribute(outH, 7);
        SetConsoleScreenBufferInfoEx(outH, &curr);
    }
};