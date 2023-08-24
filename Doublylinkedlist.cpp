#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* ftr;
    struct node* btr;
};

struct node* head;

class DLL {
public:
    int p, s;

    void begininsert() {
        int value;
        struct node* ptr = new node;
        cout << "Enter the value:";
        cin >> value;
        ptr->data = value;
        ptr->ftr = head;
        ptr->btr = NULL;
        if (head != NULL)
            head->btr = ptr;
        head = ptr;
    }

    void lastinsert() {
        struct node* ptr = new node;
        struct node* temp = head;
        int value;
        cout << "Enter the value:";
        cin >> value;
        ptr->data = value;
        ptr->ftr = NULL;
        if (head == NULL) {
            ptr->btr = NULL;
            head = ptr;
        } else {
            while (temp->ftr != NULL)
                temp = temp->ftr;
            ptr->btr = temp;
            temp->ftr = ptr;
        }
    }

    void randominsert() {
        cout << "Enter the position you want to insert:";
        cin >> p;
        if (p <= 0) {
            begininsert();
        } else {
            int value;
            cout << "Enter the value:";
            cin >> value;

            struct node* ptr = new node;
            struct node* temp = head;
            ptr->data = value;

            for (int i = 1; i < p && temp->ftr; i++) {
                temp = temp->ftr;
            }

            if (temp == NULL) {
                begininsert();
            }

            ptr->ftr = temp->ftr;
            ptr->btr = temp;

            if (temp->ftr != NULL) {
                temp->ftr->btr = ptr;
            }
            temp->ftr = ptr;
        }
    }

    void begindelete() {
        if (head == NULL) {
            cout << "The list is empty";
        } else {
            struct node* temp = head;
            head = head->ftr;

            if (head != NULL) {
                head->btr = NULL;
            }

            delete temp;
        }
    }

    void lastdelete() {
        if (head == NULL) {
            cout << "The list is empty";
        } else {
            struct node* temp = head;

            while (temp->ftr != NULL) {
                temp = temp->ftr;
            }

            if (temp->btr != NULL) {
                temp->btr->ftr = NULL;
            } else {
                head = NULL;
            }

            delete temp;
        }
    }

    void randomdelete() {
        cout << "Enter the position you want to delete:";
        cin >> p;

        if (p <= 0) {
            begindelete();
        } else {
            struct node* temp = head;

            for (int i = 1; i < p && temp != NULL; ++i) {
                temp = temp->ftr;
            }

            if (temp == NULL) {
                return;
            }

            if (temp->btr != NULL) {
                temp->btr->ftr = temp->ftr;
            } else {
                head = temp->ftr;
            }

            if (temp->ftr != NULL) {
                temp->ftr->btr = temp->btr;
            }

            delete temp;
        }
    }

    void reverse() {
        struct node* ptr =new node ;
        struct node* temp=head;
        while(temp->ftr!=NULL){temp=temp->ftr;
		}
		ptr=temp;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->btr;
        }
    }

    void display() {
        struct node* ptr = head;

        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->ftr;
        }
    }

    void search() {
        cout << "Enter the element you want to search:";
        cin >> s;
        struct node* temp = head;

        while (temp != NULL) {
            if (temp->data == s) {
                cout << "Element found";
                return;
            }
            temp = temp->ftr;
        }
        cout << "Not found";
    }
};

int main() {
    DLL l;
    int c = 0;

    while (c != 10) {
        cout << "\n1. Insert in beginning\n2. Insert at last\n3. Insert at random\n4. Delete in beginning\n5. Delete at last\n6. Delete at random\n7. Display\n8. Reverse display\n9. Search\n:";
        cin >> c;

        switch (c) {
            case 1:
                l.begininsert();
                break;
            case 2:
                l.lastinsert();
                break;
            case 3:
                l.randominsert();
                break;
            case 4:
                l.begindelete();
                break;
            case 5:
                l.lastdelete();
                break;
            case 6:
                l.randomdelete();
                break;
            case 7:
                l.display();
                break;
            case 8:
                l.reverse();
                break;
            case 9:
                l.search();
                break;
            case 10:
                cout << "Exiting";
                break;
            default:
                cout << "Invalid";
        }
    }
    return 0;
}
