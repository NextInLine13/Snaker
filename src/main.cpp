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

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    const int blockSize = 40;
    const int updateInterval = 1;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    auto time = GetTime();
    Vector2 snakePosition = { 200, 200 };
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        auto newTime = GetTime();
        if (newTime - time > updateInterval )
        {
            time = newTime;

            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawRectangleV( snakePosition, { blockSize, blockSize }, BLACK );
                snakePosition.x += blockSize;

            EndDrawing();
        }
    }
    CloseWindow();

    return 0;
}
