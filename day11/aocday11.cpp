#include <iostream>
#include <regex> 
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

struct monkey
{
    vector<int> items;
    int test;
    vector<int> result;
};

vector<monkey> process_inputs(vector<string> inputs) {
    vector<monkey> monkeys;
    for (int i=0; i< inputs.size(); i+= 7) {
        string itemsRow = inputs[i+1];
        itemsRow = itemsRow.substr(18);
        for (int j=0; j<itemsRow.size(); j+=4) {

        }


    }
}


int main() {
    vector<string> inputs;
    get_inputs(inputs, "inputs.txt");
    
}