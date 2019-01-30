#include "defines.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include "player.h"
#include "camera.h"

using namespace std;

const SMALL_RECT screenPos = {0, 0, 119, 39};

wchar_t playerSprite[] = L" ##### #+++++##+-o-+##+++++########";

wchar_t* activeBuffer = nullptr;
fpoint_t cameraPos = {0, 0};

int main()
{
    HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);

    HANDLE screenH = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    if (screenH == INVALID_HANDLE_VALUE) return 1;

    wchar_t screenBuffer[screenSize + 1] = {0};
    SetConsoleScreenBufferSize(screenH, {WINDOW_WIDTH, WINDOW_HEIGHT});
    SetConsoleWindowInfo(screenH, TRUE, &screenPos);

    if (!SetConsoleActiveScreenBuffer(screenH)) return 2;
    activeBuffer = screenBuffer;

    auto t1 = chrono::system_clock::now();
    auto t2 = chrono::system_clock::now();

    Player player(10, 10);
    Object prop1;
    player.sprite.SetImage(playerSprite, 7, 5);
    prop1.sprite.SetImage(playerSprite, 7, 5);
    prop1.position = {36.6, 14.2};

    DWORD bytesWritten;
    while(1) {
        if (GetAsyncKeyState(VK_ESCAPE)) break;

        t2 = chrono::system_clock::now();
        chrono::duration<double> t = t2 - t1;
        t1 = t2;
        double frameTime = t.count();

        Object::UpdateAll(frameTime);
        cameraPos.x -= frameTime * 1.5;
        cameraPos.y -= frameTime;

        for (int i = 0; i < screenSize; i++) screenBuffer[i] = 0;

        Object::DrawAll();

        WriteConsoleOutputCharacter(screenH, screenBuffer, screenSize, {0, 0}, &bytesWritten);
    }

    SetConsoleActiveScreenBuffer(stdoutH);

    return 0;
}