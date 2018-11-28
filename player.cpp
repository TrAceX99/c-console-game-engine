#include "defines.h"
#include "player.h"
#include <windows.h>

using namespace std;

Player::Player(double X, double Y) {
    x = X;
    y = Y;
}

int Player::bufferLocation(int x, int y) {
    return x + WINDOW_WIDTH * y;
}

void Player::update(double deltaTime) {
    // Get WASD input
    int deltaX = GetAsyncKeyState('D') ? 1 : 0 +
    GetAsyncKeyState('A') ? -1 : 0;
    int deltaY = GetAsyncKeyState('S') ? 1 : 0 +
    GetAsyncKeyState('W') ? -1 : 0;

    // Update precise player position
    x += deltaX * SPEED * deltaTime;
    y += deltaY * SPEED * deltaTime;
    return;
}

void Player::draw(wchar_t * buffer) {
    // Draw only if we are on screen
    if (x < WINDOW_WIDTH && x > 0 && y < WINDOW_HEIGHT && y > 0) {
        buffer[bufferLocation(x + 0.5, y + 0.5)] = '#'; // Rounding to nearest int
    }
    return;
}