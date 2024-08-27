#include <iostream>
#include <fstream>
#include <string>
#include "file_handle.h"

/*
The program doesn't use the readFile() function below, however I choose to include it as it can be useful if you twerk the program yourself.
It can be used for the purpose of reading a bitmap and display it on a canvas
*/
std::string readFile(){
    std::string fileContent;
    std::string appendstring(" \n");

    // Read from the text file
    std::ifstream FileHandle("object.cpp");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (FileHandle, fileContent)) {
    // Output the text from the file
        std::cout << fileContent << std::endl;
    }
    FileHandle.close();

    return fileContent;
}

/*
Write the content of bitmap as cpp file.
The name of the output file is bitmap.cpp
*/
void WriteFile(int matrix_map[64][128]){
    std::ofstream FileHandle("bitmap.cpp");

    FileHandle << "static const unsigned char myBitmap [] { " << std::endl;
     for(int i = 0; i < 64; i++){
        FileHandle << "\t";
        for(int j = 0; j < 128; j++){
            if (matrix_map[i][j] == 0){
                FileHandle << "0x00, "; 
            }
            else{
                FileHandle << "0xff, ";
            }
        }
        FileHandle << std::endl;
    }
    FileHandle << "};";

    FileHandle.close();
}
