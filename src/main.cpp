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
#include <vector>

enum class Direction
{
    Left,
    Right,
    Up,
    Down
};

Vector2 GetUpdatePositionVector( Direction direction, float size )
{
    if (direction == Direction::Left )
    {
        return { -size, 0 };
    }
    else if (direction == Direction::Right)
    {
        return { size, 0 };
    }
    else if (direction == Direction::Up)
    {
        return { 0, -size };
    }
    else if (direction == Direction::Down)
    {
        return { 0, size };
    }
}

int main(void)
{
    const int blockSize = 40;
    constexpr int screenWidth = 10 * blockSize;
    constexpr int screenHeight = 10 * blockSize;
    const float updateInterval = 0.5;
    std::vector<Vector2> snakePartsPositions = { {200, 200}, { 160, 200 }, { 120, 200 }, { 80, 200 } };

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    auto time = GetTime();
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

            for ( auto i = snakePartsPositions.size() ; i > 0 ; --i )
            {
                snakePartsPositions[i].x = snakePartsPositions[i -1].x;
                snakePartsPositions[i].y = snakePartsPositions[i -1].y;
            }
            auto deltaPosition = GetUpdatePositionVector( snakeDirection, blockSize );
            snakePartsPositions[0].x += deltaPosition.x;
            snakePartsPositions[0].y += deltaPosition.y;
        }
            BeginDrawing();
                ClearBackground(RAYWHITE);
                for (auto snakePart : snakePartsPositions)
                {
                    DrawRectangleV( snakePart, { blockSize, blockSize }, BLACK );
                }
            EndDrawing();
    }
    CloseWindow();

    return 0;
}
