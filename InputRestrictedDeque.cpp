// #include <iostream>
// #include <deque>
// using namespace std;

// int main() {
//     deque<int> dq;

//     // Insertion allowed only at back
//     dq.push_back(101);
//     dq.push_back(102);
//     dq.push_back(103);

//     cout << "Customers in queue: ";
//     for (int i = 0; i < dq.size(); i++)
//         cout << dq[i] << " ";
//     cout << endl;

//     // Delete from front
//     dq.pop_front();
//     cout << "After deleting from front: ";
//     for (int i = 0; i < dq.size(); i++)
//         cout << dq[i] << " ";
//     cout << endl;

//     // Delete from rear
//     dq.pop_back();
//     cout << "After deleting from rear: ";
//     for (int i = 0; i < dq.size(); i++)
//         cout << dq[i] << " ";
//     cout << endl;

//     return 0;
// }


#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int choice, item;

    while (true) {
        cout << "\n--- Input Restricted Deque ---\n";
        cout << "1. Insert at Back\n";
        cout << "2. Delete from Front\n";
        cout << "3. Delete from Back\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter customer id to insert: ";
                cin >> item;
                dq.push_back(item);
                break;

            case 2:
                if (dq.empty())
                    cout << "Queue Empty\n";
                else {
                    cout << "Deleted customer: " << dq.front() << endl;
                    dq.pop_front();
                }
                break;

            case 3:
                if (dq.empty())
                    cout << "Queue Empty\n";
                else {
                    cout << "Deleted customer: " << dq.back() << endl;
                    dq.pop_back();
                }
                break;

            case 4:
                if (dq.empty())
                    cout << "Queue Empty\n";
                else {
                    cout << "Customers: ";
                    for (int i = 0; i < dq.size(); i++)
                        cout << dq[i] << " ";
                    cout << endl;
                }
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
