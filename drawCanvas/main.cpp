#include "raylib.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_handle.h"


#define x_resolution 128
#define y_resolution 64

/*
Basic of my progam:

There is a canvas for you to draw, including the option to use a pen or eraser.

The matrix map will tell you the state of each pixel: 0 is the default white and 1 is for the default black

Press F2 to switch to a screen where you can save your file as cpp code. Copy the code of the bitmap into the arduino / esp32 program that you want to run with an OLED
(This feature is unfinished)

*/

typedef enum ProgramScreen { DRAW, CODE } ProgramScreen;

typedef enum DrawTool { PEN, ERASER } DrawTool;

Vector2 BeginDrawCanvas = {40, 20};
Vector2 EndDrawCanvas = {1320, 660};

int matrix_map[y_resolution][x_resolution];  // Matrix : Arr[row][column]

Rectangle DrawToolButton {80, 675, 200, 30};
Rectangle DrawCanvas {40, 20, 1280, 640};

int GetPositionOfMap(int pos, int offset){
    pos = pos - offset;
    return ( pos - (pos % 10) ) / 10;
}

int PositionToCanvas(int pos, int offset){
    return offset + pos*10;
}

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
    // PrintFile();
    init_matrix_map();
   
    const int screenWidth = 1360; // 1280 + 80
    const int screenHeight = 720; // 640 + 40 + 40

    ProgramScreen CurrentScreen = DRAW;
    DrawTool CurrentDrawTool = PEN;

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


            if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){BeginDrawCanvas.x, BeginDrawCanvas.y, 1280, 640}) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT) )){
                    Vector2 CurrentPosition = GetMousePosition();
                    int mouse_x = CurrentPosition.x;
                    int mouse_y = CurrentPosition.y;
                    int position_map_x = GetPositionOfMap(mouse_x, BeginDrawCanvas.x);
                    int position_map_y = GetPositionOfMap(mouse_y, BeginDrawCanvas.y);
                    
                    std::cout << position_map_x << " " << position_map_y << "\n";
                    switch (CurrentDrawTool)
                    {
                    case PEN:
                        matrix_map[position_map_y][position_map_x] = 1;
                        break;
                    case ERASER:
                        matrix_map[position_map_y][position_map_x] = 0;
                        break;
                    default:
                        break;
                    }
                }

            switch (CurrentDrawTool)
            {
                case PEN:
                if ( CheckCollisionPointRec(GetMousePosition(), DrawToolButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)  ) {
                    CurrentDrawTool = ERASER;
                }
                break;
                case ERASER:
                            
                if ( CheckCollisionPointRec(GetMousePosition(), DrawToolButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ) {
                    CurrentDrawTool = PEN;
                }
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
                    
                    DrawRectangleRec(DrawToolButton, LIGHTGRAY);
                    switch (CurrentDrawTool)
                    {
                        case PEN:
                            DrawText("Using: Pen", 100, 680, 25, BLACK);
                        break;
                            
                        case ERASER:
                            DrawText("Using: Eraser", 100 , 680, 25, BLACK);
                        break;

                        default:
                        break;
                    }
                
                for(int i = 0; i < y_resolution; i++){
                    for(int j = 0; j < x_resolution; j++){
                        if (matrix_map[i][j] == 1){
                            DrawRectangle(PositionToCanvas(j, BeginDrawCanvas.x), PositionToCanvas(i, BeginDrawCanvas.y), 10, 10, LIGHTGRAY);
                        }
                    }
                }

                } break;

                // Seperate screen
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