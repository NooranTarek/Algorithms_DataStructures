#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T nodeData;
    Node<T>* pointerToNext;

    Node()
    {
        nodeData = T();
        pointerToNext = nullptr;
    }

    Node(T data)
    {
        nodeData = data;
        pointerToNext = nullptr;
    }

    ~Node()
    {
    }
};

template <class T>
class singleLinkedList
{
public:
    Node<T>* listHead; // head
    int linkedListCounter;

    singleLinkedList()
    {
        listHead = nullptr;
        linkedListCounter = 0;
    }
    //copy constructor
     singleLinkedList(singleLinkedList &original)
    {
        listHead = nullptr;
        linkedListCounter = 0;
        Node<T>* ptr = original.listHead;

        while (ptr)
        {
            append(ptr->nodeData);
            ptr = ptr->pointerToNext;
        }//1  2  3  4
    }//1  2  3
    //___________________________________________________________
        void append(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (listHead == nullptr)
        {
            listHead = newNode;
        }
        else
        {
            Node<T>* current = listHead;
            while (current->pointerToNext != nullptr)
            {
                current = current->pointerToNext;
            }
            //append the new node to the end
            current->pointerToNext = newNode;
        }

        linkedListCounter++;
    }
    void clearList()
    {
        Node<T>* ptr = listHead;
        while (ptr != nullptr)
        {
            listHead = listHead->pointerToNext;
            delete ptr;
            ptr = listHead;
        }
        listHead = nullptr;
        linkedListCounter = 0;
    }

    void push(T data)
    {
        Node<T>* ptr = new Node<T>(data);
        ptr->pointerToNext = listHead;
        listHead = ptr;
        linkedListCounter++;
    }

    T pop()
    {
        if (listHead == nullptr)
        {
            cout << "Stack is empty, nothing to pop" << endl;
            //return a default value for the type T

        }

        T poppedData = listHead->nodeData;
        Node<T>* temp = listHead;
        listHead = listHead->pointerToNext;
        delete temp;
        linkedListCounter--;
        return poppedData;
    }

    void display()
    {
        Node<T>* current = listHead;
        while (current != nullptr)
        {
            cout << current->nodeData << " ";
            current = current->pointerToNext;
        }
        cout << endl;
    }

    ~singleLinkedList()
    {
        clearList();
    }
};

int main()
{
    singleLinkedList<int> stack1;
    singleLinkedList<int> stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack2.push(5);
    stack2.push(6);
    stack2.push(7);
//    stack1.append(stack2)
    cout << "The elements you pushed are:" << endl;
    stack1.display();
    stack1.pop();
    stack1.pop();
    cout << "The elements you popped are:" << endl;
    stack1.display();
    singleLinkedList<int> copiedList(stack1);
    cout << "copied list: ";
    cout << "\n";
    copiedList.display();
    return 0;
}
