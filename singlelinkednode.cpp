#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

class Node {
public:
    struct node *head;
    Node() {
        head = NULL;
    }

    void begininsert() {
        int item;
        cout << "Enter the value:";
        cin >> item;
        struct node* ptr = new node;
        if (ptr == NULL) {
            cout << "Overflow";
        }
        else {
            ptr->data = item;
            ptr->next = head;
            head = ptr;
        }
    }

    void lastinsert() {
        int item;
        cout << "Enter the value:";
        cin >> item;
        struct node* ptr = new node;
        if (ptr == NULL) {
            cout << "Overflow";
        }
        else {
            ptr->data = item;
            ptr->next = NULL;
            if (head == NULL) {
                head = ptr;
            }
            else {
                struct node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = ptr;
            }
        }
    }

    void randominsert() {
        int item, loc;
        cout << "Enter the value:";
        cin >> item;
        cout << "Enter the location:";
        cin >> loc;
        struct node* ptr = new node;
        if (ptr == NULL) {
            cout << "Overflow";
        }
        else {
            ptr->data = item;
            struct node* temp = head;
            for (int i = 1; i < loc - 1; i++) {
                temp = temp->next;
                if (temp == NULL) {
                    cout << "Cannot insert";
                    return;
                }
            }
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }

    void begindelete() {
        if (head == NULL) {
            cout << "Underflow";
        }
        else {
            struct node* ptr = head;
            head = head->next;
            delete ptr;
            cout << "Node deleted from the beginning";
        }
    }

    void lastdelete() {
        if (head == NULL) {
            cout << "Underflow";
        }
        else if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Node deleted from the last";
        }
        else {
            struct node* ptr = head;
            struct node* prev = NULL;
            while (ptr->next != NULL) {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = NULL;
            delete ptr;
            cout << "Node deleted from the last";
        }
    }

    void randomdelete() {
        int loc;
        cout << "Enter the location:";
        cin >> loc;
        if (loc <= 0) {
            cout << "Invalid location";
            return;
        }
        if (head == NULL) {
            cout << "Underflow";
            return;
        }
        if (loc == 1) {
            struct node* ptr = head;
            head = head->next;
            delete ptr;
            cout << "Node deleted";
            return;
        }
        struct node* ptr = head;
        struct node* prev = NULL;
        for (int i = 1; i < loc; i++) {
            prev = ptr;
            ptr = ptr->next;
            if (ptr == NULL) {
                cout << "Cannot delete";
                return;
            }
        }
        prev->next = ptr->next;
        delete ptr;
        cout << "Node deleted";
    }

    void display() {
        struct node* ptr = head;
        if (ptr == NULL) {
            cout << "No elements";
        }
        else {
            cout << "The values:";
            while (ptr != NULL) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }
    }
};

int main() {
    Node n;
    int c = 0;
    while (c != 8) {
        cout << "\n1.Insert in beginning \n2.Insert at last \n3.Insert at random \n4.Delete in beginning \n5.Delete at last \n6.Delete at random \n7.Display \n8.Exit\n";
        cin >> c;
        switch (c) {
        case 1:
            n.begininsert();
            break;
        case 2:
            n.lastinsert();
            break;
        case 3:
            n.randominsert();
            break;
        case 4:
            n.begindelete();
            break;
        case 5:
            n.lastdelete();
            break;
        case 6:
            n.randomdelete();
            break;
        case 7:
            n.display();
            break;
        case 8:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid";
        }
    }
    return 0;
}
