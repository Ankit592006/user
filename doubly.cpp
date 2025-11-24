#include <iostream>
using namespace std;

class Node {
public:
    int marks;
    Node* next;
    Node* prev;
    Node(int m) {
        marks = m;
        next = prev = NULL;
    }
};

Node* insertEnd(Node* head, int m) {
    Node* newNode = new Node(m);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL)
    temp = temp->next;
    
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->marks << " ";
        temp = temp->next;
    }
    cout << endl;
}

void sortList(Node* head) {
    for (Node* i = head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->marks > j->marks) {   // ascending order
                swap(i->marks, j->marks);
            }
        }
    }
}

Node* mergeLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;
    return head1;
}

int main() {
    Node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int n1, n2, val;

    cout << "Enter number of marks in List 1: ";
    cin >> n1;
    cout << "Enter marks: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        list1 = insertEnd(list1, val);
    }

    cout << "Enter number of marks in List 2: ";
    cin >> n2;
    cout << "Enter marks: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        list2 = insertEnd(list2, val);
    }

    cout << "\nList 1 Before Sorting: ";
    display(list1);
    cout << "List 2 Before Sorting: ";
    display(list2);

    sortList(list1);
    sortList(list2);

    cout << "\nList 1 After Sorting: ";
    display(list1);
    cout << "List 2 After Sorting: ";
    display(list2);

    merged = mergeLists(list1, list2);
    sortList(merged);

    cout << "\nMerged Sorted List: ";
    display(merged);

    return 0;
}
