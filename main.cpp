#define _UNICODE

#include <iostream>
#include <Windows.h>
#include <chrono>

#define WINDOW_WIDTH 120
#define WINDOW_HEIGHT 40

using namespace std;

const int screenSize = WINDOW_WIDTH * WINDOW_HEIGHT;
const SMALL_RECT screenPos = {0, 0, 119, 39};

inline int location(COORD);

int main()
{
    HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);

    HANDLE screenH = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    if (screenH == INVALID_HANDLE_VALUE) return 1;

    wchar_t screenBuffer[screenSize + 1] = {0};
    SetConsoleScreenBufferSize(screenH, {WINDOW_WIDTH, WINDOW_HEIGHT});
    SetConsoleWindowInfo(screenH, TRUE, &screenPos);

    if (!SetConsoleActiveScreenBuffer(screenH)) return 2;

    DWORD bytesWritten;
    while(1) {
        WriteConsoleOutputCharacter(screenH, screenBuffer, screenSize, {0, 0}, &bytesWritten);
        if (GetAsyncKeyState(VK_ESCAPE)) break;
    }

    SetConsoleActiveScreenBuffer(stdoutH);

    return 0;
}

inline int location(COORD point) {
    return point.X + WINDOW_WIDTH * point.Y;
}