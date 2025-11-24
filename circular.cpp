#include <iostream>
using namespace std;

class Node {
public:
    int orderID;
    Node* next;
    Node(int id) {
        orderID = id;
        next = NULL;
    }
};

Node* front = NULL;   // first order
Node* rear = NULL;    // last order
int countOrders = 0;  // current orders

void placeOrder(int id, int M) {
    if (countOrders == M) {
        cout << "Cannot place order. Parlor Full (Max " << M << " orders allowed)\n";
        return;
    }

    Node* newNode = new Node(id);
    if (front == NULL) {              // first order
        front = rear = newNode;
        rear->next = front;           // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;           // maintain circular link
    }
    countOrders++;
    cout << "Order " << id << " placed successfully.\n";
}

void serveOrder() {
    if (front == NULL) {
        cout << "No orders to serve.\n";
        return;
    }

    cout << "Serving Order " << front->orderID << endl;

    if (front == rear) {  // only one order
        delete front;
        front = rear = NULL;
    } else {
        Node* temp = front;
        front = front->next;
        rear->next = front; // maintain circular link
        delete temp;
    }
    countOrders--;
}

void displayOrders() {
    if (front == NULL) {
        cout << "No pending orders.\n";
        return;
    }

    cout << "Pending Orders: ";
    Node* temp = front;
    do {
        cout << temp->orderID << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

int main() {
    int M;
    cout << "Enter maximum number of orders allowed: ";
    cin >> M;

    int choice, id;
    while (true) {
        cout << "\n---- Pizza Parlor Menu ----\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> id;
                placeOrder(id, M);
                break;

            case 2:
                serveOrder();
                break;

            case 3:
                displayOrders();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
