#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputStream("input.txt");

    string instruction;
    int currentNum = 50;
    int code = 0;

    while (getline(inputStream, instruction)) {
        string direction = instruction.substr(0, 1);
        int rotation = stoi(instruction.substr(1));
        if (direction == "L") {
            for (int i = 0; i < rotation; i++) {
                currentNum--;
                if (currentNum < 0) {
                    currentNum = 99;
                }
                if (currentNum == 0) {
                    code++;
                }
            }
        }
        else {
            for (int i = 0; i < rotation; i++) {
                currentNum++;
                if (currentNum > 99) {
                    currentNum = 0;
                }
                if (currentNum == 0) {
                    code++;
                }
            }
        }
    }
    cout << code;
    cout << "\n";
}