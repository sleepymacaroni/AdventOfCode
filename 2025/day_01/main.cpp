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
            currentNum -= rotation;
        }
        else {
            currentNum += rotation;
        }
        currentNum = currentNum % 100;
        if (currentNum == 0) {
            code++;
        }
    }
    cout << code;
    cout << "\n";
}