#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    getline(input, line);
    stringstream stream(line);

    vector<pair<long long, long long> > ranges;
    string range;

    while (getline(stream, range, ',')) {
        size_t hyphenIndex = range.find('-');
        long long low = stoll(range.substr(0, hyphenIndex));
        long long high = stoll(range.substr(hyphenIndex + 1));
        ranges.push_back(make_pair(low, high));
    }

    long long sum = 0;

    for (size_t idx = 0; idx < ranges.size(); idx++) {
        long long low = ranges[idx].first;
        long long high = ranges[idx].second;

        int lowDigits = to_string(low).size();
        int highDigits = to_string(high).size();

        for (int digits = (lowDigits % 2 == 0 ? lowDigits : lowDigits + 1);
             digits <= highDigits; digits += 2) {

            int half = digits / 2;
            long long pow10 = 1;
            for (int i = 0; i < half; i++) pow10 *= 10;

            long long minHalf = max(pow10 / 10, (low + pow10 - 1) / pow10);
            long long maxHalf = min(pow10 - 1, high / pow10);

            for (long long A = minHalf; A <= maxHalf; A++) {
                long long N = A * pow10 + A;
                sum += N;
            }
        }
    }
    cout << sum << endl;
}