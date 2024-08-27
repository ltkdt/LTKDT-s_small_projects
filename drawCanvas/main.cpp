#include "raylib.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_handle.h"

#define X_RESOLUTION 128
#define Y_RESOLUTION 64

/*
Basic of my progam:

There is a canvas for you to draw, including the option to use a pen or eraser. You can reset the canvas to a blank one or invert the color.

The matrix map will tell you the state of each pixel: 0 will be translated to 0x00 (black) and 1 will be translated to 0xff or white.

Press F12 or click the save button to generate code to bitmap.cpp. Copy the code of the bitmap into the arduino / esp32 program that you want to run with an OLED

*/

// There are only 2 draw tools for this basic program: pen or eraser
typedef enum DrawTool { PEN, ERASER } DrawTool;

// Position of the starting point and the ending point of the canvas
Vector2 BeginDrawCanvas = {40, 20};
Vector2 EndDrawCanvas = {1320, 660};

// Buttons. The 4 components are respectively: position_x, position_y, width, height.

Rectangle DrawToolButton {80, 675, 200, 30};
Rectangle ResetCanvasButton {300, 675, 200, 30};
Rectangle InvertColorButton {520, 675, 200, 30};
Rectangle SaveButton {740, 675, 400, 30};

int matrix_map[Y_RESOLUTION][X_RESOLUTION];  // Matrix : Arr[row][column]

/*

This function give you the corresponding postion from the canvas to the matrix map.

Quick explain: Let say you have multiple blocks with each one is 10 units wide. If your position is 12, then you are at the first block (1st)

So to get the postition of the matrix map, you round down the position to the nearest tenth, and then divide the number you have by 10.

The variable offset exists because our canvas doesn't start at (0,0), but (40, 20) according to BeginDrawCanvas. You need to subtract this offset before making calculation.

*/

int GetPositionOfMap(int pos, int offset){
    pos = pos - offset;
    return ( pos - (pos % 10) ) / 10;
}

/*

The below function take the position of the matrix map to tell the postion of the block on the canvas that will be drawn.

You reverse the step of the GetPositionOfMap to get the number that you rounded down to the nearest tenth.

*/

int PositionToCanvas(int pos, int offset){
    return offset + pos*10;
}

// By default, all of the blocks on the canvas are blank and represent black color on the bitmap.
void reset_matrix_map(){
    for(int i = 0; i < Y_RESOLUTION; i++){
        for(int j = 0; j < X_RESOLUTION; j++){
            matrix_map[i][j] = 0;
        }
    }
}

// Switching color 
void invert_matrix_map(){
    for(int i = 0; i < Y_RESOLUTION; i++){
        for(int j = 0; j < X_RESOLUTION; j++){
            if (matrix_map[i][j] == 0 ){
                matrix_map[i][j] = 1;
            }
            else{
                matrix_map[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    reset_matrix_map();
    // Each pixel of the result bitmap is represented by a block of 10x10 on the canvas
    const int screenWidth = 1360; // 1280 + 80. The draw canvas only takes up 1280 pixels in terms of width.
    const int screenHeight = 720; // 640 + 80. The draw canvas only takes up 640 pixels in terms height

    DrawTool CurrentDrawTool = PEN;

    InitWindow(screenWidth, screenHeight, "Simple program to draw bitmap by ltkdt");

    SetTargetFPS(60);              
    
    while (!WindowShouldClose())    
    {
        // Check if you are clicking or pressing down on the canvas. If you are, then it will take the postition of your mouse and translate to canvas position.

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
                    // Using draw tool, blocks that you click on are white. (The default is black)
                    matrix_map[position_map_y][position_map_x] = 1;
                    break;
                case ERASER:
                    // Using eraser tool, blocks that you click on are black, the same as the default color
                    matrix_map[position_map_y][position_map_x] = 0;
                    break;
                default:
                    break;
                }
            }

        // Button function
        if ( CheckCollisionPointRec(GetMousePosition(), ResetCanvasButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ){
            reset_matrix_map();
        }

        if ( CheckCollisionPointRec(GetMousePosition(), InvertColorButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ){
            invert_matrix_map();
        }

        if ( (CheckCollisionPointRec(GetMousePosition(), SaveButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_F12) ){
            WriteFile(matrix_map);
        }

        // The switch block below is for switching between drawing tools
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
            default: break;
        }

/*
----------------------------------------------------------------------------------------------------------------------------------------------------------------

                                Displaying on the screen starts here

----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
                for(int i = 0; i < Y_RESOLUTION; i++){
                for(int j = 0; j < X_RESOLUTION; j++){
                    if (matrix_map[i][j] == 1){
                        DrawRectangle(PositionToCanvas(j, BeginDrawCanvas.x), PositionToCanvas(i, BeginDrawCanvas.y), 10, 10, LIGHTGRAY);
                        }
                    }
                }

                // The outline of the canvas
                DrawLineV( BeginDrawCanvas, {EndDrawCanvas.x, BeginDrawCanvas.y}, BLACK );
                DrawLineV( BeginDrawCanvas, {BeginDrawCanvas.x, EndDrawCanvas.y}, BLACK );
                DrawLineV( {EndDrawCanvas.x, BeginDrawCanvas.y}, EndDrawCanvas, BLACK );
                DrawLineV( {BeginDrawCanvas.x, EndDrawCanvas.y}, EndDrawCanvas, BLACK);

                // Horizontal lines
                // This loop will draw 63 horizontal lines between the outer horizontal line of the canvas (64 rows require 65 lines including the border)
                for(int cur_y = BeginDrawCanvas.y; cur_y < 650; cur_y += 10){
                    DrawLine(BeginDrawCanvas.x, cur_y + 10, EndDrawCanvas.x, cur_y+10, BLACK); // x1, y1, x2, y2
                }
                
                // Vertical lines
                // This loop will draw 127 vertical lines between the two outer horizontal line of the canvas (128 colums require 129 lines including the border)
                for(int cur_x = BeginDrawCanvas.x; cur_x < 1310; cur_x += 10){
                    DrawLine(cur_x+10, BeginDrawCanvas.y, cur_x+10, EndDrawCanvas.y, BLACK); // x1, y1, x2, y2
                }

                //Displaying the buttons and draw text on them

                DrawRectangleRec(DrawToolButton, LIGHTGRAY);
                DrawRectangleRec(ResetCanvasButton, LIGHTGRAY);
                DrawRectangleRec(InvertColorButton, LIGHTGRAY);
                DrawRectangleRec(SaveButton, LIGHTGRAY);

                DrawText("Reset canvas", 315, 680, 25, BLACK);
                DrawText("Invert color", 540, 680, 25, BLACK);
                DrawText("Save to: object.txt (Or F12)", 775, 680, 25, BLACK);

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
            
        EndDrawing();
    }

    CloseWindow();      

    return 0;
}
