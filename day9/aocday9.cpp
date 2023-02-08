#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <bits/stdc++.h>

using namespace std;

void get_inputs(list<string>& inputs) {
    ifstream IN("inputs.txt");
    string text;
    while (getline(IN, text)) {
        inputs.push_back(text);
    }
    IN.close();
}

// void appendToVect(vector<tuple<int, int>> & visited, tuple<int, int> pos) {
//     if (find_if(visited.begin(), visited.end(), pos) == visited.end()) {
//         visited.push_back(pos);
//     }
// }

int main() {
    list<string> inputs;
    get_inputs(inputs);

    int xdir[4] = {0, 1, 0, -1};
    int ydir[4] = {1, 0, -1, 0};

    int8_t dir = 0;

    int posXHead = 0;
    int posYHead = 0;

    int posXtail = 0;
    int posYtail = 0;

    //vector<tuple<int, int>> visited;

    for (string row : inputs) {
        cout << row << '\n';

        if (row[0] == 'R') {
            dir = (dir + 1)%4;
        } else { 
            dir = (dir - 1)%4; 
        }

        cout << dir << "\n";

        for (int k=0;k<stoi(row.substr(2)); k++) {
            cout << xdir[dir] << " " << ydir[dir] << "\n";
            posXHead += xdir[dir];
            posYHead += ydir[dir];
            cout << posXHead << " " << posYHead << "\n";

        }
        
    }
    

}