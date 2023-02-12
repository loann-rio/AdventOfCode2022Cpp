#include <iostream>
#include <regex> 
#include <fstream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

void get_inputs(string& inputs, string file) {
    ifstream IN(file);
    string text;
    while (getline(IN, text)) {
        inputs += '\n' + text;
    }
    IN.close();
}

struct monkey
{
    vector<int> items;
    int test;
    vector<int> result;
};

void process_inputs(string inputs) {
    vector<monkey> monkeys;
    // use of regex
    // first line:
    // Starting\sitems:\s([1-9]{2},\s)*

    // sec line: Operation:\snew\s=\sold\s(\+|\*)\s(.*)
    // Test:\sdivisible\sby\s([1-9]+)
    // If\s((\btrue\b)|(\bfalse\b)):\sthrow\sto\smonkey\s([0-9])


    /*Starting\sitems:\s(([0-9]{2},\s)*)\n\s\sOperation:\snew\s=\sold\s(\+|\*)\s(.*)\n\s\sTest:\sdivisible\sby\s([1-9]+)\n\s\s\s\sIf\strue:\sthrow\sto\smonkey\s([0-9])\n\s\s\s\sIf\sfalse:\sthrow\sto\smonkey\s([0-9])*/

    regex rgx ("Starting\\sitems:\\s(([0-9]{2},\\s)*)\n\\s\\sOperation:\\snew\\s=\\sold\\s");
    smatch matches;

    if(regex_search(inputs, matches, rgx)) {
        cout << "Match found\n";

        for (size_t i = 0; i < matches.size(); ++i) {
            cout << i << ": '" << matches[i].str() << "'\n";
        }
    } else {
        cout << "Match not found\n";
    }
}


int main() {
    string inputs;
    get_inputs(inputs, "inputs.txt");
    process_inputs(inputs);
    
}