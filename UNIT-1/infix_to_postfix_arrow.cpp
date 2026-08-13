#include<bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";
    
    for(int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        
        // If character is operand, add to postfix
        if(isalnum(c))
        {
            postfix += c;
        }
        // If character is '(', push to stack
        else if(c == '(')
        {
            s.push(c);
        }
        // If character is ')', pop till '('
        else if(c == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        }
        // If character is operator
        else if(isOperator(c))
        {
            while(!s.empty() && precedence(s.top()) >= precedence(c))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    // Pop remaining operators from stack
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    
    return 0;
}