/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

#include <memory>
#include <iostream>

enum class Direction
{
    Left,
    Right,
    Up,
    Down
};

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int blockSize = 40;
    constexpr int screenWidth = 10 * blockSize;
    constexpr int screenHeight = 10 * blockSize;

    const float updateInterval = 0.75;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    auto time = GetTime();
    Vector2 snakePosition = { 200, 200 };
    Vector2 deltaPosition = { blockSize, 0 };
    Direction snakeDirection = Direction::Right;

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //handle input
        if (snakeDirection != Direction::Left && IsKeyDown(KEY_RIGHT))
        {
            snakeDirection = Direction::Right;
        }
        if (snakeDirection != Direction::Right && IsKeyDown(KEY_LEFT))
        {
            snakeDirection = Direction::Left;
        }
        if (snakeDirection != Direction::Down && IsKeyDown(KEY_UP))
        {
            snakeDirection = Direction::Up;
        }
        if (snakeDirection != Direction::Up && IsKeyDown(KEY_DOWN))
        {
            snakeDirection = Direction::Down;
        }


        auto newTime = GetTime();
        if (newTime - time > updateInterval )
        {
            time = newTime;
            snakePosition.x += deltaPosition.x;
            snakePosition.y += deltaPosition.y;
        }
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawRectangleV( snakePosition, { blockSize, blockSize }, BLACK );
            EndDrawing();
        
    }
    CloseWindow();

    return 0;
}
