#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

long long maxJoltage(const string& bank) {
    vector<char> digits;
    digits.push_back(-1);
    for (int i = 0; i < bank.size(); i++) {
        while (!digits.empty() && (digits.size() + bank.size() - i - 1 >= 12) && digits.back() < bank[i]) {
            digits.pop_back();
        }
        if (digits.size() < 12) {
            digits.push_back(bank[i]);
        }
    }
    string cat = string(digits.begin(), digits.end());
    return stoll(cat);
}

int main() {
    ifstream inputStream("input.txt");
    string bank;
    long long total = 0;
    while (getline(inputStream, bank)) {
        total += maxJoltage(bank);
    }
    cout << total << endl;
}