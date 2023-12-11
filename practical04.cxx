

#include <fstreaam>
#include <iostream>
using namespace std;

void writetofile() {
    ofstream a_file("abcd.txt", ios::app);
    int n, id, sal;
    char name[10];

    cout << "Enter No of Records you want to enter:\n";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter Id, Name, and Salary of Emp:\n";
        cin >> id >> name >> sal;
        a_file << id << '\t' << name << '\t' << sal << '\n';
    }

    cout << endl;
}

void readfile() {
    ifstream b_file("abcd.txt", ios::in);
    int id, sal;
    char name[10];

    cout << "ID\tName\tSalary\n";

    while (b_file >> id >> name >> sal) {
        cout << id << '\t' << name << '\t' << sal << '\n';
    }

    cout << endl;
}

int main() {
    int ch;

    do {
        cout << "Main Menu for file\n";
        cout << "1. Write to file\n";
        cout << "2. Read from file\n";
        cout << "3. Exit\n";
        cout << "Enter your choice\n";
        cin >> ch;

        switch (ch) {
            case 1:
                writetofile();
                break;
            case 2:
                readfile();
                break;
            case 3:
                break;
            default:
                cout << "Wrong choice\n\n";
        }
    } while (ch != 3);

    return 0;
}