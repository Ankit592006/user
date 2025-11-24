#include <iostream>
using namespace std;

int main() {
    int size = 11;   // hash table size
    int hashTable[size];
    for(int i = 0; i < size; i++)
        hashTable[i] = -1;
    int arr[11] = {25, 15, 10, 5, 11, 19, 16, 36, 42, 28, 32};
    cout << "Inserting 11 mango category values using Quadratic Probing...\n";
    for(int i = 0; i < size; i++) {
        int key = arr[i];
        int index = key % size;
        int j = 1;
        // quadratic probing when collision happens
        while(hashTable[index] != -1) {
            index = (key + j*j) % size;   // quadratic probing formula
            j++;
            if(j > size) {   // table full condition safety check
                cout << "Hash table is full. Cannot insert " << key << endl;
                break;
            }
        }
        if(hashTable[index] == -1)
            hashTable[index] = key;
    }
    cout << "\nHash Table:\n";
    for(int i = 0; i < size; i++)
        cout << i << " --> " << hashTable[i] << endl;
    return 0;
}
