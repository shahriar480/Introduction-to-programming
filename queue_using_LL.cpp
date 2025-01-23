#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front=nullptr;
        rear=nullptr;
    }
    void enqueue(int value) {
     Node* temp=new Node();
     temp->data=value;
     temp->next=nullptr;
     if (rear==nullptr) {
      front=rear=temp;
       return;
        }
        rear->next=temp;
        rear=temp;
    }
    void reverse() {
        Node* prev=nullptr;
        Node* current=front;
        Node* next=nullptr;
        rear=front;
        while (current!=nullptr) {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        front=prev;
    }

    void print() {
        Node* temp=front;
        while (temp) {
            cout<<temp->data<< " ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "Original Queue (Front-to-Rear): ";
    q.print();

    q.reverse();

    cout<<"Reversed Queue (Rear-to-Front): ";
    q.print();

    return 0;
}
