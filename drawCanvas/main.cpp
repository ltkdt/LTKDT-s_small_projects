#include "raylib.h"
#include <iostream>

#define x_resolution 128
#define y_resolution 64

typedef enum ProgramScreen { DRAW, CODE } ProgramScreen;

Vector2 BeginDrawCanvas = {40, 20};
Vector2 EndDrawCanvas = {1320, 660};


int matrix_map[y_resolution][x_resolution];  // Matrix : Arr[row][column]

void init_matrix_map(){
    for(int i = 0; i < y_resolution; i++){
        for(int j = 0; j < x_resolution; j++){
            matrix_map[i][j] = 0;
        }
    }
}


int main(void)
{
    init_matrix_map();
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1360; // 1280 + 80
    const int screenHeight = 680; // 640 + 40

    ProgramScreen CurrentScreen = DRAW;
    InitWindow(screenWidth, screenHeight, "Draw your bitmap here");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        switch (CurrentScreen)
        {
        case DRAW:
            if (IsKeyPressed(KEY_F1))
                {
                    CurrentScreen = CODE;
                }
            break;
        
        case CODE:
            if (IsKeyPressed(KEY_F2)){
                CurrentScreen = DRAW;
            }
            break;
        default: break;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            switch(CurrentScreen)
            {
                case DRAW:
                {
                    DrawLineV( BeginDrawCanvas, {EndDrawCanvas.x, BeginDrawCanvas.y}, BLACK );
                    DrawLineV( BeginDrawCanvas, {BeginDrawCanvas.x, EndDrawCanvas.y}, BLACK );
                    DrawLineV(  {EndDrawCanvas.x, BeginDrawCanvas.y}, EndDrawCanvas, BLACK );
                    DrawLineV( {BeginDrawCanvas.x, EndDrawCanvas.y}, EndDrawCanvas, BLACK);

                    // Horizontal lines
                    // This loop will draw 127 horizontal lines between the two horizontal line of the canvas
                    for(int cur_y = BeginDrawCanvas.y; cur_y < 650; cur_y += 10){
                        DrawLine(BeginDrawCanvas.x, cur_y + 10, EndDrawCanvas.x, cur_y+10, BLACK); // x1, y1, x2, y2
                    }
                    
                    // Vertical lines
                    // This loop will draw 127 horizontal lines between the two horizontal line of the canvas
                    for(int cur_x = BeginDrawCanvas.x; cur_x < 1310; cur_x += 10){
                        DrawLine(cur_x+10, BeginDrawCanvas.y, cur_x+10, EndDrawCanvas.y, BLACK); // x1, y1, x2, y2
                    }
    
                } break;
                case CODE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);

                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}