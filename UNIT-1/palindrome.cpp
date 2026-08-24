#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp, digit, rev = 0;
    stack<int> s;

    cout << "Enter number: ";
    cin >> n;

    temp = n;

    while(temp != 0)
    {
        digit = temp % 10;
        s.push(digit);
        temp = temp / 10;
    }

    temp = n;

    while(temp != 0)
    {
        digit = temp % 10;

        if(digit != s.top())
        {
            cout << "Not Palindrome";
            return 0;
        }

        s.pop();
        temp = temp / 10;
    }

    cout << "Palindrome";

    return 0;
}