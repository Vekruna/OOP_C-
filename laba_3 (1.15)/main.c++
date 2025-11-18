#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
private:
    string surname;
    string name;
    string fathername;
    string address;
    string gender;
    string education;
    int birthYear;

public:
    // Конструктор
    Person(string s, string n, string f, string a, string g, string e, int by)
        : surname(s), name(n), fathername(f), address(a),
          gender(g), education(e), birthYear(by) {}

    int getAge(int currentYear = 2025) const {
        return currentYear - birthYear;
    }

    string getEducation() const { return education; }
    string getGender() const { return gender; }

    void print() const {
        cout << surname << " " << name << " " << fathername
             << ", Адреса: " << address
             << ", Стать: " << gender
             << ", Освіта: " << education
             << ", Рік народження: " << birthYear
             << ", Вік: " << getAge()
             << endl;
    }
};

int main() {
    setlocale(0, "");

    // Масив об'єктів Person
    vector<Person> people = {
        Person("Іваненко", "Олег", "Петрович", "Київ, вул. Лісова 10", "Чоловіча", "Вища", 1999),
        Person("Петренко", "Марина", "Ігорівна", "Львів, вул. Шевченка 22", "Жіноча", "Середня", 2002),
        Person("Сидоренко", "Андрій", "Олегович", "Одеса, вул. Приморська 5", "Чоловіча", "Вища", 1987),
        Person("Коваленко", "Оксана", "Юріївна", "Харків, вул. Науки 14", "Жіноча", "Вища", 1995),
        Person("Мельник", "Дмитро", "Сергійович", "Полтава, вул. Київська 8", "Чоловіча", "Середня", 2004)
    };

    int ageLimit;
    cout << "Введіть вік для пошуку: ";
    cin >> ageLimit;

    cout << "\nа) Люди, старші за " << ageLimit << " років:\n";
    for (const auto& p : people) {
        if (p.getAge() > ageLimit)
            p.print();
    }

    cout << "\nб) Люди з вищою освітою:\n";
    for (const auto& p : people) {
        if (p.getEducation() == "Вища")
            p.print();
    }

    cout << "\nв) Перелік громадян чоловічої статі:\n";
    for (const auto& p : people) {
        if (p.getGender() == "Чоловіча")
            p.print();
    }

    return 0;
}