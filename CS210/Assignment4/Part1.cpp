#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int x) {
        value = x;
        next = nullptr;
    }
};

class linkedList {
    private:
        Node* head;
    
    public:
        linkedList() {
            head = nullptr;
        }

        void append(int x) {
            Node* newNode = new Node(x);

            if (head == nullptr) {
                head = newNode;
                return;
            }

            Node* currentNode = head;

            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }

        bool search (int x) {
            Node* currentNode = head;

            while (currentNode != nullptr) {
                if (currentNode->value == x) {
                    return true;
                }

                currentNode = currentNode->next;
            }
            return false;
        }

        void remove(int x) {
            Node* currentNode = head;

            if (head == nullptr) {
                return;
            }

            if (head->value == x) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
        
            }
            
            while (currentNode->next != nullptr) {
                if (currentNode->next->value == x) {
                    Node* temp = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    delete temp;
                    return;
                }
                currentNode = currentNode->next;
            }
        }

        void printList() {
            Node* currentNode = head;

            while (currentNode != nullptr) {
                cout << currentNode->value << endl;
                currentNode = currentNode->next;
            }
        }

};

int main() {
    linkedList list;
    
    list.append(6);
    list.append(7);
    list.append(67);

    list.printList();

    cout << list.search(67) << endl;
    cout << list.search(1) << endl;

    list.remove(6);
    list.printList();
}