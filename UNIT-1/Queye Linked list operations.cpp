#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int info;
    Node* next;

    Node(int data)
    {
        info = data;
        next = NULL;
    }
};

Node *front = NULL, *rear = NULL;

bool isEmpty()
{
    return front == NULL;
}

void traverse()
{
    if(front == NULL)
    {
        cout << "Empty Queue";
        return;
    }

    Node *temp = front;

    while(temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
    cout << "Front = " << front->info << ", Rear = " << rear->info;
}

void enqueue(int info)
{
    Node *newNode = new Node(info);

    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    int info;

    if(front == NULL)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    info = front->info;
    Node *temp = front;

    if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }

    delete temp;
    return info;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    
    

    return 0;
}