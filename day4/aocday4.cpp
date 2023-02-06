#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void get_inputs(vector<string>& inputs) {
    ifstream IN("inputs.txt");
    string text;
    while (getline(IN, text)) {
        inputs.push_back(text);
    }
    IN.close();
}

int main() {
    vector<string> lines;
    get_inputs(lines);
    int r = 0;
    int r2 = 0;
    for (string line : lines) {        
        string fRange = line.substr(0, line.find(','));
        string sRange = line.substr(line.find(',')+1, line.length());
        int range1[2] = {stoi(fRange.substr(0, fRange.find('-'))), stoi(fRange.substr(fRange.find('-')+1, fRange.length()))};
        int range2[2] = {stoi(sRange.substr(0, sRange.find('-'))), stoi(sRange.substr(sRange.find('-')+1, sRange.length()))};
        
        // part 1 
        if (((range1[0]>=range2[0])&&(range1[1]<=range2[1]))||((range1[0]<=range2[0])&&(range1[1]>=range2[1]))) {
            r++;
        }
        
        // part 2
        if (!((range1[0]>range2[1]) || (range1[1]<range2[0]))) {
            r2++;
        }
    }
    cout << r << " " << r2;
}