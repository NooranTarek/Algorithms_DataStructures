#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T nodeData;
    Node<T>* pointerToNext;
    Node<T>* pointerToPrevious;

    Node()
    {
        nodeData = T();
        pointerToNext = nullptr;
        pointerToPrevious = nullptr;
    }

    Node(T data)
    {
        nodeData = data;
        pointerToNext = nullptr;
        pointerToPrevious = nullptr;
    }

    ~Node()
    {
    }
};

template <class T>
class doubleLinkedList
{
public:
    Node<T>* listHead;
    Node<T>* listTail;
    int linkedListCounter;

    doubleLinkedList()
    {
        listHead = nullptr;
        listTail = nullptr;
        linkedListCounter = 0;
    }
     doubleLinkedList(doubleLinkedList& original)
    {

        listHead = listTail = nullptr;
        linkedListCounter = 0;

        //start from the head of the original list
        Node<T>* ptr = original.listHead;

        while (ptr)
        {
            // Add a new node with the same data to the new list
            enqueue(ptr->nodeData);
            ptr = ptr->pointerToNext;
        }
    }

    void enqueue(T data)
    {
        Node<T>* ptr = new Node<T>(data);
        if (listTail == nullptr)
        {
            listTail = listHead = ptr;
        }
        else
        {
            ptr->pointerToPrevious = listTail;
            listTail->pointerToNext = ptr;
            listTail = ptr;
        }
        linkedListCounter++;
    }

    T dequeue()
    {
        if (listHead == nullptr)
        {
            cout<< "The list is empty; nothing to dequeue." << endl;
            //return T()
        }

        T dequeuedData = listHead->nodeData;
        Node<T>* temp = listHead;

        if (listHead->pointerToNext != nullptr)
        {
            listHead = listHead->pointerToNext;
            listHead->pointerToPrevious = nullptr;
        }
        else
        {
            listHead = listTail = nullptr;
        }

        delete temp;
        linkedListCounter--;

        return dequeuedData;
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
        listHead = listTail = nullptr;
        linkedListCounter = 0;
    }

    void displayList()
    {
        Node<T>* ptr = listHead;
        while (ptr)
        {
            cout << ptr->nodeData << " ";
            ptr = ptr->pointerToNext;
        }
        cout << "\n";
    }

    ~doubleLinkedList()
    {
        clearList();
    }
};

int main()
{
    doubleLinkedList<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout<<"the elements you enqueued are"<<endl;
    queue.displayList();
    queue.dequeue();
    queue.dequeue();
    cout<<"the elements you dequeued are"<<endl;
    queue.displayList();

    doubleLinkedList<int> copiedList(queue);
    cout << "copied list: ";
    cout << "\n";
    copiedList.displayList();


    return 0;
}
