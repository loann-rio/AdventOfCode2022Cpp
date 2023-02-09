#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
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

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

void appendToVect(vector<tuple<int, int>> & visited, tuple<int, int> pos) {
    // append the position to the vector if not already in
    for (tuple<int, int> pastpos : visited) {
        if (pastpos == pos) {
            return;
        }
    }
    visited.push_back(pos);
}


int getDir(char dir) {
    switch (dir)
    {
    case 'R':
        return 1;
    case 'L':
        return 3;
    case 'U':
        return 0;
    case 'D':
        return 2;
    }   
}

int main() {
    // get inputs from file
    list<string> inputs;
    get_inputs(inputs);

    // directions
    int xdir[4] = {0, 1, 0, -1};
    int ydir[4] = {1, 0, -1, 0};

    tuple<int, int> 

    // head direction
    int dir = 0;

    int posXHead = 0;
    int posYHead = 0;

    int posXtail = 0;
    int posYtail = 0;

    // vector of all visited position {set}
    vector<tuple<int, int>> visited;

    for (string row : inputs) {
        dir = getDir(row[0]); // get direction from input

        for (int k=0;k<stoi(row.substr(2)); k++) { // for all repetion of inputs action

            // update head pos
            posXHead += xdir[dir];
            posYHead += ydir[dir];

            double dist = sqrt((posXHead-posXtail)*(posXHead-posXtail)+ (posYHead-posYtail)*(posYHead-posYtail));

            if (dist == 2) {
                posXtail += (int) (posXHead-posXtail)/2;
                posYtail += (int) (posYHead-posYtail)/2;
                
            } else if (dist > 2) {
                posXtail += sgn(posXHead-posXtail);
                posYtail += sgn(posYHead-posYtail);
            }

            tuple<int, int> pos = {posXtail, posYtail};
            appendToVect(visited, pos);

        }
        
    }

    cout << visited.size();

}