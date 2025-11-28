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
        Person("Толін", "Андрій", "Фарфанюк", "Чернівці, вул. Лісова 10", "Чоловіча", "Вища", 2008),
        Person("Куку", "Вадим", "Ярославович", "Чернівці, вул. Перемоги", "Чоловіча", "Вища", 2008),
        Person("Іванський", "Володя", "Володимирович", "Чернівці, вул. Майдан", "Чоловіча", "Вища", 2008),
        Person("Куку", "Марина", "Василівна", "Чернівці, вул. Шевченка 22", "Жіноча", "Середня", 1973),
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
