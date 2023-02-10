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

tuple<int, int> addTuple(tuple<int, int> a, tuple<int, int> b) {
    return {get<0>(a)+get<0>(b), get<1>(a)+get<1>(b)};    
}

tuple<int, int> subTuple(tuple<int, int> a, tuple<int, int> b) {
    return {get<0>(a)-get<0>(b), get<1>(a)-get<1>(b)};    
}

tuple<int, int> divTuple(tuple<int, int> a, float b) {
    return {get<0>(a)/b, get<1>(a)/b};    
}

double sqr(double a) {
    return a*a;
}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

void appendToVect(vector<tuple<int, int>> & visible, tuple<int, int> pos) {
    if (find(visible.begin(), visible.end(), pos) == visible.end()) {
        visible.push_back(pos);
    }
}

tuple<int, int> getDir(char dir) {
    switch (dir)
    {
    case 'R':
        return {1, 0};
    case 'L':
        return {-1, 0};
    case 'U':
        return {0, 1};
    case 'D':
        return {0, -1};
    }   
}

tuple<int, int> move(tuple<int, int> posHead, tuple<int, int> postail) {
    tuple<int, int> diff = subTuple(posHead, postail);

    double dist = sqrt(sqr(get<0>(diff)) + sqr(get<1>(diff)));

    if (dist == 2) {
        postail = addTuple(divTuple(diff, 2), postail);
        
    } else if (dist > 2) {
        get<0>(postail) += sgn(get<0>(diff));
        get<1>(postail) += sgn(get<1>(diff));
    }
    return postail;
}

int main() {
    // get inputs from file
    list<string> inputs;
    get_inputs(inputs);

    vector<tuple<int, int>> poss(10);

    // vector of all visited position {set}
    vector<tuple<int, int>> visited;

    for (string row : inputs) {
        tuple<int, int> dir = getDir(row[0]); // get direction from input

        for (int k=0;k<stoi(row.substr(2)); k++) { // for all repetion of inputs action

            // update head pos
            poss[0] = addTuple(poss[0], dir);

            // update tail
            for (int i=0; i< poss.size()-1; i++) {
                poss[i+1] = move(poss[i], poss[i+1]);
            }
            
            // save the pos of the last knot
            appendToVect(visited, poss.back());
        }
    }
    cout << visited.size();
}