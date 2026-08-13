#include<bits/stdc++.h>
using namespace std;

//parenthesis matching using stack
bool isMatching(char a, char b)
{
    if(a=='(' && b==')')
        return true;
    else if(a=='{' && b=='}')
        return true;
    else if(a=='[' && b==']')
        return true;
    else
        return false;
}
//function to check if the expression is balanced or not
bool isBalanced(string exp) 
{   
    
    stack<char> s;
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            s.push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(s.empty() || !isMatching(s.top(), exp[i]))
                return false;
            else
                s.pop();
        }
    }
    return s.empty();
}
//main function
int main()
{
    string exp;
    cout<<"Enter the expression: ";
    cin>>exp;
    if(isBalanced(exp))
        cout<<"The expression is balanced"<<endl;
    else
        cout<<"The expression is not balanced"<<endl;
    return 0;
}
// This code checks if the given expression has balanced parentheses, brackets, and braces using a stack data structure. It defines a function `isMatching` to check if two characters are matching pairs of parentheses, and a function `isBalanced` to determine if the entire expression is balanced. The main function takes an input expression from the user and outputs whether it is balanced or not.

    //Code Implementatiom of ParenthesisMatch completed 
