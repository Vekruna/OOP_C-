#include <iostream>
#include "VIDEO.h"
using namespace std;

VIDEO::VIDEO() {
    Name = "";
    Year = 0;
    Genre = "";
    Rezhiser = "";
}

void VIDEO::input() {
    cout << "Назва фільму: ";
    getline(cin, Name);

    cout << "Рік випуску: ";
    cin >> Year;
    cin.ignore();

    cout << "Жанр: ";
    getline(cin, Genre);

    cout << "Режисер: ";
    getline(cin, Rezhiser);
}

void VIDEO::output() const {
    cout << "Назва: " << Name << endl;
    cout << "Рік: " << Year << endl;
    cout << "Жанр: " << Genre << endl;
    cout << "Режисер: " << Rezhiser << endl;
    cout << "------------------------" << endl;
}

string VIDEO::getRezhiser() const {
    return Rezhiser;
}
