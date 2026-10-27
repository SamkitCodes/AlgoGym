#include <iostream>
using namespace std;

// Problem: Pattern 1 — square of stars
// Time:  O(n^2) — n rows × n stars each
// Space: O(1)
void pattern1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << "* ";
        cout << "\n";
    }
}

// Problem: Pattern 9 — Diamonds
// Time:  O(n^2) — 2n rows × 2n (stars + space) each
// Space: O(1)
void pattern9(int n) {
    for (int i = 0; i < n; i++) {
        //space
        for (int j = 0; j < n - 1 - i; j++) {
            cout << " ";
        }

        //star
        for (int j = 0; j < (2 * i) + 1; j++) {
            cout << "*";
        }

        //space
        for (int j = 0; j < n - 1 - i; j++) {
            cout << " ";
        }
        cout << "\n";
    }


    for (int i = 0; i < n; i++) {
        //space
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        //star
        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            cout << "*";
        }

        //space
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "\n";
    }
}


// Problem: Pattern 11- Binary Triangle
// Time: O(n^2) - Outer loop n inner loop 0,1,2,3,...,(n)
// Space: O(1)
void pattern11(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << (((i + j) % 2 == 0) ? 1 : 0);
        }

        cout << endl;
    }
}

// Problem: Pattern 22 - Border Numbers
// Time: O(n^2)
// Space: O(1)
void pattern22(int n) {
    int size = (2 * n) - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int bottom = (size - 1) - i;
            int left = j;
            int right = (size - 1) - j;

            int min_dist = std::min({top, bottom, left, right});

            std::cout << (n - min_dist) << " ";
        }
        cout << "\n";
    }
}


int main() {
    //pattern1(4);
    //pattern9(5);
    //pattern11(5);
    pattern22(4);
}
