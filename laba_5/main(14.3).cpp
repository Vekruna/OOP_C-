#include <iostream>
#include <string>
#include "VIDEO.h"
using namespace std;

int main() {
    setlocale(0, "");
    
    int N;
    cout << "Скільки фільмів хочете внести? ";
    cin >> N;
    cin.ignore();

    VIDEO* VIDEO_COLLECTION = new VIDEO[N];

    cout << "\n--- Введення фільмів ---\n";
    for (int i = 0; i < N; i++) {
        cout << "\nФільм №" << i + 1 << endl;
        VIDEO_COLLECTION[i].input();
    }

    string targetRezhiser;
    cout << "\nВведіть ім'я режисера для пошуку: ";
    getline(cin, targetRezhiser);

    cout << "\n--- Фільми режисера " << targetRezhiser << " ---\n";
    bool found = false;

    for (int i = 0; i < N; i++) {
        if (VIDEO_COLLECTION[i].getRezhiser() == targetRezhiser) {
            VIDEO_COLLECTION[i].output();
            found = true;
        }
    }

    if (!found) {
        cout << "Нічого не знайдено.\n";
    }

    delete[] VIDEO_COLLECTION;
    return 0;
}
