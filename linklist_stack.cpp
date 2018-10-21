#include <iostream>

using namespace std;


template<class T>
class stack
{
private:
    struct node
    {
        T key;
        node *next;
    }*head;
public:
    stack()
    {
        head=new node;
        head->next= nullptr;
    }

    void push(T x)
    {
        node *temp=new node;
        temp->key=x;
        temp->next=head->next;
        head->next=temp;
    }
    T pop()
    {
        if(!head->next)
            cerr<<"can't pop because of emptiness";
        else
        {
            node *Temp=head->next;
            T TempKey=Temp->key;
            head->next=Temp->next;
            delete Temp;
            return TempKey;
        }
    }

    bool IsEmpty()
    {
        if(!head->next)
            return true;
        else return false;
    }


};