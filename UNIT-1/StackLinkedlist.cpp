#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
     struct Node *next;
};
 //Gloal pointer to top of stack
 Node *top = NULL;  
 //isa matlab hai ki top pointer ko NULL se initialize kiya gaya hai, iska matlab hai ki stack khali hai

 //Display operation
 void display()
 {
    Node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
 }
//Push Operation
void push( int x )
{
    Node*t=new Node;
    if(t==NULL){
        cout<<"stack overflow"<<endl;
    }
    else {
        t->data=x;
        t->next=top;
        top=t;
    }
    }

    //pop operation
    int pop()
    {
        Node *m;
        int x=-1;
        if(top==NULL)
        {
            cout<<"stack underflow"<<endl;
        }
        else {
            m=top;
            top=top->next;
            x=m->data;
            free(m);
        }
        return x;
    }

    //peek operation                            
    //ye thoda tricky hai isme humne pos-1 kiya hai kyuki humne 0 se start kiya hai aur pos-1 tak ja rahe hai 
    int peek (int pos){
        int x=-1;
        Node *q=top;
        for(int i=0;q!=NULL && i<pos-1;i++) //pos-1  hai to then  humne 0 se start kiya hai aur pos-1 tak ja rahe hai
        {
            q=q->next;     //iska matlab yo ki humne desired position tak pahunch gaye hai
        }
        if(q!=NULL)     //agar q NULL nahi hai to iska matlab hai ki humne desired position tak pahunch gaye hai
        {
            x=q->data;   //to humne jo data chahiye tha wo mil gaya hai
        }
        else {
            cout<<"invalid position"<<endl;
        }
        
        return x;
    }

    //stack top operation
    int stacktop()
    {
        if (top==NULL){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else{ 
            return top->data;
        }

    }

    //isEmpty operation
    int isEmpty(){
        if(top==NULL)
        {
            cout<<"stack is empty"<<endl;
            return 1;
        }
        else
        {
            cout<<"stack is not empty"<<endl;
            return 0;
        }
    }

    //isFull operation
    int isFull(){
        Node *t=new Node;
        if(t==NULL)
        {
        cout<<"stack is full"<<endl;
        return 1;
        }
        else
        {
            cout<<"stack is not full"<<endl;
            return 0;
        }
    }

    int main()
    {
        push(10);
        push(20);
        push(30);
        push(40);
        push(50);
        display();

        cout << "peek(3): " << peek(3) << endl;
        cout << "stacktop(): " << stacktop() << endl;
        cout << "pop(): " << pop() << endl;
        cout << "stacktop(): " << stacktop() << endl;
        display();
    }

    //Code Implementatiom of Stack using Linkedlist completed 
