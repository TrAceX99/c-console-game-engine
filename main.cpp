#include "defines.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <string>
#include "objectClasses.h"
#include "staticData.h"

using namespace std;

const SMALL_RECT screenPos = {0, 0, 119, 39};

//Sprite sprite1(tes, 5, 3, {2, 1});
/*Sprite sprite2(L" ##### #+++++##+-o-+##+++++# ##### ", 7, 5);
Sprite playerspr(L"\0Wo\0\0\0\0|M>\0\0\0| \\\0\0PLAYER", 6, 4, {3, 2});
Sprite text(L"*********************************----- This is an UI element -----*********************************", 33, 3);
Sprite fpsSprite(L"", 10, 1);*/

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

    Player player(fpoint_t(5, 5), Graphics::playerSpr);
    Object prop(fpoint_t(11.7, 32.4), Graphics::sprite2, 10);
    UIObject ui(fpoint_t(10, 32), Graphics::sprite1, 666);

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

        Object::DrawAll();

        WriteConsoleOutputCharacter(screenH, screenBuffer, screenSize, {0, 0}, &bytesWritten);
    }

    SetConsoleActiveScreenBuffer(stdoutH);

    return 0;
}