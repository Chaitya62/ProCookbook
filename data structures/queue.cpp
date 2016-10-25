#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    node *next;
    node(int val) : data(val), next(NULL) {}
};

class Queue {
private:
    node *rear;
    node *front;
public:
    Queue() {
        rear = NULL;
        front = NULL;
    }
    void enqueue();
    void dequeue();
    void display();
};

void Queue::enqueue() {
    int data;
    cout << "Enter the data to enqueue: ";
    cin >> data;
    node *newNode = new node(data);
    if (front == NULL){
        front = rear = newNode;
    } else {
        rear -> next = newNode;
        rear = newNode;
    }
}

void Queue::dequeue() {
    if (front == NULL) {
        cout << "\nQueue is Empty\n";
    } else {
        node *temp = front;
        front = front -> next;
        if (front == NULL)
            rear = NULL;
        cout << "The data Dequeued is " << temp -> data;
        delete temp;
    }
}

void Queue::display() {
    node *temp = front;
    if(front == NULL) {
        cout << "\nQueue is Empty!\n";
    } else {
        while (temp) {
            cout << temp -> data << endl;
            temp = temp -> next;
        }
    }
}

int main() {
    Queue queue;
    while (true) {
        int choice;
        cout << "\n1.Enqueue\n2. Dequeue\n3. Display\n4.Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                queue.enqueue();
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Input. Try again! \n";
                break;
        }
    }
    return 0;
}
