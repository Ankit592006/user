#include <iostream>
#include <string>
using namespace std;

struct Aadhar {
    long long aadharNo;
    string name;
    int age;
    string address;
};

int main() {
    Aadhar data[100];      // Array of records
    int n = 0;             // Current number of records
    int choice;

    while (true) {
        cout << "\n====== AADHAR CARD MANAGEMENT SYSTEM ======";
        cout << "\n1. Read Records";
        cout << "\n2. Display Records";
        cout << "\n3. Insert Record";
        cout << "\n4. Update Record";
        cout << "\n5. Delete Record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        // ----------------------------------------------------
        // 1. READ MULTIPLE RECORDS
        // ----------------------------------------------------
        case 1: {
            cout << "\nHow many records do you want to enter? ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\nRecord " << i + 1 << ":\n";
                cout << "Enter Aadhar Number: ";
                cin >> data[i].aadharNo;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, data[i].name);
                cout << "Enter Age: ";
                cin >> data[i].age;
                cout << "Enter Address: ";
                cin.ignore();
                getline(cin, data[i].address);
            }
            break;
        }

        // ----------------------------------------------------
        // 2. DISPLAY RECORDS
        // ----------------------------------------------------
        case 2: {
            if (n == 0) {
                cout << "\nNo records to display!";
                break;
            }
            cout << "\n--------- ALL AADHAR RECORDS ---------\n";
            for (int i = 0; i < n; i++) {
                cout << "\nRecord " << i + 1;
                cout << "\nAadhar Number: " << data[i].aadharNo;
                cout << "\nName: " << data[i].name;
                cout << "\nAge: " << data[i].age;
                cout << "\nAddress: " << data[i].address;
                cout << "\n--------------------------------------";
            }
            break;
        }

        // ----------------------------------------------------
        // 3. INSERT NEW RECORD
        // ----------------------------------------------------
        case 3: {
            if (n == 100) {
                cout << "\nArray is full! Cannot insert.";
                break;
            }
            cout << "\nEnter details of new record:\n";
            cout << "Enter Aadhar Number: ";
            cin >> data[n].aadharNo;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, data[n].name);
            cout << "Enter Age: ";
            cin >> data[n].age;
            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, data[n].address);

            n++; // Increase record count
            cout << "\nRecord inserted successfully!";
            break;
        }

        // ----------------------------------------------------
        // 4. UPDATE RECORD BY AADHAR NUMBER
        // ----------------------------------------------------
        case 4: {
            long long ano;
            cout << "\nEnter Aadhar Number to update: ";
            cin >> ano;

            int index = -1;
            for (int i = 0; i < n; i++) {
                if (data[i].aadharNo == ano) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                cout << "\nRecord not found!";
                break;
            }

            cout << "\nEnter new details:\n";
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, data[index].name);
            cout << "Enter Age: ";
            cin >> data[index].age;
            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, data[index].address);

            cout << "\nRecord updated successfully!";
            break;
        }

        // ----------------------------------------------------
        // 5. DELETE RECORD BY AADHAR NUMBER
        // ----------------------------------------------------
        case 5: {
            long long ano;
            cout << "\nEnter Aadhar Number to delete: ";
            cin >> ano;

            int index = -1;
            for (int i = 0; i < n; i++) {
                if (data[i].aadharNo == ano) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                cout << "\nRecord not found!";
                break;
            }

            // Shift elements left
            for (int i = index; i < n - 1; i++) {
                data[i] = data[i + 1];
            }
            n--;

            cout << "\nRecord deleted successfully!";
            break;
        }

        // ----------------------------------------------------
        // 6. EXIT
        // ----------------------------------------------------
        case 6:
            cout << "\nExiting program...";
            return 0;

        default:
            cout << "\nInvalid choice!";
        }
    }
}
