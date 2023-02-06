#include <iostream>
#include <fstream>

using namespace std;

void printarray(int (&array)[3]) {
    for (int e : array) {
        cout << e << endl;
    }
}

int main() {
    int maximumValues[3] = {0, 0, 0};
    ifstream inputs("inputsday1.txt");
    string text;
    int elf = 0;

    while (getline(inputs, text)) {
        if (text.empty()) {
            for (int i=0; i<3; i++) {
                if (maximumValues[i] < elf) {
                    if (i != 0) {
                        maximumValues[i-1] = maximumValues[i];
                    }
                    if ((i==2) || (maximumValues[i+1] > elf)) {
                        maximumValues[i] = elf;
                        break;
                    }
                }
            }
            elf = 0;

        } else {
            elf += stoi(text);
        }

    }
    printarray(maximumValues);
}