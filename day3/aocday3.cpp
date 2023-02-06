#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void get_inputs(vector<string>& inputs) {
    ifstream IN("inputs.txt");
    string text;
    while (getline(IN, text)) {
        inputs.push_back(text);
    }
    IN.close();
}

int main() {
    int r = 0;
    vector<string> lines;
    get_inputs(lines);

    // part 1
    for (string line : lines) {
        int l = line.length();
        string compartment1 = line.substr(0, l/2);
        string compartment2 = line.substr(l/2, l);
        for (char letter : compartment1) {
            if (compartment2.find(letter) != std::string::npos) {
                if (letter - 'a' > 0) {
                    r += 1+letter - 'a';
                } else {
                    r+= 27+letter - 'A';
                }
                break;
            }
        }
    }
    cout << r << '\n';

    // part 2
    r = 0;
    for (int i = 0; i< lines.size(); i+=3) {
        for (char letter : lines[i]) {
            if  ((lines[i+1].find(letter) != std::string::npos) &&  (lines[i+2].find(letter) != std::string::npos)) {
                if (letter - 'a' > 0) {
                    r += 1+letter - 'a';
                } else {
                    r+= 27+letter - 'A';
                }
                break;
            }


        }
    }
    cout << r;
}