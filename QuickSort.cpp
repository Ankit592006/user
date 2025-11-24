#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float sgpa;
    string dept;

    void getData(int r, string n, float s, string d) {
        roll = r;
        name = n;
        sgpa = s;
        dept = d;
    }

    void display() {
        cout << roll << "\t" << name << "\t" << sgpa << "\t" << dept << endl;
    }
};

// Quick Sort partition (Descending order based on SGPA)
int partition(Student s[], int low, int high) {
    float pivot = s[high].sgpa;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (s[j].sgpa > pivot) {   // greater SGPA first
            i++;
            Student temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    Student temp = s[i + 1];
    s[i + 1] = s[high];
    s[high] = temp;

    return (i + 1);
}

// Quick Sort function
void quickSort(Student s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

int main() {
    const int n = 15;
    Student s[n];

    s[0].getData(105, "Amit", 8.1, "Computer");
    s[1].getData(102, "Neha", 8.5, "ENTC");
    s[2].getData(110, "Rahul", 7.9, "IT");
    s[3].getData(101, "Sneha", 9.0, "Computer");
    s[4].getData(115, "Manas", 7.2, "Mechanical");
    s[5].getData(108, "Pooja", 8.0, "Electrical");
    s[6].getData(113, "Kiran", 8.8, "Civil");
    s[7].getData(107, "Riya", 7.5, "ENTC");
    s[8].getData(103, "Sagar", 6.9, "IT");
    s[9].getData(111, "Tina", 9.2, "Computer");
    s[10].getData(109, "Yash", 7.4, "Mechanical");
    s[11].getData(104, "Rohan", 8.4, "Electrical");
    s[12].getData(114, "Sana", 8.9, "Civil");
    s[13].getData(106, "Meera", 7.7, "Computer");
    s[14].getData(112, "Kartik", 8.3, "ENTC");

    // Sort using quick sort (descending SGPA)
    quickSort(s, 0, n - 1);

    cout << "\n--- Top 10 Toppers of TY BTECH Class ---\n";
    cout << "Roll\tName\tSGPA\tDepartment\n";

    for (int i = 0; i < 10; i++)
        s[i].display();

    return 0;
}
