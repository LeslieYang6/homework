//
// Created by leslie on 18-10-29.
//

#ifndef UNTITLED11_BAG_H
#define UNTITLED11_BAG_H
#include<iostream>
class Bag
{
public:
    virtual bool Add(int x)=0;
    virtual void Remove()=0;  //栈和链表的pop
    virtual int Get()=0;//返回栈和队列的ｔｏｐ元素
    virtual void MakeEmpty()=0;
    virtual bool IsEmpty()=0;
    virtual bool IsFull()=0;
    virtual int GetLength()=0;
};

class Queue:public Bag
{
private:
    int head;
    int tail;
    int length;
    int max_length;
    int data[10000];
public:
    Queue()
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
    void  MakeEmpty()
    {
        head=tail=0;
        length=0;
    }
    int GetLength()
    {
        return length;
    }
    bool Add(int x);
    void Remove();
    int Get();

};



class Stack:public Bag
{
private:
    int data[1000];
    int length;
public:
    Stack()
    {
        length=-1;
    }
    bool Add(int x);
    void Remove();
    int Get();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    int GetLength()
    {
        return length;
    }
};



class Min_Queue:public Bag{
private:
    int Left_Child(int i)
    {
        return 2*i;
    }
    int Right_Child(int i)
    {
        return 2*i+1;
    }
    int Parent(int i)
    {
        return i/2;
    }
    void heapfy(int i);
    int size;
    int data[1024];
public:
    Min_Queue()
    {
        size=0;
        for(int i=0;i<1025;i++)
            data[i]=INT32_MAX;
    }
    bool IsEmpty()
    {
        return size==0;
    }
    bool IsFull()
    {
        return size==1023;
    }
    void MakeEmpty()
    {
        size=0;
    }
    int GetLength()
    {
        return size;
    }

    void Remove();
    bool Add(int x);
    int Get();
};
#endif //UNTITLED11_BAG_H
