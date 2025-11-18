#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    void input() {
        cout << "Введіть дійсну частину: ";
        cin >> real;
        cout << "Введіть уявну частину: ";
        cin >> imag;
    }

    void output() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }

    Complex conjugate() const {
        return Complex(real, -imag);
    }
};

int main() {
    setlocale(0, "");

    Complex z;
    cout << "Введення комплексного числа:\n";
    z.input();

    cout << "\nВведене число: ";
    z.output();

    Complex conj = z.conjugate();
    cout << "\nКомплексно-спряжене число: ";
    conj.output();

    cout << endl;
    return 0;
}