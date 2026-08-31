#include <bits/stdc++.h>
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

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int info)
    {
        Node* newNode = new Node;
        newNode->data=info;
        if(front==NULL)
        {
            
        }




        if(isEmpty())
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
        if(isEmpty())
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

    int getFront()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    int getRear()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return rear->data;
    }

    void display()
    {
        if(isEmpty())
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

    cout << "Front Element: " << q.getFront() << endl;
    cout << "Rear Element: " << q.getRear() << endl;

    q.dequeue();

    cout << "After Dequeue: ";
    q.display();

    q.enqueue(50);

    cout << "After Enqueue: ";
    q.display();

    cout << "Is Queue Empty: " << q.isEmpty() << endl;

    return 0;
}