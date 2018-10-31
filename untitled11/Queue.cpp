//
// Created by leslie on 18-10-29.
//

#include"Bag.h"
#include<iostream>
using namespace std;



bool Queue::Add(int x) {
    if(IsFull())
        return false;
    else
    {
        length++;
        data[tail]=x;
        tail=(tail+1)%10000;
    }
}

void Queue::Remove() {
    if(IsEmpty())
        return;
    else
    {
        length--;
        head=(head+1)%10000;
        return;
    }
}

int Queue::Get()
{
    if(IsEmpty())
    {
        cerr<<"no elements in the queue";
        return -1;
    }
    else
    {
        return data[head];
    }

}