#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int power(int a, int n) {
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= a;
    return result;
}

double root(double x, int n) {
    return pow(x, 1.0 / n); 
}

int hexToDec(const string &hex) {
    int result = 0;
    int base = 1;

    for (int i = hex.length() - 1; i >= 0; i--) {
        char c = toupper(hex[i]);

        int value;
        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'A' && c <= 'F')
            value = c - 'A' + 10;
        else {
            cout << "Помилка: недопустимий символ '" << c << "' у числі!\n";
            return -1;
        }

        result += value * base;
        base *= 16;
    }
    return result;
}

int main() {

    int a = 3, n = 4;
    cout << "3^4 = " << power(a, n) << endl;

    double x = 81;
    int k = 4;
    cout << "Корінь 4-го степеня з 81 = " << root(x, k) << endl;

    string hex1 = "1A3F";
    cout << "Шістнадцяткове 1A3F = " << hexToDec(hex1) << " (у десятковій)\n";

    string hex2 = "FF";
    cout << "Шістнадцяткове FF = " << hexToDec(hex2) << " (у десятковій)\n";

    return 0;
}
