#include<iostream>
using namespace std;

class Complex {
    int real;
    float imag;

public:
    Complex() : real(0), imag(0) {}

    Complex operator+(const Complex&);
    Complex operator*(const Complex&);

    friend istream& operator>>(istream&, Complex&);
    friend ostream& operator<<(ostream&, const Complex&);
};

Complex Complex::operator+(const Complex& obj) {
    Complex temp;
    temp.real = real + obj.real;
    temp.imag = imag + obj.imag;
    return temp;
}

Complex Complex::operator*(const Complex& obj) {
    Complex temp;
    temp.real = real * obj.real - imag * obj.imag;
    temp.imag = imag * obj.real + real * obj.imag;
    return temp;
}

istream& operator>>(istream& in, Complex& a) {
    cout << "\nEnter real part: ";
    in >> a.real;
    cout << "Enter imaginary part: ";
    in >> a.imag;
    return in;
}

ostream& operator<<(ostream& out, const Complex& a) {
    out << a.real << (a.imag >= 0 ? "+" : "") << a.imag << "i";
    return out;
}

int main() {
    Complex c1, c2, c3;
    int choice;

    do {
        cout << "\n1. Enter two complex numbers";
        cout << "\n2. Add two complex numbers";
        cout << "\n3. Multiply two complex numbers";
        cout << "\n4. Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter first complex number";
                cin >> c1;
                cout << "Enter second complex number";
                cin >> c2;
                break;

            case 2:
                c3 = c1 + c2;
                cout << "\nResult after addition: " << c3 << endl;
                break;

            case 3:
                c3 = c1 * c2;
                cout << "\nResult after multiplication: " << c3 << endl;
                break;

            case 4:
                cout << "\nQuitting program.\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}