#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = 5)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push element.\n";
            return;
        }
        arr[++top] = value;
        cout << "Element " << value << " pushed to stack.\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop element.\n";
            return -1;
        }
        cout << "Element " << arr[top] << " popped from stack.\n";
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[top];
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack stack1;

    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);

    stack1.print();

    cout << "Top element: " << stack1.peek() << endl;

    stack1.pop();
    stack1.pop();

    stack1.print();

    return 0;
}