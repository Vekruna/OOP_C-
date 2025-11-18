#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class AverageCalculator {
public:
    void run() {
        vector<int> arr(10);
        cout << "Введіть 10 цілих чисел: ";
        for (int i = 0; i < 10; i++) cin >> arr[i];

        int sum = 0, count = 0;

        for (int x : arr) {
            if (x != 0) {
                sum += x;
                count++;
            }
        }

        cout << "Сума ненульових елементів: " << sum << endl;
        cout << "Кількість ненульових елементів: " << count << endl;

        if (count > 0)
            cout << "Середнє арифметичне: " << (double)sum / count << endl;
        else
            cout << "Немає ненульових елементів!" << endl;
    }
};

class MagicSquareChecker {
public:
    void run() {
        int n;
        cout << "Введіть розмір квадратної матриці n: ";
        cin >> n;

        vector<vector<int>> a(n, vector<int>(n));

        cout << "Введіть матрицю:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        int magicSum = 0;
        for (int j = 0; j < n; j++)
            magicSum += a[0][j];

        for (int i = 0; i < n; i++) {
            int rowSum = 0;
            for (int j = 0; j < n; j++)
                rowSum += a[i][j];
            if (rowSum != magicSum) {
                cout << "Матриця НЕ є магічним квадратом.\n";
                return;
            }
        }

        for (int j = 0; j < n; j++) {
            int colSum = 0;
            for (int i = 0; i < n; i++)
                colSum += a[i][j];
            if (colSum != magicSum) {
                cout << "Матриця НЕ є магічним квадратом.\n";
                return;
            }
        }

        int d1 = 0, d2 = 0;
        for (int i = 0; i < n; i++) {
            d1 += a[i][i];
            d2 += a[i][n - i - 1];
        }

        if (d1 != magicSum || d2 != magicSum) {
            cout << "Матриця НЕ є магічним квадратом.\n";
            return;
        }

        cout << "Матриця Є магічним квадратом!\n";
    }
};

class GuessNumberGame {
    string secret;

    string generateNumber() {
        string s;
        s += char('1' + rand() % 9);
        for (int i = 1; i < 3; i++)
            s += char('0' + rand() % 10);
        return s;
    }

public:
    GuessNumberGame() {
        srand(time(NULL));
        secret = generateNumber();
    }

    pair<int, int> check(const string& guess) {
        int matched = 0, correctPos = 0;

        for (int i = 0; i < 3; i++) {
            if (guess[i] == secret[i])
                correctPos++;
            if (secret.find(guess[i]) != string::npos)
                matched++;
        }

        return {matched, correctPos};
    }

    void run() {
        cout << "Комп'ютер загадав трьохзначне число. Вгадуйте!" << endl;

        while (true) {
            cout << "Ваш варіант -> ";
            string guess;
            cin >> guess;

            if (guess == secret) {
                cout << "Вгадано: 3. На своїх позиціях: 3" << endl;
                cout << "!!! ВИ ВГАДАЛИ !!!" << endl;
                break;
            }

            auto res = check(guess);
            cout << "Вгадано: " << res.first
                 << ". На своїх позиціях: " << res.second << endl;
        }
    }
};


class Morze {
    map<char, string> morze;

public:
    Morze() {
        morze = {
            {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
            {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
            {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
            {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
            {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
            {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
            {'Y', "-.--"}, {'Z', "--.."},
            {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
            {'3', "...--"}, {'4', "....-"}, {'5', "....."},
            {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
            {'9', "----."}
        };
    }

    void run() {
        string text;
        cout << "Введіть текст (латиниця + цифри): ";
        cin.ignore();
        getline(cin, text);

        for (char& c : text) {
            c = toupper(c);
            if (morse.count(c))
                cout << morse[c] << " ";
            else
                cout << "/ ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(0, "");

    while (true) {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1 — Середнє ненульових елементів\n";
        cout << "2 — Магічний квадрат\n";
        cout << "3 — Гра «Вгадай число»\n";
        cout << "4 — Морзе\n";
        cout << "0 — Вихід\n";
        cout << "Ваш вибір: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                AverageCalculator p;
                p.run();
                break;
            }
            case 2: {
                MagicSquareChecker p;
                p.run();
                break;
            }
            case 3: {
                GuessNumberGame g;
                g.run();
                break;
            }
            case 4: {
                Telegraph t;
                t.run();
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Ще раз\n";
        }
    }
}
