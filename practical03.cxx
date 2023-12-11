
#include <iostream>
#include <string>
using namespace std;

class publication {
private:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title of publication: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price of publication: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Publication title: " << title << endl;
        cout << "Publication price: " << price << endl;
    }
};

class book : public publication {
private:
    int pagecount;

public:
    void getdata() {
        cout << "For Book version:\n";
        publication::getdata();
        cout << "Enter Book Page Count: ";
        cin >> pagecount;
    }

    void putdata() const {
        cout << "\n-----Book version------:\n";
        publication::putdata();
        cout << "Book page count: " << pagecount << endl;
    }
};

class tape : public publication {
private:
    float ptime;

public:
    void getdata() {
        cout << "For audiocassette version: \n";
        publication::getdata();
        cout << "Enter tape's playing time: ";
        cin >> ptime;
    }

    void putdata() const {
        cout << "\n-----Audiocassette version------:\n";
        publication::putdata();
        cout << "Tape's playing time: " << ptime << endl;
    }
};

int main() {
    book b;
    tape t;
    b.getdata();
    t.getdata();
    b.putdata();
    t.putdata();
    return 0;
}