#include <iostream>
using namespace std;

class ArrayStack {
private:
    int arr[10];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    void push(int value) {
        if (top == 9) {
            cout << "Stack is full" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Removed: " << arr[top] << endl;
        top--;
    }

    void print() {
        cout << "Stack: ";

        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

struct StackNode {
    int value;
    StackNode* next;
};

class LinkedStack {
private:
    StackNode* top;

public:
    LinkedStack() {
        top = nullptr;
    }

    void push(int value) {
        StackNode* newNode = new StackNode();
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        StackNode* temp = top;

        cout << "Removed: " << top->value << endl;

        top = top->next;
        delete temp;
    }

    void print() {
        StackNode* current = top;

        cout << "Stack: ";

        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }
};

class ArrayQueue {
private:
    int arr[10];
    int size;

public:
    ArrayQueue() {
        size = 0;
    }

    void enqueue(int value) {
        if (size == 10) {
            cout << "Queue is full" << endl;
            return;
        }

        arr[size] = value;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Removed: " << arr[0] << endl;

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void print() {
        cout << "Queue: ";

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

struct QueueNode {
    int value;
    QueueNode* next;
};

class LinkedQueue {
private:
    QueueNode* front;
    QueueNode* back;

public:
    LinkedQueue() {
        front = nullptr;
        back = nullptr;
    }

    void enqueue(int value) {
        QueueNode* newNode = new QueueNode();
        newNode->value = value;
        newNode->next = nullptr;

        if (front == nullptr) {
            front = newNode;
            back = newNode;
            return;
        }

        back->next = newNode;
        back = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        QueueNode* temp = front;

        cout << "Removed: " << front->value << endl;

        front = front->next;
        delete temp;

        if (front == nullptr) {
            back = nullptr;
        }
    }

    void print() {
        QueueNode* current = front;

        cout << "Queue: ";

        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }
};

class ArrayDeque {
private:
    int arr[10];
    int size;

public:
    ArrayDeque() {
        size = 0;
    }

    void pushBack(int value) {
        if (size == 10) {
            cout << "Deque is full" << endl;
            return;
        }

        arr[size] = value;
        size++;
    }

    void pushFront(int value) {
        if (size == 10) {
            cout << "Deque is full" << endl;
            return;
        }

        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;
        size++;
    }

    void popFront() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Removed front: " << arr[0] << endl;

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void popBack() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Removed back: " << arr[size - 1] << endl;
        size--;
    }

    void print() {
        cout << "Deque: ";

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

struct DequeNode {
    int value;
    DequeNode* next;
    DequeNode* previous;
};

class LinkedDeque {
private:
    DequeNode* front;
    DequeNode* back;

public:
    LinkedDeque() {
        front = nullptr;
        back = nullptr;
    }

    void pushFront(int value) {
        DequeNode* newNode = new DequeNode();

        newNode->value = value;
        newNode->previous = nullptr;
        newNode->next = front;

        if (front == nullptr) {
            front = newNode;
            back = newNode;
            return;
        }

        front->previous = newNode;
        front = newNode;
    }

    void pushBack(int value) {
        DequeNode* newNode = new DequeNode();

        newNode->value = value;
        newNode->next = nullptr;
        newNode->previous = back;

        if (back == nullptr) {
            front = newNode;
            back = newNode;
            return;
        }

        back->next = newNode;
        back = newNode;
    }

    void popFront() {
        if (front == nullptr) {
            cout << "Deque is empty" << endl;
            return;
        }

        DequeNode* temp = front;

        cout << "Removed front: " << front->value << endl;

        front = front->next;

        if (front == nullptr) {
            back = nullptr;
        } else {
            front->previous = nullptr;
        }
        delete temp;
    }

    void popBack() {
        if (back == nullptr) {
            cout << "Deque is empty" << endl;
            return;
        }

        DequeNode* temp = back;

        cout << "Removed back: " << back->value << endl;

        back = back->previous;

        if (back == nullptr) {
            front = nullptr;
        } else {
            back->next = nullptr;
        }

        delete temp;
    }

    void print() {
        DequeNode* current = front;

        cout << "Deque: ";

        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    cout << "ARRAY STACK" << endl;

    ArrayStack arrayStack;

    arrayStack.push(10);
    arrayStack.push(20);
    arrayStack.push(30);
    arrayStack.pop();
    arrayStack.push(40);
    arrayStack.push(50);
    arrayStack.pop();
    arrayStack.pop();
    arrayStack.pop();
    arrayStack.pop();
    arrayStack.pop();

    arrayStack.print();

    cout << "\nLINKED STACK" << endl;

    LinkedStack linkedStack;

    linkedStack.push(10);
    linkedStack.push(20);
    linkedStack.push(30);
    linkedStack.pop();
    linkedStack.push(40);
    linkedStack.push(50);
    linkedStack.pop();
    linkedStack.pop();
    linkedStack.pop();
    linkedStack.pop();
    linkedStack.pop();

    linkedStack.print();

    cout << "\nARRAY QUEUE" << endl;

    ArrayQueue arrayQueue;

    arrayQueue.enqueue(10);
    arrayQueue.enqueue(20);
    arrayQueue.enqueue(30);
    arrayQueue.dequeue();
    arrayQueue.enqueue(40);
    arrayQueue.enqueue(50);
    arrayQueue.dequeue();
    arrayQueue.dequeue();
    arrayQueue.dequeue();
    arrayQueue.dequeue();
    arrayQueue.dequeue();

    arrayQueue.print();

    cout << "\nLINKED QUEUE" << endl;

    LinkedQueue linkedQueue;

    linkedQueue.enqueue(10);
    linkedQueue.enqueue(20);
    linkedQueue.enqueue(30);
    linkedQueue.dequeue();
    linkedQueue.enqueue(40);
    linkedQueue.enqueue(50);
    linkedQueue.dequeue();
    linkedQueue.dequeue();
    linkedQueue.dequeue();
    linkedQueue.dequeue();
    linkedQueue.dequeue();

    linkedQueue.print();

    cout << "\nARRAY DEQUE" << endl;

    ArrayDeque arrayDeque;

    arrayDeque.pushBack(10);
    arrayDeque.pushBack(20);
    arrayDeque.pushFront(5);
    arrayDeque.pushBack(30);
    arrayDeque.popFront();
    arrayDeque.pushFront(1);
    arrayDeque.popBack();
    arrayDeque.popFront();
    arrayDeque.popBack();
    arrayDeque.popBack();
    arrayDeque.popBack();

    arrayDeque.print();

    cout << "\nLINKED DEQUE" << endl;

    LinkedDeque linkedDeque;

    linkedDeque.pushBack(10);
    linkedDeque.pushBack(20);
    linkedDeque.pushFront(5);
    linkedDeque.pushBack(30);
    linkedDeque.popFront();
    linkedDeque.pushFront(1);
    linkedDeque.popBack();
    linkedDeque.popFront();
    linkedDeque.popBack();
    linkedDeque.popBack();
    linkedDeque.popBack();

    linkedDeque.print();

    return 0;
}