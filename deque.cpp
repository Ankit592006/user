#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

class Deque {
public:
    Node* front;
    Node* rear;

    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    // Insert at front
    void push_front(int x) {
        Node* temp = new Node(x);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }

        cout << x << " inserted at front.\n";
    }

    // Insert at rear
    void push_back(int x) {
        Node* temp = new Node(x);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }

        cout << x << " inserted at rear.\n";
    }

    // Delete from front
    void pop_front() {
        if (isEmpty()) {
            cout << "Deque is Empty!\n";
            return;
        }

        cout << front->data << " deleted from front.\n";

        Node* temp = front;
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete from rear
    void pop_back() {
        if (isEmpty()) {
            cout << "Deque is Empty!\n";
            return;
        }

        cout << rear->data << " deleted from rear.\n";

        Node* temp = rear;
        if (front == rear) {
            front = rear = NULL;
        } else {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    // Display Deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Deque Elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    while (true) {
        cout << "\n--- Linked List Deque Menu ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dq.push_front(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                dq.push_back(value);
                break;

            case 3:
                dq.pop_front();
                break;

            case 4:
                dq.pop_back();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
