#include "staticData.h"

#define IMAGE(name) const wchar_t *name[]
#define SPRITE(name) Sprite Graphics::name


// ----------- SPRITE IMAGE DATA -------------------------

IMAGE(spr1) = {L"*************test464646**----------*************"};
IMAGE(prop1) = {L"\0#####\0#+++++##+-o-+##+++++#\0#####\0"};
IMAGE(playerImg) = {L"\0\0\0Wo\0|M>| \\", L"W\0\0|o/|M\0/ \\", L"\0\0\0\0oW<M|/ |", L"\0\0W\\o|\0M|/ \\"};

// ----------- SPRITES ----------------------------

SPRITE(sprite1)(spr1, 12, 4);
SPRITE(playerSpr)(playerImg, 3, 4, {1, 2});
SPRITE(sprite2)(prop1, 7, 5, {3, 2});