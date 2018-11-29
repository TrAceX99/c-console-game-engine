#include "defines.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include "player.h"

using namespace std;

const SMALL_RECT screenPos = {0, 0, 119, 39};

wchar_t playerSprite[] = L"#";

int main()
{
    HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);

    HANDLE screenH = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    if (screenH == INVALID_HANDLE_VALUE) return 1;

    wchar_t screenBuffer[screenSize + 1] = {0};
    SetConsoleScreenBufferSize(screenH, {WINDOW_WIDTH, WINDOW_HEIGHT});
    SetConsoleWindowInfo(screenH, TRUE, &screenPos);

    if (!SetConsoleActiveScreenBuffer(screenH)) return 2;

    auto t1 = chrono::system_clock::now();
    auto t2 = chrono::system_clock::now();

    Player player(10, 10);
    player.sprite.setImage(playerSprite, 1, 1);

    DWORD bytesWritten;
    while(1) {
        if (GetAsyncKeyState(VK_ESCAPE)) break;

        t2 = chrono::system_clock::now();
        chrono::duration<float> t = t2 - t1;
        t1 = t2;
        float frameTime = t.count();

        player.update(frameTime);

        for (int i = 0; i < screenSize; i++) screenBuffer[i] = 0;
        player.draw(screenBuffer);

        WriteConsoleOutputCharacter(screenH, screenBuffer, screenSize, {0, 0}, &bytesWritten);
    }

    SetConsoleActiveScreenBuffer(stdoutH);

    return 0;
}