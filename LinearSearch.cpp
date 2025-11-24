#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float sgpa;
    string dept;
};

int main() {
    int n = 15;        // At least 15 records
    Student s[n] = {
        {1, "Amit", 9.1, "Computer"},
        {2, "Neha", 8.5, "IT"},
        {3, "Rohan", 9.1, "ENTC"},
        {4, "Priya", 7.8, "Mechanical"},
        {5, "Sam", 8.5, "Computer"},
        {6, "Meera", 9.4, "IT"},
        {7, "Yash", 7.1, "Civil"},
        {8, "Rutu", 8.5, "IT"},
        {9, "Kabir", 9.4, "Computer"},
        {10, "Anu", 6.9, "ENTC"},
        {11, "Deep", 7.8, "Civil"},
        {12, "Sara", 8.8, "Computer"},
        {13, "Nikhil", 9.1, "Mechanical"},
        {14, "Ravi", 7.1, "IT"},
        {15, "Om", 8.8, "ENTC"}
    };

    float key;
    cout << "Enter SGPA to search : ";
    cin >> key;

    bool found = false;

    // Linear Search
    for (int i = 0; i < n; i++) {
        if (s[i].sgpa == key) {
            found = true;
            cout << "\nRoll: " << s[i].roll
                 << "\nName: " << s[i].name
                 << "\nSGPA: " << s[i].sgpa
                 << "\nDepartment: " << s[i].dept << endl;
            cout << "------------------------";
        }
    }

    if (!found)
        cout << "\nNo student found with SGPA = " << key << endl;

    return 0;
}
