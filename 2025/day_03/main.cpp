#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputStream("input.txt");
    string bank;
    int total = 0;
    while (getline(inputStream, bank)) {
        int digit1 = -1;
        int max = -1;
        for (int i = 0; i < bank.length(); i++) {
            for (int j = i+1; j < bank.length(); j++) {
                if ((bank[i]-'0') * 10 + (bank[j]-'0') > max) {
                    max = (bank[i]-'0') * 10 + (bank[j]-'0');
                }
            }
        }
        total += max;
    }
    cout << total << endl;
}