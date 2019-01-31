#include "player.h"
#include <windows.h>

void Player::Update(double& deltaTime) {
    Object::Update(deltaTime);
    // Get WASD input
    int deltaX = GetAsyncKeyState('D') ? 1 : 0 +
    GetAsyncKeyState('A') ? -1 : 0;
    int deltaY = GetAsyncKeyState('S') ? 1 : 0 +
    GetAsyncKeyState('W') ? -1 : 0;

    // Update precise player position
    position.x += deltaX * SPEED * deltaTime;
    position.y += deltaY * SPEED * deltaTime;
    return;
}