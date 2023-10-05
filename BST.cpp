#include <iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}
void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
   cout << root->data << " ";
}
TreeNode* search(TreeNode* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }

    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to display the BST in a sorted order
void display(TreeNode* root) {
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
}

int main() {
    TreeNode* root = NULL;
    int choice, value;

    while (true) {
        cout << "Binary Search Tree Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << std::endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                display(root);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Found" << std::endl;
                } else {
                    cout << "Not Found" << std::endl;
                }
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << std::endl;
        }
    }

    return 0;
}
