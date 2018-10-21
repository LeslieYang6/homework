
using namespace std;
template<class T>
class stack{
private:
    T data[1000];
    int length;
public:
    stack()
    {
        length=-1;
    }
    bool push(T x);
    T pop();
    bool IsEmpty();
};
template<class T>
bool stack<T>::push(T x)
{
    if(length==999)
        return 0;
    else
        data[++length]=x;
}

template<class T>
T stack<T>::pop()
{
    if(length>-1)
        return data[length--];
}

template<class T>
bool stack<T>::IsEmpty()
{
    if(length==-1)
        return 1;
    else
        return 0;
}