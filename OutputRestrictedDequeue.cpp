// #include <iostream>
// #include <deque>
// using namespace std;

// int main() {
//     deque<int> dq;

//     // Insert from rear
//     dq.push_back(201);

//     // Insert from front
//     dq.push_front(202);

//     // Insert from rear
//     dq.push_back(203);

//     cout << "Customers in queue: ";
//     for (int i = 0; i < dq.size(); i++)
//         cout << dq[i] << " ";
//     cout << endl;

//     // Deletion allowed only from front
//     dq.pop_front();
//     cout << "After deleting from front: ";
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
        cout << "\n--- Output Restricted Deque ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Back\n";
        cout << "3. Delete from Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter customer id to insert: ";
                cin >> item;
                dq.push_front(item);
                break;

            case 2:
                cout << "Enter customer id to insert: ";
                cin >> item;
                dq.push_back(item);
                break;

            case 3:
                if (dq.empty())
                    cout << "Queue Empty\n";
                else {
                    cout << "Deleted customer: " << dq.front() << endl;
                    dq.pop_front();
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
