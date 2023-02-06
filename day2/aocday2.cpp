#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

void get_inputs(list<string>& inputs) {
    ifstream IN("inputs.txt");
    string text;
    while (getline(IN, text)) {
        inputs.push_back(text);
    }
    IN.close();
}

int main() {
    int score = 0;
    int scorePart2 = 0;
    list<string> inputs{};
    get_inputs(inputs);
    for (string i : inputs) {
        int fst = i[0] - 'A';
        int snd = i[2] - 'X';
        score += snd + 1 + 3 * ((snd - fst + 3+ 1)%3);
        scorePart2 += snd*3 + 1 + (fst - 1 + snd + 3) % 3;
    }
    cout << score << " " << scorePart2;
}