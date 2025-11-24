#include <iostream>
using namespace std;

int main() {
    int size = 6;      // fixed hash table size as per question
    int key, index;
    int hashTable[size];
    for(int i = 0; i < size; i++)
        hashTable[i] = -1;
    cout << "Enter 6 cold drink flavour keys:\n";
    for(int i = 0; i < size; i++) {
        cout << "Enter key: ";
        cin >> key;
        index = key % size;   // hash function
        int start = index;    // remember starting point
        bool inserted = false;
        // linear probing
        while(hashTable[index] != -1) {
            index = (index + 1) % size;
            if(index == start) {               // table full
                cout << "Hash table is full. Cannot insert " << key << endl;
                inserted = false;
                break;
            }
        }
        if(hashTable[index] == -1) {           // empty slot found
            hashTable[index] = key;
            inserted = true;
        }
        if(!inserted)                          // stop inserting after full
            break;
    }

    cout << "\nHash Table:\n";
    for(int i = 0; i < size; i++)
        cout << i << " --> " << hashTable[i] << endl;

    return 0;
}
