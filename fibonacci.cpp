#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float sgpa;
    string dept;
};

int fibSearch(Student s[], int n, string key) {
    int fib2 = 0, fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (s[i].dept < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (s[i].dept > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
            return i;
    }

    if (fib1 && offset + 1 < n && s[offset + 1].dept == key)
        return offset + 1;

    return -1;
}

int main() {
    Student s[15] = {
        {1,"Amit",9.1,"Computer"},
        {2,"Neha",8.5,"IT"},
        {3,"Rohan",9.1,"ENTC"},
        {4,"Priya",7.8,"Mechanical"},
        {5,"Sam",8.5,"Computer"},
        {6,"Meera",9.4,"IT"},
        {7,"Yash",7.1,"Civil"},
        {8,"Rutu",8.5,"IT"},
        {9,"Kabir",9.4,"Computer"},
        {10,"Anu",6.9,"ENTC"},
        {11,"Deep",7.8,"Civil"},
        {12,"Sara",8.8,"Computer"},
        {13,"Nikhil",9.1,"Mechanical"},
        {14,"Ravi",7.1,"IT"},
        {15,"Om",8.8,"ENTC"}
    };

    int n = 15;

    // SORT by Department (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].dept > s[j + 1].dept) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    string key = "Computer";
    int index = fibSearch(s, n, key);

    cout << "\nSearching whether student belongs to COMPUTER department...\n";

    if (index == -1) {
        cout << "\nNo student from Computer Department found.\n";
        return 0;
    }

    cout << "\nStudent(s) in Computer Department:\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < n; i++) {
        if (s[i].dept == key) {
            cout << s[i].roll << "  " << s[i].name << "  " << s[i].sgpa << "  " << s[i].dept << endl;
        }
    }

    return 0;
}
