#include<iostream>
#include<random>
using namespace std;

template<class T>
class queue
{
private:
        int head;
        int tail;
        int length;
        int max_length;
        T data[10000];
public:
    queue()
    {
        head=tail=0;
        length=0;
        max_length=10000;
    }
    bool IsEmpty()
    {
        return length==0;
    }
    bool IsFull()
    {
        return length==max_length;
    }
    bool push(T x);
    T pop();
    void initial();
    void show();
};

template<class T>
bool queue<T>::push(T x)
{
    if(IsFull())
        return false;
    else
    {
        length++;
        data[tail]=x;
        tail=(tail+1)%10000;
    }
}

template<class T>
T queue<T>::pop() {
    if(IsEmpty())
        return INT32_MAX;
    else
    {
        length--;
        T temp=data[head];
        head=(head+1)%10000;
        return temp;
    }
}

template<class T>
void queue<T>::initial() {
    head=tail=0;
    length=0;
}

template<class T>
void queue<T>::show() {
    int temp=length;
    int TempHead=head;
    while(temp)
    {
        cout<<data[head]<<" ";
        head=(head+1)%10000;
        temp--;
    }
}

int main()
{
    queue<int> test;
    for(int i=0;i<1000;i++)
        test.push(rand()%1000);
    cout<<test.pop();
}