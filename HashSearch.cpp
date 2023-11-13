#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE] = {0};

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index] = key;
        cout << "Key " << key << " inserted successfully.\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        if (table[index] == key) {
            table[index] = 0;
            cout << "Key " << key << " removed successfully.\n";
        } else {
            cout << "Key " << key << " not found.\n";
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        return (table[index] == key);
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: " << table[i] << "\n";
        }
    }
};

int main() {
    HashTable hashTable;
    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                hashTable.insert(key);
                break;
            case 2:
                cout << "Enter key to remove: ";
                cin >> key;
                hashTable.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (hashTable.search(key)) {
                    cout << "Key " << key << " found in the hash table.\n";
                } else {
                    cout << "Key " << key << " not found in the hash table.\n";
                }
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
