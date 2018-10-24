#include<iostream>
#include<string>
#include<stack>
using namespace std;

void midtprix(string p,stack<char>& S2) {
    stack<char> S1;
    unsigned long length = p.length();
    for (int i = (int) (length - 1); i >= 0; i--) {
        if (p[i] >= '0' && p[i] <= '9')
            S2.push(p[i]);
        else {
            switch (p[i]) {
                case ')':
                    S1.push(p[i]);
                    break;
                case '(':
                    while (S1.top() != ')') {
                        S2.push(S1.top());
                        S1.pop();
                    }
                    S1.pop();
                    break;
                case '*':
                    S1.push(p[i]);
                    break;
                case '/':
                    S1.push(p[i]);
                    break;
                case '+':
                    while (!S1.empty() && (S1.top() != ')') && (S1.top() == '/' || S1.top() == '*')) {
                        S2.push(S1.top());
                        S1.pop();
                    }
                    S1.push(p[i]);
                    break;
                case '-':
                    while (!S1.empty() && (S1.top() != ')') && (S1.top() == '/' || S1.top() == '*')) {
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

int ComputingPrefix(stack<char> S1)
    {
        stack<char> S2;// 用于存放逆序的Ｓ1
        while(!S1.empty())
        {
            S2.push(S1.top());
            S1.pop();
        }
        stack<int> temp;
        while(!S2.empty())
        {
            if(S2.top()>='0'&&S2.top()<='9')
                {
                temp.push(S2.top()-'0');
                S2.pop();
                }
            else
            {
                int x=temp.top();
                temp.pop();
                int y=temp.top();
                temp.pop();
                switch(S2.top())
                {
                    case '+':x=x+y;temp.push(x);break;
                    case '-':x=x-y;temp.push(x);break;
                    case '*':x=x*y;temp.push(x);break;
                    case '/':x=x/y;temp.push(x);break;
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
    string test="(3+4)*5-6*3+9*(4+1)";
    stack<char> S;
    midtprix(test,S);
    cout<<ComputingPrefix(S);
}
