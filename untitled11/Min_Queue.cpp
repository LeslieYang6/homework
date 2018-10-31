//
// Created by leslie on 18-10-29.
//
#include"Bag.h"
#include<math.h>
#include<iostream>
using namespace std;



void Min_Queue::heapfy(int i) {
    int left=Left_Child(i);
    int right=Right_Child(i);
    int min=i;
    if(size>=left&&data[left]<data[min])
        min=left;
    if(size>=right&&data[right]<data[min])
        min=right;
    if(min==i)
        return;
    else
    {
        swap(data[i],data[min]);
        heapfy(min);
    }
}

void Min_Queue::Remove() {
    if(size==0)
        return;
    if(size==1)
    {
        size--;
        return;
    }
    data[1]=data[size--];
    heapfy(1);
}

int Min_Queue::Get()
{
    return data[1];
}

bool Min_Queue::Add(int x)
{
    if(size==1023)
        return false;
    else
    {
        data[++size]=x;
        int i=size;

        while(i!=1&&data[i]<data[Parent(i)])
        {
            swap(data[i],data[Parent(i)]);
            i=Parent(i);
        }
        return true;
    }
}


