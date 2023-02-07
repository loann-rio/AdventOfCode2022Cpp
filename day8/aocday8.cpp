#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

void get_inputs(string file, int inputs[99][99]) {
    ifstream IN(file);
    string text;

    int i = 0;
    while (getline(IN, text)) {
        for (int j=0; j<99;j++) {
            inputs[i][j] = text[j] - '0';
        }
        i++;
    }
    IN.close();
}

int main() {
    int inputs[99][99];
    get_inputs("inputs.txt", inputs);
    
    for (int i=0;i<99;i++) {
        for (int j=0; j<99; j++) {
            cout << inputs[i][j];
        }
        cout << '\n';
    }
}