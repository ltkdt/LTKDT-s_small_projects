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

void WriteFile(bool InvertedColor){
    
}
