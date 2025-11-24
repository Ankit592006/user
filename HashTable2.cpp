#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};
int main() {
    int size = 20;   // hash table size as per question
    int key, index;
    Node* hashTable[size];
    for(int i = 0; i < size; i++)
        hashTable[i] = NULL;
    int arr[20] = {33,56,78,12,10,67,89,99,100,23,45,71,39,62,59,90,91,20,75,66};
    cout << "Inserting 20 student marks:\n";
    for(int i = 0; i < 20; i++) {
        key = arr[i];
        index = key % size;   // hash function
        Node* newNode = new Node(key);
        if(hashTable[index] == NULL) {
            hashTable[index] = newNode;
        } else {
            Node *temp = hashTable[index];
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    cout << "\nHash Table (Separate Chaining using Linked List):\n";
    for(int i = 0; i < size; i++) {
        cout << i << " --> ";
        Node *temp = hashTable[i];
        if(temp == NULL) {
            cout << "NULL";
        } else {
            while(temp != NULL) {
                cout << temp->data;
                if(temp->next != NULL) cout << " -> ";
                temp = temp->next;
            }
        }
        cout << endl;
    }

    return 0;
}
