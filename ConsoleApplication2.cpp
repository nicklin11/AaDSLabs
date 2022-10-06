#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

template<typename T>
class DynamicArr
{
    T* dummy;
    T* arr;
    int size;
public:
    DynamicArr()
    {
        dummy = nullptr;
        arr = nullptr;
        size = 0;
    }
    ~DynamicArr()
    {
        delete[] arr;
    }
    DynamicArr(const DynamicArr& dynArr)
    {
        arr = new T[dynArr.size];
        size = dynArr.size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = dynArr.arr[i];
        }
    }
    DynamicArr operator=(const DynamicArr& dynArr)
    {
        if (size > 0)
        {
            delete[] arr;
        }
        arr = new T[dynArr.size];
        size = dynArr.size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = dynArr.arr[i];
        }
    }
    void appendToArr(T item)
    {
        dummy = arr;
        size += 1;
        arr = new T[size];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = dummy[i];
        }
        arr[size - 1] = item;
        delete[] dummy;
    }
    int removeTopElFromArr()
    {
        if (size == 0)
        {
            return 1;
        }
        dummy = arr;
        size -= 1;
        arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = dummy[i];
        }
        delete[] dummy;
        return 0;
    }
    int sizeOfArr()
    {
        return size;
    }
    T returnLastElement()
    {
        return arr[size - 1];
    }
};



template<typename T>
class DynamicArrayStack 
{
private:
    DynamicArr <T> stack;
    int top, max;
public:
    DynamicArrayStack()
    {
        max = stack.sizeOfArr();
        top = stack.sizeOfArr() - 1;
    }
    void pushStack(T value)
    {
        stack.appendToArr(value);
        max += 1;
        top += 1;
    }
    int popStack()
    {
        if (top == -1)
        {
            return 0;
        }
        else
        {
            stack.removeTopElFromArr();
            max = max - 1;
            top = top - 1;
        }
        return 1;
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
    T lastStackElement()
    {
        return stack.returnLastElement();
    }
};

template <class T>
class Node
{
public:
    Node<T>* next;
    Node<T>* head;
    T data;
};
template <class T>
class List
{
public:
    Node<T>* head;
    Node<T>* next;

    List()
    {
        head = nullptr;
        next = nullptr;
    }

    List(T d)
    {
        Node<T>* temp = new Node<T>();
        temp->data = d;
        temp->next = NULL;
        temp->head = NULL;
    };


    void listAdd(T& d)
    { 
        Node<T>* temp = new Node<T>();
        temp->data = d;
        temp->next = head;
        head = temp;
    }

    void getList()
    {
        Node<T>* ok = head;
        while (ok != NULL)
        {
            std::cout << ok->data;
            ok = ok->next;
        }
    }


    void clearList()
    {  
        Node<T>* tmp = head;
        while (tmp != NULL)
        {
            Node<T>* temp = tmp->next;
            delete temp->head;
            head = temp;

        }

    }


    T getLast()
    { 
        Node<T>* current = head;
        return current->data;
    }

    void pop()
    { 
        Node<T>* temp = head;
        head = temp->next;
        delete temp;
    }

    int size()
    {
        int counter = 0;
        Node<T>* temp = head;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool empty()
    { 
        if (head == NULL)
        {
            return true;
        }
        return false;

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

string reductStr(string str)
{
    while (str.find("sin") != string::npos)
    {
        str.replace(str.find("sin"), 3, "s");
    }
    while (str.find("cos") != string::npos)
    {
        str.replace(str.find("cos"), 3, "c");
    }
    return str;
}

void rearrangeExpression(string &inBuff, string &outBuff, List <char> &stck)
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
            stck.listAdd(c);
        }
        if (c == '(')
        {
            stck.listAdd(c);
        }
        if (c == ')')
        {
            while (stck.getLast() != '(')
            {
                outBuff += stck.getLast();
                outBuff += " ";
                stck.pop();
            }
            stck.pop();
        }
        if (symbPriority(c) != 0)
        {
            while (stck.getLast() == 's' || stck.getLast() == 'c' || symbPriority(stck.getLast()) >= symbPriority(c))
            {
                if (stck.getLast() == 's')
                {
                    outBuff += stck.getLast();
                    outBuff += "in ";
                    stck.pop();
                    break;
                }
                if (stck.getLast() == 'c')
                {
                    outBuff += stck.getLast();
                    outBuff += "os ";
                    stck.pop();
                    break;
                }
                outBuff += stck.getLast();
                outBuff += " ";
                stck.pop();
            }
            stck.listAdd(c);
        }
    }
    while (stck.size() != 0)
    {
        if (stck.getLast() == 's')
        {
            outBuff += stck.getLast();
            outBuff += "in ";
            stck.pop();
            break;
        }
        if (stck.getLast() == 'c')
        {
            outBuff += stck.getLast();
            outBuff += "os ";
            stck.pop();
            break;
        }
        outBuff += stck.getLast();
        outBuff += " ";
        stck.pop();
    }
}  


void rearrangeExpression(string& inBuff, string& outBuff, DynamicArrayStack <char> &stck)
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
                if (stck.lastStackElement() == 's')
                {
                    outBuff += stck.lastStackElement();
                    outBuff += "in ";
                    stck.popStack();
                    break;
                }
                if (stck.lastStackElement() == 'c')
                {
                    outBuff += stck.lastStackElement();
                    outBuff += "os ";
                    stck.popStack();
                    break;
                }
                outBuff += stck.lastStackElement();
                outBuff += " ";
                stck.popStack();
            }
            stck.pushStack(c);
        }
    }
    while (stck.countStack() != 0)
    {
        if (stck.lastStackElement() == 's')
        {
            outBuff += stck.lastStackElement();
            outBuff += "in ";
            stck.popStack();
            break;
        }
        if (stck.lastStackElement() == 'c')
        {
            outBuff += stck.lastStackElement();
            outBuff += "os ";
            stck.popStack();
            break;
        }
        outBuff += stck.lastStackElement();
        outBuff += " ";
        stck.popStack();
    }
}


void testProgram()
{
    DynamicArrayStack <char> testStackOne;
    List <char> testStackTwo;
    string testStr = "sin ( 2 ) + cos ( 5 ) * 2";
    string compareStr = "2 sin 5 cos 2 * + ";
    testStr = reductStr(testStr);
    string testOutStr1, testOutStr2 = "";
    rearrangeExpression(testStr, testOutStr1, testStackOne);
    rearrangeExpression(testStr, testOutStr2, testStackTwo);
    assert(testOutStr1.compare(compareStr) == 0);
    assert(testOutStr2.compare(compareStr) == 0);
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    testProgram();
    DynamicArrayStack <char> stackOne;
    List <char> stackTwo;
    cout << "Введите выражение (каждый символ через пробел, за исключением sin и cos):" << endl;
    string inStr;
    string outStr;
    getline(cin, inStr);
    inStr = reductStr(inStr);
    inStr += " ";
    for (int i = 0; i < inStr.size()-1; i++)
    {
        if (inStr[i] != ' ' && inStr[i + 1] != ' ')
        {
            cout << "Неправильный ввод данных, проверьте корректность" << endl;
            return 1;
        }
    }
    int cse;
    cout << "Выберете с чем вы хотите работать:\n1. Односвязный список\n2. Динамический массив\n(выбор цифрой)" << endl; 
    cin >> cse;
    switch (cse)
    {
    case 1:
        rearrangeExpression(inStr, outStr, stackTwo);
        break;
    case 2:
        rearrangeExpression(inStr, outStr, stackOne);
        break;
    default:
        outStr = "Ошибка.";
        break;
    }
    cout << "Обратная польская запись:" << endl;
    cout << outStr;
    return 0;
};
