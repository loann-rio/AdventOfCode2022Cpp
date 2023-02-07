#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

string text;
ifstream IN("inputs.txt");

int searchDirectory(vector<int> & sizes);

int main() {
    vector<int> sizes; // sizes of directory and subdirectories
    int total_weight = searchDirectory(sizes);

    int r = 0;
    int rpart2 = 10000000;

    int neededSpace = 30000000 - 70000000 + total_weight;

    for (int e : sizes) {
        if (e<=100000) {
            r+= e;
        }
        if ((e>neededSpace)&&(e<rpart2)) {
            rpart2 = e;
        }
    }
    cout << r << '\n';
    cout << rpart2 << '\n';
}

int searchDirectory(vector<int> & sizes) {
    int weight = 0;
    while (getline(IN, text)) {
        if (text == "$ cd ..") {
            sizes.push_back(weight);
            return weight;
        } else if ((text == "$ ls")||(text.substr(0, 3) == "dir")) {
            // pass
        } else if (text.substr(0, 4) == "$ cd") {
            weight += searchDirectory(sizes);
        } else {
            weight += stoi(text.substr(0, text.find(" ")));
        }
    }
    sizes.push_back(weight);
    return weight;
}