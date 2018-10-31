#include"Bag.h"
#include<iostream>
#include<random>
using namespace std;

int main()
{
    Min_Queue p;
    for(int i=0;i<20;i++)
        p.Add(rand()%100);
    for(int i=0;i<20;i++)
    {
        cout<<p.Get()<<" ";
        p.Remove();
    }
    cout<<endl;
    Stack demo;
    for(int i=0;i<20;i++)
        demo.Add(i);
    for(int i=0;i<20;i++)
    {
        cout<<demo.Get()<<" ";
        demo.Remove();
    }
    cout<<endl;

    Queue T;
    for(int i=0;i<20;i++)
        T.Add(i);
    for(int i=0;i<20;i++)
    {
        cout<<T.Get()<<" ";
        T.Remove();
    }




}