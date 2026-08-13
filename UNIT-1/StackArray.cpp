#include<bits/stdc++.h>
using namespace std;

 struct Stack
 {
    int size;
    int top;
    int *s;
 };


    void create(struct Stack *st)
    {
    cout<<"Enter the size of stack:"<<endl;
    cin>>st->size;
    st->top=-1;
    st->s=new int[st->size];
 }


  void display(struct Stack st)
  {
    int i;
    for(i=st.top;i>=0;i--)
    {
        cout<<st.s[i]<<" "<<endl;
    }
  }


void push(struct Stack *st,int x)
{  
    if(st->top==st->size-1)
    {
    cout<<"stack overflow"<<endl;
}
else 
{ 
    st->top++;
    st->s[st->top]=x;
}

}
int pop(struct Stack *st )
{       
    int x=-1;
     if(st->top==-1)
     {
      cout<<"stack underflow"<<endl;

    }
    else {
        x=st->s[st->top];
        st->top--;
    }
    return x;

}

int peek(struct Stack  st ,int pos)
{       
    int x=-1;
    if (st.top-pos+1<0)
    {
        cout<<"invalid position"<<endl;

    }

else {
    x=st.s[st.top-pos+1];
}
return x;
}

int stacktop(struct Stack st)
{
    if (st.top==-1){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else{ 
        return st.s[st.top];
    }

}
int isEmpty(struct Stack st)
{
    if (st.top==-1)
    {
        cout<<"stack is empty"<<endl;
        return 1;
    }
    cout<<"stack is not empty"<<endl;
    return 0;
}
int isFull(struct Stack st)
{
    if(st.top==st.size-1)
    {
        cout<<"stack is full"<<endl;
        return 1;
    }
    else {
        return 0;
    }
}

  
 int main()
{
    struct Stack st;

    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    cout << "Stack elements:" << endl;
    display(st);

    cout << "Popped element: " << pop(&st) << endl;

    cout << "Stack after pop:" << endl;
    display(st);

    cout << "Peek position 1: " << peek(st,1) << endl;
    cout << "Peek position 2: " << peek(st,2) << endl;

    cout << "Stack top: " << stacktop(st) << endl;

    cout << "isEmpty(): " << isEmpty(st) << endl;

    cout << "isFull(): " << isFull(st) << endl;
     //If delete[] st.s; is not used, the dynamically allocated memory is not freed, causing a memory leak. In small programs, the operating system frees the memory when the program exits, but in large or long-running programs, memory leaks can waste memory and eventually cause crashes.
    delete[] st.s;          

    return 0;
}