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
    cout << '\n';
    for (vector<char> stack : stacks) {
        for (char box : stack) {
            cout << " " << box;
        }
        cout << '\n';
    }
}

void movestack(vector<vector<char>> & stacks, int indexFirstStack, int index2stack, int nbElement) {
    vector<char> & stack1 = stacks[indexFirstStack];
    vector<char> & stack2 = stacks[index2stack];
    for (int i=0; i<nbElement; i++) {
        stack2.push_back(stack1.back());
        stack1.pop_back();
    }   
}

void movestackpart2(vector<vector<char>> & stacks, int indexFirstStack, int index2stack, int nbElement) {
    vector<char> & stack1 = stacks[indexFirstStack];
    vector<char> & stack2 = stacks[index2stack];
    stack2.resize(stack2.size()+nbElement);
    for (int i=0; i<nbElement; i++) {
        stack2[stack2.size() - nbElement + i] = stack1[stack1.size() - nbElement + i];
    } 
    stack1.resize(stack1.size() - nbElement);
}



int main() {
    vector<string> Movements;
    get_inputs(Movements, "inputsMovement.txt");

    vector<vector<char>> stack_input(9);
    processStack("inputsStack.txt", stack_input);

    printstack(stack_input);
    for (string mov : Movements) {
        int nbElement = stoi(mov.substr(5, mov.find('f')));
        int indexFstack = stoi(mov.substr(mov.find('f')+5, mov.find('f')+7)) - 1;
        int indexSstack = stoi(mov.substr(mov.find('f')+10, mov.find('f')+13)) - 1;

        movestackpart2(stack_input, indexFstack, indexSstack, nbElement);
    }
    printstack(stack_input);
}
