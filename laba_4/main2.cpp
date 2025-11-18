#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    ~Complex() {}

    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i";
    }

    // Оператори + та -
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Оператори *= та /=
    Complex& operator*=(double scalar) {
        real *= scalar;
        imag *= scalar;
        return *this;
    }

    Complex& operator/=(double scalar) {
        if (abs(scalar) < 1e-9) { 
            cerr << "Помилка: Ділення на нуль неможливе!" << endl;
            return *this; 
        }
        real /= scalar;
        imag /= scalar;
        return *this;
    }

    // Префіксний ++ (збільшує дійсну частину)
    Complex& operator++() {
        real += 1.0;
        return *this;
    }

    // Постфіксний ++ (збільшує уявну частину)
    Complex operator++(int) { 
        Complex temp = *this; 
        imag += 1.0;          
        return temp;          
    } 

    // Префіксний -- (зменшує дійсну частину)
    Complex& operator--() {
        real -= 1.0;
        return *this;
    }

    // Постфіксний -- (зменшує уявну частину)
    Complex operator--(int) { 
        Complex temp = *this; 
        imag -= 1.0;          
        return temp;          
    } 

    // Оператор !=
    bool operator!=(const Complex& other) const {
        const double epsilon = 1e-9;
        return (abs(real - other.real) > epsilon) || (abs(imag - other.imag) > epsilon);
    }
};

// --- Тестова функція main ---
int main() {
    Complex c1(3.5, 4.0);
    Complex c2(1.0, -2.0);
    Complex c3(3.5, 4.0);
    double scalar = 2.0;

    cout << "c1 = "; c1.display(); cout << endl;
    cout << "c2 = "; c2.display(); cout << endl;

    Complex sum = c1 + c2;
    cout << "c1 + c2 = "; sum.display(); cout << endl;

    c1 *= scalar;
    cout << "c1 (*= 2.0): "; c1.display(); cout << endl;

    Complex c_inc_pre = ++c2;
    cout << "++c2 (Префіксний): "; c_inc_pre.display(); 
    cout << " | c2 тепер: "; c2.display(); cout << endl;
    
    Complex c_inc_post = c2++;
    cout << "c2++ (Постфіксний): "; c_inc_post.display(); 
    cout << " | c2 тепер: "; c2.display(); cout << endl;

    cout << boolalpha << "c1 != c3: " << (c1 != c3) << endl; 
    
    return 0;
}