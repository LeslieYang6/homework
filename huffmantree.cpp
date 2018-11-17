#include<queue>
#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int weight;
    Node *lChild,*rChild;
    Node()
    {
        lChild= nullptr ;
        rChild= nullptr;
        weight=0;
    }
};

struct cmp
{
    bool operator()(Node &a,Node &b) {
        if (a.weight == b.weight)
            return true;
        else
            return a.weight > b.weight;
    }
};

Node GetHuffmanTree(Node root[],int length)
{
    if(length==1)
        return root[0];
    priority_queue<Node,vector<Node>,cmp> p;
    for(int i=0;i<length;i++)
        p.push(root[i]);
    while(length!=1)
    {
        Node temp1=p.top();
        p.pop();
        Node temp2=p.top();
        p.pop();
        length--;
        Node parent;
        parent.lChild=parent.rChild=new Node;
        parent.rChild=new Node;
        parent.lChild=new Node;
        *parent.lChild=temp1;
        *parent.rChild=temp2;
        parent.weight=parent.lChild->weight+parent.rChild->weight;
        p.push(parent);
    }
    return p.top();
}

int main()
{
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    Node root[6];
    for(int i=0;i<6;i++)
        root[i].weight=freq[i];
    Node HfTree=GetHuffmanTree(root,6);
    return 0;
}

