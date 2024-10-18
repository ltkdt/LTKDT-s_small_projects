#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

std::string readFile();

extern std::unordered_map<int, char> ToHexLetter;

int four_bit_to_hex(int a, int b, int c, int d);

void WriteFile(int matrix_map[64][128]);
