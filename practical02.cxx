#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class StudentDatabase {
    int roll;
    char name[20];
    char Class[10];
    char Div[10];
    char dob[12];
    char bg[5];
    char contact[10];
    char phone[12];
    char license[12];

public:
    static int stdCount;

    StudentDatabase() : roll(0) {
        strcpy(name, "Sachin");
        strcpy(Class, "I");
        strcpy(Div, "A");
        strcpy(dob, "11/11/2010");
        strcpy(bg, "A");
        strcpy(contact, "city");
        strcpy(phone, "9876543211");
        strcpy(license, "A0101010");
        ++stdCount;
    }

    StudentDatabase(const StudentDatabase &obj) {
        strcpy(name, obj.name);
        strcpy(dob, obj.dob);
        strcpy(Class, obj.Class);
        strcpy(Div, obj.Div);
        strcpy(bg, obj.bg);
        strcpy(contact, obj.contact);
        strcpy(phone, obj.phone);
        strcpy(license, obj.license);
        ++stdCount;
    }

    void getData() {
        cout << "\nEnter: name, roll, Class, Div, Dob, bg, contact, phone, license\n";
        cin >> name >> roll >> Class >> Div >> dob >> bg >> contact >> phone >> license;
    }

    friend void display(const StudentDatabase &d);

    ~StudentDatabase() {
        cout << "\n\n" << name << "(Object) is destroyed!";
    }

    static void count() {
        cout << "\nNo. of objects created: " << stdCount;
    }
};

void display(const StudentDatabase &d) {
    cout << "\n" << setw(12) << d.name << setw(5) << d.roll << setw(7) << d.Class
              << setw(3) << d.Div << setw(15) << d.dob << setw(6) << d.bg << setw(12)
              << d.contact << setw(15) << d.phone << setw(12) << d.license;
}

int StudentDatabase::stdCount;

int main() {
    int n, i;
    StudentDatabase d1, *ptr[5];
    cout << "\nDefault values:";
    display(d1);
    d1.getData();
    display(d1);
    StudentDatabase d2(d1);
    cout << "\n\nUse of copy constructor :\n";
    display(d2);
    cout << "\nHow many objects do you want to create?: ";
    cin >> n;

    for (i = 0; i < n; ++i) {
        ptr[i] = new StudentDatabase();
        ptr[i]->getData();
    }

    cout << "\n" << setw(12) << "Name" << setw(5) << "Roll" << setw(10) << "Class"
              << setw(5) << "Div" << setw(15) << "dob" << setw(6) << "bg" << setw(12)
              << "contact" << setw(15) << "phone" << setw(12) << "license";

    for (i = 0; i < n; ++i)
        display(*ptr[i]);

    StudentDatabase::count();

    for (i = 0; i < n; ++i)
        delete ptr[i];

    cout << "\nObjects deleted!";
    return 0;
}