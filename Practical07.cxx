#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> state = {
        {"Maharashtra", 900225578},
        {"Goa", 899278},
        {"Jammu", 556055},
        {"Odisa", 788920},
        {"Haryana", 697903},
        {"Karnataka", 7028378},
        {"Punjab", 2303044}
    };

    string search;
    cout << "Enter the state to be searched:" << endl;
    cin >> search;

    auto it = state.find(search);
    if (it != state.end())
        cout << "The population of " << it->first << "=" << it->second << endl;
    else
        cout << "State Not Found." << endl;

    return 0;
}