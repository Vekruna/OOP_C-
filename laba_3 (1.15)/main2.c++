#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BoolMatrix {
private:
    int n, m;
    bool **a;

public:

    BoolMatrix(int n = 2, int m = 2) : n(n), m(m) {
        allocate();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = 0;
    }

    BoolMatrix(const BoolMatrix &other) {
        n = other.n;
        m = other.m;
        allocate();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = other.a[i][j];
    }

    ~BoolMatrix() {
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
    }

    void allocate() {
        a = new bool *[n];
        for (int i = 0; i < n; i++) {
            a[i] = new bool[m];
        }
    }

    BoolMatrix& operator= (const BoolMatrix &other) {
        if (this == &other) return *this;

        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;

        n = other.n;
        m = other.m;
        allocate();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = other.a[i][j];

        return *this;
    }

    BoolMatrix operator| (const BoolMatrix &B) const {
        BoolMatrix C(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C.a[i][j] = a[i][j] || B.a[i][j];
        return C;
    }

    BoolMatrix operator& (const BoolMatrix &B) const {
        BoolMatrix C(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C.a[i][j] = a[i][j] && B.a[i][j];
        return C;
    }

    BoolMatrix operator! () const {
        BoolMatrix C(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C.a[i][j] = !a[i][j];
        return C;
    }

    int countOnes() const {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j]) cnt++;
        return cnt;
    }

    void sortRows() {
        vector<vector<bool>> rows;
        for (int i = 0; i < n; i++)
            rows.push_back(vector<bool>(a[i], a[i] + m));

        sort(rows.begin(), rows.end());

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = rows[i][j];
    }

    void input() {
        cout << "Введіть матрицю (" << n << " x " << m << "):\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
    }

    void print() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
};

void ORupdate(BoolMatrix &A, const BoolMatrix &B) {
    A = A | B;
}

int main() {
    setlocale(0, "");

    BoolMatrix A(3, 3);
    BoolMatrix B(3, 3);

    cout << "Матриця A:\n";
    A.input();
    cout << "Матриця B:\n";
    B.input();

    cout << "\nA OR B:\n";
    BoolMatrix C = A | B;
    C.print();

    cout << "\nA AND B:\n";
    BoolMatrix D = A & B;
    D.print();

    cout << "\nNOT A:\n";
    BoolMatrix E = !A;
    E.print();

    cout << "\nКількість одиниць у A: " << A.countOnes() << endl;

    cout << "\nСортування рядків A:\n";
    A.sortRows();
    A.print();

    cout << "\nA = A ∨ B (оновлення через функцію):\n";
    ORupdate(A, B);
    A.print();

    return 0;
}
