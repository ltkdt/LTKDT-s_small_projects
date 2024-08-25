#include "raylib.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_handle.h"


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
    // Testing functions
    PrintFile();
    init_matrix_map();
   
    const int screenWidth = 1360; // 1280 + 80
    const int screenHeight = 720; // 640 + 40 + 40

    ProgramScreen CurrentScreen = DRAW;
    InitWindow(screenWidth, screenHeight, "Draw your bitmap here");

    SetTargetFPS(60);              
    
    while (!WindowShouldClose())    
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
                    DrawLineV( {EndDrawCanvas.x, BeginDrawCanvas.y}, EndDrawCanvas, BLACK );
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

                    DrawText("Press F1 to switch screen", 500, 675, 30, BLACK);
    
                } break;
                case CODE:
                {

                    DrawText("Press F2 to switch screen", 500, 675, 30, BLACK);
                } break;
                default: break;
            }

        EndDrawing();

    }


    CloseWindow();      

    return 0;
}