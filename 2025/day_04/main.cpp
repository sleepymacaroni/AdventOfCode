#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool accessible(int row, int column, const vector<vector<int>>& grid) {
    int numEmpty = 0;
    //check if each adjacent space is empty
    if (row-1 < 0 || grid[row-1][column] == 0) {
        numEmpty++;
    }
    if (column-1 < 0 || grid[row][column-1] == 0) {
        numEmpty++;
    }
    if (row+1 >= grid.size() || grid[row+1][column] == 0) {
        numEmpty++;
    }
    if (column+1 >= grid[row].size() || grid[row][column+1] == 0) {
        numEmpty++;
    }
    if ((row-1 < 0 || column-1 < 0) || grid[row-1][column-1] == 0) {
        numEmpty++;
    }
    if ((row+1 >= grid.size() || column+1 >= grid[row].size()) || grid[row+1][column+1] == 0) {
        numEmpty++;
    }
    if ((row-1 < 0 || column+1 >= grid[row].size()) || grid[row-1][column+1] == 0) {
        numEmpty++;
    }
    if ((row+1 >= grid.size() || column-1 < 0) || grid[row+1][column-1] == 0) {
        numEmpty++;
    }
    if (numEmpty > 4) {
        return true;
    }
    return false;
}

int main() {
    ifstream inputStream("input.txt");
    string fullRow;

    int count = 0;

    vector<vector<int>> paperGrid;
    int row = 0;
    int column;
    while (getline(inputStream, fullRow)) {
        vector<int> tempRow;
        for (column = 0; column < fullRow.length(); column++) {
            if (fullRow[column] == '@') {
                tempRow.push_back(1);
            }
            else {
                tempRow.push_back(0);
            }
        }
        paperGrid.push_back(tempRow);
        row++;
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            if (paperGrid[r][c] == 1 && accessible(r, c, paperGrid)) {
                count++;
            }
        }
    }
    cout << count << endl;
}