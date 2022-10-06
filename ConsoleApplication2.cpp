#include <iostream>
#include <string>
#include <cctype>
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
        if (top == -1)
        {
            return 0;
        }
        else
        {
            max = max - 1;
            top = top - 1;
        }
        return 1;
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
    char lastStackElement()
    {
        return stack[top];
    }
};

int symbPriority(char symb)
{
    switch (symb)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void rearrangeExpression(string &inBuff, string &outBuff, DynamicArrayStack <char> &stck)
{   
    for (int i = 0; i < inBuff.length(); i++)
    {
        char c = inBuff[i];
        if (isdigit(c) != 0)
        {
            outBuff += c;
            outBuff += " ";
        }
        if (c == 's' || c == 'c')
        {
            stck.pushStack(c);
        }
        if (c == '(')
        {
            stck.pushStack(c);
        }
        if (c == ')')
        {
            while (stck.lastStackElement() != '(')
            {
                outBuff += stck.lastStackElement();
                outBuff += " ";
                stck.popStack();
            }
            stck.popStack();
        }
        if (symbPriority(c) != 0)
        {
            while (stck.lastStackElement() == 's' || stck.lastStackElement() == 'c' || symbPriority(stck.lastStackElement()) >= symbPriority(c))
            {
                
                outBuff += stck.lastStackElement();
                outBuff += " ";
                stck.popStack();
            }
            stck.pushStack(c);
        }
    }
    while (stck.countStack() != 0)
    {
        outBuff += stck.lastStackElement();
        outBuff += " ";
        stck.popStack();
    }
}   

// sin ( 2 ) + cos ( 5 ) * 2


int main(int argc, char* argv[])
{
    DynamicArrayStack <char> stackOne;
    string str = "s ( 2 ) + c ( 5 ) * 2 ^ 5";
    string outStr = "";
    rearrangeExpression(str, outStr, stackOne);
    cout << outStr << endl;
};