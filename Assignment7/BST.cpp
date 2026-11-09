#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinarySearchTree {
    public:
        Node* root = nullptr;
        void insertion(int value) {
            Node* current = root;
            if (root == nullptr) {
                root = new Node{value, nullptr, nullptr};
                return;
            }
            while (current != nullptr) {
                if (value < current->value) {
                    if (current->left == nullptr) {
                        current->left = new Node{value, nullptr, nullptr};
                        return;
                    }
                    current = current->left;
                }
                else if (value > current->value) {
                    if (current->right == nullptr) {
                        current->right = new Node{value, nullptr, nullptr};
                        return;
                    }
                    current = current->right;
                }
                else {
                    //Duplicate valule case
                    return;
                }
            }
        }

        bool search(int value) {
            Node* current = root;
            while (current != nullptr) {
                if (value == current->value) {
                    return true;
                }
                else if (value < current->value) {
                    current = current->left;
                }
                else if (value > current-> value) {
                    current = current->right;
                }
            }
            return false;
        }

        bool remove(int value) {
            Node* current = root;
            Node* parent = nullptr;
            while (current != nullptr && current->value != value) {
                parent = current;

                if (value < current->value) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }
            if (current == nullptr) {
                return false;
            }

            // Leaf
            if (current->left == nullptr && current->right == nullptr) {
                if (parent == nullptr) {
                    delete current;
                    root = nullptr;
                    return true;
                }
                if (parent->left == current) {
                    parent->left = nullptr;
                    delete current;
                    return true;
                }
                else {
                    parent->right = nullptr;
                    delete current;
                    return true;
                }
            }

            // One child
            if (current->left != nullptr && current->right == nullptr) {
                if (parent == nullptr) {
                    root = current->left;
                    delete current;
                    return true;
                }
                if (parent->left == current) {
                    parent->left = current->left;
                }
                else {
                    parent->right = current->left;
                }
                delete current;
                return true;
                }
            if (current->left == nullptr && current->right != nullptr) {
                if (parent == nullptr) {
                    root = current->right;
                    delete current;
                    return true;
                }
                if (parent->left == current) {
                    parent->left = current->right;
                }
                else {
                    parent->right = current->right;
                }
                delete current;
                return true;
            }
            // Two children
            else {
                Node* replacement = current->right;
                Node* replacementParent = current;
                while (replacement->left != nullptr) {
                    replacementParent = replacement;
                    replacement = replacement->left;
                }
                current->value = replacement->value;
                if (replacementParent == current) {
                    replacementParent->right = replacement->right;
                }
                else {
                    replacementParent->left = replacement->right;
                }
                delete replacement;
                return true;
            }
        }

        void inorder(Node* current) {
            if (current == nullptr) {
                return;
            }
            inorder(current->left);
            cout << current->value << endl;
            inorder(current->right);
        }

        void preorder(Node* current) {
            if (current == nullptr) {
                return;
            }
            cout << current->value << endl;
            preorder(current->left);
            preorder(current->right);
        }

        void postorder(Node* current) {
            if (current == nullptr) {
                return;
            }
            postorder(current->left);
            postorder(current->right);
            cout << current->value << endl;
        }

        int height (Node* current) {
            if (current == nullptr) {
                return 0;
            }
            
            int leftHeight = height(current->left);
            int rightHeight = height(current->right);

            return 1 + max(leftHeight, rightHeight);
        }
};

int main() {
    BinarySearchTree tree;

    // Insert 10 distinct integers
    tree.insertion(50);
    tree.insertion(30);
    tree.insertion(70);
    tree.insertion(20);
    tree.insertion(40);
    tree.insertion(60);
    tree.insertion(80);
    tree.insertion(35);
    tree.insertion(45);
    tree.insertion(65);

    // Search tests
    cout << "Search for 40 (present): " << tree.search(40) << endl;
    cout << "Search for 100 (absent): " << tree.search(100) << endl;

    // Traversals
    cout << "\nInorder traversal:" << endl;
    tree.inorder(tree.root);

    cout << "\nPreorder traversal:" << endl;
    tree.preorder(tree.root);

    cout << "\nPostorder traversal:" << endl;
    tree.postorder(tree.root);

    // Height
    cout << "\nHeight: " << tree.height(tree.root) << endl;

    // Remove a leaf
    cout << "\nRemoving leaf node 20:" << endl;
    tree.remove(20);

    cout << "Inorder after removing 20:" << endl;
    tree.inorder(tree.root);

    // Remove a node with one child
    // 60 has one child: 65
    cout << "\nRemoving node 60 (one child):" << endl;
    tree.remove(60);

    cout << "Inorder after removing 60:" << endl;
    tree.inorder(tree.root);

    // Remove a node with two children
    // 40 has children 35 and 45
    cout << "\nRemoving node 40 (two children):" << endl;
    tree.remove(40);

    cout << "Inorder after removing 40:" << endl;
    tree.inorder(tree.root);

    return 0;
}