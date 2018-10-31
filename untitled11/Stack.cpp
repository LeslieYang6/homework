//
// Created by leslie on 18-10-29.
//
#include"Bag.h"
#include<iostream>
using namespace std;



bool Stack::Add(int x) {
    if(length==999)
        return false;
    else
        data[++length]=x;
    return true;
}

void Stack::Remove() {
    if(length>-1)
        length--;
}

int Stack::Get()
{
    if(length>=0)
        return data[length];
    else
    {
        cerr<<"no elements in the stack";
        return -1;
    }
}

void Stack::MakeEmpty() {
    length=-1;
}


bool Stack::IsEmpty() {
    return length==-1;
}

bool Stack::IsFull()
{
    return length==999;
}





