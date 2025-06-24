#include <iostream>
using namespace std;

// Node structure for linked queue
struct Node {
    int data;
    Node* next;
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        Node* newNode = new Node();
        newNode->data = num;
        newNode->next = nullptr;

        // If queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            // Add the new node at the end of queue
            rear->next = newNode;
            rear = newNode;
        }
    }

    void remove() {
        // Check if queue is empty
        if (front == nullptr) {
            cout << "Queue underflow\n";
            return;
        }

        cout << "\nThe element deleted from the queue is: " << front->data << "\n";

        Node* temp = front;
        front = front->next;

        // If front becomes null, then change rear also to null
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void display() {
        Node* current = front;

        // Check if queue is empty
        if (current == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedQueue() {
        // Destructor to free memory
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedQueue q;
    char ch;

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch) {
            case '1':
                q.insert();
                break;
            case '2':
                q.remove();
                break;
            case '3':
                q.display();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid option!!" << endl;
                break;
            }
        }
        catch (exception& e) {
            cout << "Check for the values entered." << endl;
        }
    }

    return 0;
}