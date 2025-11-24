#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float sgpa;
    string dept;
};

int main() {
    int n = 15;
    Student s[n] = {
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

    // Bubble Sort by name (A–Z)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].name > s[j + 1].name) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    string key;
    cout << "Enter name to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    int pos = -1;

    // Binary Search (non-recursive)
    while (low <= high) {
        int mid = (low + high) / 2;

        if (s[mid].name == key) {
            pos = mid;
            break;
        }
        else if (key < s[mid].name)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (pos == -1) {
        cout << "\nNo student found with name " << key << endl;
        return 0;
    }

    cout << "\nStudent(s) found:\n";

    // print left side of pos
    int i = pos;
    while (i >= 0 && s[i].name == key) {
        cout << s[i].roll << "  " << s[i].name << "  " << s[i].sgpa << "  " << s[i].dept << endl;
        i--;
    }

    // print right side of pos
    i = pos + 1;
    while (i < n && s[i].name == key) {
        cout << s[i].roll << "  " << s[i].name << "  " << s[i].sgpa << "  " << s[i].dept << endl;
        i++;
    }

    return 0;
}
