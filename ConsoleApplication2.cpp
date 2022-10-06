#include <iostream>
#include <string>
#include <cctype>
#define ""
using namespace std;

template<typename T>

class DynamicArrayStack 
{
private:
    T* stack;
    T* dummy;
    int top, max;
public:
    DynamicArrayStack()
    {
        stack = nullptr;
        dummy = nullptr;
        max = 0;
        top = -1;
    }
    ~DynamicArrayStack()
    {
        delete[] stack;
        delete[] dummy;
    }
    void pushStack(T value)
    {
        dummy = stack;
        stack = new T[max + 1];
        max += 1;
        top += 1;
        for (int i = 0; i < top; i++)
        {
            stack[i] = dummy[i];
        }
        stack[top] = value;
        delete[] dummy;
        
    }
    int popStack()
    {
        if (top = -1)
        {
            return 0;
        }
        max -= 1;
        top -= 1;
    }
    DynamicArrayStack(const DynamicArrayStack& st)
    {
        stack = new T[st.max];
        max = st.max;
        for (int i = 0; i < max; i++)
        {
            stack[i] = st.stack[i];
        }
    }
    DynamicArrayStack operator=(const DynamicArrayStack& st)
    {
        if (max > 0)
        {
            max = 0;
            delete[] stack;
        }
        stack = new T[st.max];
        max = st.max;
        for (int i = 0; i < max; i++)
        {
            stack[i] = st.stack[i];
        }
    }
    int countStack()
    {
        return max;
    }
    void printStack()
    {
        T* p;
        p = stack;
        cout << "Stack: " << endl;
        if (max == 0)
        {
            cout << "Empty" << endl;
        }
        for (int i = 0; i < max; i++)
        {
            cout << "Item["<< i <<"] = " << *p << " ";
            p++;
        }
        cout << endl;
    }
};

void rearrangeExpression(string &inBuff, string &outBuff, DynamicArrayStack <char> &stck)
{
    for (int i = 0; i < inBuff.length(); i++)
    {
        char c = inBuff[i];
        if (isdigit(c) == true)
        {
            outBuff += c;
        }
        else
        {
            stck.pushStack(c);
        }
    }
}

int main(int argc, char* argv[])
{
    DynamicArrayStack <char> stackOne;
    stackOne.printStack();
    stackOne.pushStack('+');
    stackOne.printStack();
    
}
;