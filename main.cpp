#include "defines.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <string>
#include "player.h"
#include "uiobject.h"

const SMALL_RECT screenPos = {0, 0, 119, 39};

Sprite sprite1(L"/***\\| × |\\___/", 5, 3, {2, 1});
Sprite sprite2(L" ##### #+++++##+-o-+##+++++# ##### ", 7, 5);
Sprite playerspr(L"\0Wo\0\0\0\0|M>\0\0\0| \\\0\0PLAYER", 6, 4, {3, 2});
Sprite text(L"*********************************----- This is an UI element -----*********************************", 33, 3);
Sprite fpsSprite(L"", 10, 1);

using namespace std;

wchar_t *activeBuffer = nullptr;
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

    Player player(fpoint_t(5, 5), &playerspr, 1);
    Object prop1(fpoint_t(45.3, 27.7), &sprite1, 10);
    Object prop2(fpoint_t(95.5, 17.2), &sprite2);
    UIObject ui(fpoint_t(80, WINDOW_HEIGHT - 4), &text, 999);
    UIObject fps(fpoint_t(1, 1), &fpsSprite, 1000);

    DWORD bytesWritten;
    while(1) {
        if (GetAsyncKeyState(VK_ESCAPE)) break;

        t2 = chrono::system_clock::now();
        chrono::duration<double> t = t2 - t1;
        t1 = t2;
        double frameTime = t.count();

        Object::UpdateAll(frameTime);
        cameraPos.x -= (cameraPos.x + WINDOW_WIDTH / 2 - player.position.x) * frameTime;
        cameraPos.y -= (cameraPos.y + WINDOW_HEIGHT / 2 - player.position.y) * frameTime;
        
        for (int i = 0; i < screenSize; i++) screenBuffer[i] = 0;
        wstring string = L"FPS: " + to_wstring(1/frameTime);
        fpsSprite.image = string.c_str();

        Object::DrawAll();

        WriteConsoleOutputCharacter(screenH, screenBuffer, screenSize, {0, 0}, &bytesWritten);
    }

    SetConsoleActiveScreenBuffer(stdoutH);

    return 0;
}