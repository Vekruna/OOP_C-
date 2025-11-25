#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ================== ФУНКЦІЇ ==================

// Введення масиву з консолі
void inputArrayConsole(vector<int>& arr) {
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;
    arr.resize(n);
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Запис масиву в текстовий файл
void writeArrayToTextFile(const vector<int>& arr, const string& filename) {
    ofstream fout(filename);
    for (int val : arr) {
        fout << val << " ";
    }
    fout.close();
}

// Створення випадкового масиву
void createRandomArray(vector<int>& arr, int size, int minVal = -10, int maxVal = 10) {
    arr.resize(size);
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

// Запис масиву у бінарний файл
void writeArrayToBinaryFile(const vector<int>& arr, const string& filename) {
    ofstream fout(filename, ios::binary);
    for (int val : arr) {
        fout.write(reinterpret_cast<const char*>(&val), sizeof(val));
    }
    fout.close();
}

// Видалення від'ємних елементів
void removeNegativeElements(vector<int>& arr) {
    vector<int> temp;
    for (int val : arr) {
        if (val >= 0) temp.push_back(val);
    }
    arr = temp;
}

// Зчитування масиву з текстового файлу
void readArrayFromTextFile(vector<int>& arr, const string& filename) {
    ifstream fin(filename);
    int val;
    arr.clear();
    while (fin >> val) {
        arr.push_back(val);
    }
    fin.close();
}

// Вивід масиву на консоль
void displayArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Зчитування масиву з бінарного файлу
void readArrayFromBinaryFile(vector<int>& arr, const string& filename) {
    ifstream fin(filename, ios::binary);
    arr.clear();
    int val;
    while (fin.read(reinterpret_cast<char*>(&val), sizeof(val))) {
        arr.push_back(val);
    }
    fin.close();
}

// ================== MAIN ==================
int main() {
    vector<int> arr;
    int choice;
    string textFile = "array.txt";
    string binaryFile = "array.bin";

    do {
        cout << "\nМеню:\n";
        cout << "1. Ввести масив з консолі та записати в текстовий файл\n";
        cout << "2. Створити випадковий масив та записати в бінарний файл\n";
        cout << "3. Видалити від'ємні елементи\n";
        cout << "4. Прочитати масив з текстового файлу та вивести на консоль\n";
        cout << "5. Прочитати масив з бінарного файлу та вивести на консоль\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputArrayConsole(arr);
                writeArrayToTextFile(arr, textFile);
                cout << "Масив записано у " << textFile << endl;
                break;
            case 2: {
                int size;
                cout << "Введіть розмір випадкового масиву: ";
                cin >> size;
                createRandomArray(arr, size);
                writeArrayToBinaryFile(arr, binaryFile);
                cout << "Випадковий масив записано у " << binaryFile << endl;
                break;
            }
            case 3:
                removeNegativeElements(arr);
                cout << "Масив після видалення від'ємних елементів:\n";
                displayArray(arr);
                break;
            case 4:
                readArrayFromTextFile(arr, textFile);
                cout << "Масив з текстового файлу:\n";
                displayArray(arr);
                break;
            case 5:
                readArrayFromBinaryFile(arr, binaryFile);
                cout << "Масив з бінарного файлу:\n";
                displayArray(arr);
                break;
            case 0:
                cout << "Вихід...\n";
                break;
            default:
                cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}