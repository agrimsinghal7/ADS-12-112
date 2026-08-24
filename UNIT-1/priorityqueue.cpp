#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node* next;

    Node(int value, int p)
    {
        data = value;
        priority = p;
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

    void enqueue(int value, int p)
    {
        Node* newNode = new Node(value, p);

        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }

        if(p > front->priority)
        {
            newNode->next = front;
            front = newNode;
            return;
        }

        Node* temp = front;

        while(temp->next != NULL && temp->next->priority >= p)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if(newNode->next == NULL)
        {
            rear = newNode;
        }
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Deleted element: " << front->data << endl;

        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    void display()
    {
        if(front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        while(temp != NULL)
        {
            cout << "Element: " << temp->data
                 << " Priority: " << temp->priority << endl;

            temp = temp->next;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10, 2);
    q.enqueue(20, 5);
    q.enqueue(30, 1);
    q.enqueue(40, 4);

    cout << "Priority Queue:" << endl;
    q.display();

    q.dequeue();

    cout << "\nAfter Dequeue:" << endl;
    q.display();

    return 0;
}