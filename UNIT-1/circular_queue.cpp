#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
    Node* front;
    Node* rear;

public:

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);

        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            rear->next = front;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if(front == rear)
        {
            delete front;
            front = NULL;
            rear = NULL;
        }
        else
        {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display()
    {
        if(front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != front);

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Circular Queue: ";
    q.display();

    q.dequeue();

    cout << "After Dequeue: ";
    q.display();

    q.enqueue(50);

    cout << "After Enqueue: ";
    q.display();

    return 0;
}