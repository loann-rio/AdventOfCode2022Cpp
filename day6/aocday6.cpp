#include <iostream>
#include <fstream>

using namespace std;

bool checksubstring(string s, int sizemarker) {
    for (int i=0; i+1 < s.size(); i++) {
        if (s.substr(i+1, sizemarker).find(s[i]) != string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream IN("inputs.txt");
    string text;
    getline(IN, text); // only one line in the inputs
    IN.close();

    int sizemarker = 14;

    for (int i=0; i+sizemarker<text.size(); i++) {
        if (!checksubstring(text.substr(i, sizemarker), sizemarker)) {
            cout << i+sizemarker;
            break;
        }
    }
}