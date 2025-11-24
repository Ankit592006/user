#include <iostream>
using namespace std;

class Node {
public:
    string name;
    float package;
    Node* next;

    Node(string n, float p) {
        name = n;
        package = p;
        next = NULL;
    }
};

Node* head = NULL;

void insertStudent() {
    string name;
    float package;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Package: ";
    cin >> package;

    Node* newNode = new Node(name, package);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Record Inserted Successfully!\n";
}

void displayStudents() {
    if (head == NULL) {
        cout << "No Records Found.\n";
        return;
    }
    Node* temp = head;
    cout << "\n--- Placement Records ---\n";
    while (temp != NULL) {
        cout << "Name: " << temp->name << ", Package: " << temp->package << " LPA\n";
        temp = temp->next;
    }
}

void searchStudent() {
    string key;
    cout << "Enter Name to Search: ";
    cin >> key;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == key) {
            cout << "Record Found! Package: " << temp->package << " LPA\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Record Not Found!\n";
}

void updateStudent() {
    string key;
    cout << "Enter Name to Update: ";
    cin >> key;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == key) {
            cout << "Enter New Package: ";
            cin >> temp->package;
            cout << "Record Updated Successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Record Not Found!\n";
}

void deleteStudent() {
    string key;
    cout << "Enter Name to Delete: ";
    cin >> key;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->name == key) {
        head = temp->next;
        delete temp;
        cout << "Record Deleted Successfully!\n";
        return;
    }

    while (temp != NULL && temp->name != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Record Not Found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Record Deleted Successfully!\n";
}

void sortStudents() {
    if (head == NULL) return;

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->package < j->package) {
                swap(i->package, j->package);
                swap(i->name, j->name);
            }
        }
    }
    cout << "Records Sorted by Package (High to Low)!\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n----- Placement Information System -----\n";
        cout << "1. Insert Record\n2. Display Records\n3. Search\n4. Update\n5. Delete\n6. Sort by Package\n7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortStudents(); break;
            case 7: exit(0);
            default: cout << "Invalid Choice\n";
        }
    }
}
