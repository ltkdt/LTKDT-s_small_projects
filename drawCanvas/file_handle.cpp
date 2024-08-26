#include <iostream>
#include <fstream>
#include <string>
#include "file_handle.h"


std::string readFile(){
    std::string fileContent;
    std::string appendstring(" \n");

    // Read from the text file
    std::ifstream FileHandle("bitmap.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (FileHandle, fileContent)) {
    // Output the text from the file
        std::cout << fileContent << std::endl;
    }
    FileHandle.close();

    return fileContent;
}

void PrintFile(){
    std::cout << readFile() << "\n";
}

void WriteFile(int matrix_map[64][128]){
    std::ofstream FileHandle("object.txt");

    FileHandle << "static const unsigned char myBitmap [] { " << std::endl;
     for(int i = 0; i < 64; i++){
        FileHandle << "\t";
        for(int j = 0; j < 128; j++){
            if (matrix_map[i][j] == 0){
                FileHandle << "0x00 "; 
            }
            else{
                FileHandle << "0xff ";
            }
        }
        FileHandle << std::endl;
    }
    FileHandle << "}";

    FileHandle.close();
}
