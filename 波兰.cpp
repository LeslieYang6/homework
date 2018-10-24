#include<iostream>
#include<stack>
using namespace std;


void midtfix(string p,stack<char>& S2) {
    stack<char> S1;
    int length =(int)p.length();
    for (int i =0; i < length; i++) {
        if (p[i] >= '0' && p[i] <= '9')
            S2.push(p[i]);
        else {
            switch (p[i]) {
                case '(':
                    S1.push(p[i]);
                    break;
                case ')':
                    while (S1.top() != '(') {
                        S2.push(S1.top());
                        S1.pop();
                    }
                    S1.pop(); 
                    break;
                case '*':
                    while(!S1.empty()&&S1.top()!='('&&(S1.top()=='/'||S1.top()=='*'))
                    {
                        S2.push(S1.top());
                        S1.pop();
                    }
                    S1.push(p[i]);
                    break;
                case '/':
                    while(!S1.empty()&&S1.top()!='('&&(S1.top()=='/'||S1.top()=='*'))
                    {
                        S2.push(S1.top());
                        S1.pop();
                    }
                    S1.push(p[i]);
                    break;
                case '+':
                    while(!S1.empty()&&S1.top()!='(')
                    {
                        S2.push(S1.top());
                        S1.pop();
                    }
                    S1.push(p[i]);
                    break;
                case '-':
                    while(!S1.empty()&&S1.top()!='(')
                    {
                        S2.push(S1.top());
                        S1.pop();
                    }
                    S1.push(p[i]);
                    break;
                default:
                    break;
            }
        }
    }
    while (!S1.empty()) {
        S2.push(S1.top());
        S1.pop();
    }
}


int Computeprefix(stack<char> S1)
{
    stack<char> S2;
    while(!S1.empty())
    {
        S2.push(S1.top());
        S1.pop();
    }
    stack<int>temp;
    while(!S2.empty())
    {
        if(S2.top()>='0'&&S2.top()<='9')
        {
            temp.push(S2.top()-'0');
            S2.pop();
        }
        else {
            int x = temp.top();
            temp.pop();
            int y = temp.top();
            temp.pop();
            switch (S2.top()) {
                case '+':
                    x = y + x;
                    temp.push(x);
                    break;
                case '-':
                    x = y - x;
                    temp.push(x);
                    break;
                case '*':
                    x = y * x;
                    temp.push(x);
                    break;
                case '/':
                    x = y / x;
                    temp.push(x);
                    break;
                default:
                    break;
            }
            S2.pop();
        }
    }
    return temp.top();
}
int main()
{
    string test="(3+4)*5-6";
    stack<char> S;
    midtfix(test,S);
    cout<<Computeprefix(S);

}