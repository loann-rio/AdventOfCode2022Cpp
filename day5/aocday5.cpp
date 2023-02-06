#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

void get_inputs(vector<string>& inputs, string file) {
    ifstream IN(file);
    string text;
    while (getline(IN, text)) {
        inputs.push_back(text);
    }
    IN.close();
}

void processStack(string file, vector<vector<char>> & stack) {
    ifstream In(file);
    string line;
    while (getline(In, line)) { // for all lines in reversed inputs
        for (int j = 0; j < 36; j+=4 ) { // for every block (that are space with four elements in btw)
            char block = line[j]; // get block name
            if (block != '0') { // if the block is not empty
                int index = j/4;
                stack[index].push_back(block);
            } 
        }
    }   
    for (vector<char> & singlestack : stack) {
        reverse(singlestack.begin(), singlestack.end());
    }
}

void printstack(vector<vector<char>> & stacks) {
    for (vector<char> stack : stacks) {
        for (char box : stack) {
            cout << " " << box;
        }
        cout << '\n';
    }
}

int main() {
    vector<string> Movements;
    get_inputs(Movements, "inputsMovement.txt");

    vector<vector<char>> stack_input(9);
    processStack("inputsStack.txt", stack_input);

    printstack(stack_input);
}
