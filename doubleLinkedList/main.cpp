#include <iostream>
//______________________________________________________________________________________________
using namespace std;
template <class T>
//______________________________________________________________________________________________
// node class then contains data and the two pointers (next , previous)
class Node
{
public:
    T nodeData;
    Node <T> *pointerToNext;
    Node <T> *pointerToPrevious;

    //default with empty data and null previous and next
    Node()
    {
        nodeData=T();
        pointerToNext=nullptr;
        pointerToPrevious=nullptr;
    }
    //this constructor to fill node data with data
    Node(T dataOfNode)
    {
        nodeData=dataOfNode;
        pointerToNext=nullptr;
        pointerToPrevious=nullptr;
    }

    ~Node<T> ()
    {

    }
};
//______________________________________________________________________________________________
template <class T>
class doubleLinkedList
{
public:
    Node <T> *listHead;
    Node <T> *listTail;
    int nodesInListCount =0;
    //default constructor
    doubleLinkedList()
    {
        listHead=nullptr;
        listTail=nullptr;
        nodesInListCount=0;
    }
    //______________________________________________________________________________________________
    //copy constructor to copy the original list
    doubleLinkedList(const doubleLinkedList& original)
    {

        listHead = listTail = nullptr;
        nodesInListCount = 0;

        //start from the head of the original list
        Node<T>* ptr = original.listHead;

        while (ptr)
        {
            // Add a new node with the same data to the new list
            addNodeEnd(ptr->nodeData);
            ptr = ptr->pointerToNext;
        }
    }
    //______________________________________________________________________________________________
    //add new node at the first
    void addNodeFirst (T nodeData)
    {

        Node<T> *newNode=new Node<T> (nodeData);
        if (listHead==nullptr)
        {
            listHead=listTail=newNode;
        }
        //update pointers and set the new node as the head
        else
        {
            newNode->pointerToNext=listHead;
            listHead->pointerToPrevious=newNode;
            listHead=newNode;
        }
        nodesInListCount ++;
    }
    //______________________________________________________________________________________________
    //add new node at the end
    void addNodeEnd(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if (listTail==nullptr)
        {
            listHead = listTail = newNode;
        }
        else
        {
            //update pointers and set the new node as the tail
            newNode->pointerToPrevious = listTail;
            listTail->pointerToNext = newNode;
            listTail = newNode;
        }

        nodesInListCount ++;
    }
    //______________________________________________________________________________________________
    //display
    void displayList()
    {
        //to point to the head of the list i made to start print data
        Node<T> *ptr = listHead;
        while (ptr)
        {
            // print the data in each node
            cout << ptr->nodeData << " ";
            ptr = ptr->pointerToNext;
            cout << "\n";
        }

    }
    //______________________________________________________________________________________________
    //search return position
    int searchNode(T data)
    {
        Node<T>* ptr = listHead;
        int positionNumber = 1;

        while (ptr)
        {
            if (ptr->nodeData == data)
            {
                return positionNumber;
            }

            ptr = ptr->pointerToNext;
            positionNumber++;
        }
        return -1;
    }
    //______________________________________________________________________________________________
    //search return value
    Node<T>* search(T data)
    {
        Node<T>* ptr = listHead;

        while (ptr)
        {
            if (ptr->nodeData == data)
            {
                return ptr;
            }

            ptr = ptr->pointerToNext;
        }

        return nullptr;
    }
    //______________________________________________________________________________________________
    //delete
    void deleteNode(T data)
    {
        Node<T> *ptr = search(data);
        if (ptr == nullptr)
        {
            cout << "sorry this node is not exist"<<endl;
        }
        else
        {
            //node is head and at the same time is tails
            if (ptr == listHead&&ptr==listTail)
            {
                delete ptr;
                listHead = nullptr;
                listTail = nullptr;
            }//node is the head
            else if (ptr == listHead&&ptr!=listTail)
            {
                listHead = listHead->pointerToNext;
                listHead->pointerToPrevious = nullptr;
                delete ptr;
            }//node is the tail
            else
            {
                if (ptr == listTail)
                {
                    listTail = listTail->pointerToPrevious;
                    listTail->pointerToNext = nullptr;
                    delete ptr;
                }//node is not tail or head
                else
                {
                    ptr->pointerToPrevious->pointerToNext = ptr->pointerToNext;
                    ptr->pointerToNext->pointerToPrevious = ptr->pointerToPrevious;
                    delete ptr;
                }
            }
            nodesInListCount--;
        }
    }
    //______________________________________________________________________________________________
    //clear list
    void clearList()
    {
        Node<T> *ptr =listHead;
        while(ptr!=nullptr)
        {
            listHead=listHead->pointerToNext;
            delete ptr;
            ptr=listHead;
        }
        listHead=listTail=nullptr;
        nodesInListCount=0;
    }
    ~doubleLinkedList<T> ()
    {
        clearList();
    }
};
//______________________________________________________________________________________________
int main()
{
    doubleLinkedList<int> listOfIntegers;
    listOfIntegers.addNodeEnd(30);
    listOfIntegers.addNodeEnd(10);
    listOfIntegers.addNodeEnd(50);
    //______________________________________________________________________________________________
    //display
    cout << "your double list contains: ";
    cout << "\n";
    listOfIntegers.displayList();
    cout<<"______________________________________";
    cout << "\n";
    //______________________________________________________________________________________________
    // Copy constructor to create a new list
    doubleLinkedList<int> copiedList(listOfIntegers);
    cout << "copied list: ";
    cout << "\n";
    copiedList.displayList();
    cout<<"______________________________________";
    cout << "\n";
    //______________________________________________________________________________________________
    //search
    cout<<"please enter a value to search about"<<endl;
    int searchValue;
    cin>>searchValue;
    int searchedValuePosition = listOfIntegers.searchNode(searchValue);
    if (searchedValuePosition != -1)
    {
        cout <<"value =>"<< searchValue << " exist in " << searchedValuePosition << endl;
    }
    else
    {
        cout <<"value"<< searchValue <<"not exist"<< endl;
    }
    cout<<"______________________________________";
    cout << "\n";
    //______________________________________________________________________________________________
    //delete
    int deleteValue;
    cout << "enter a value to delete: ";
    cin >> deleteValue;
    listOfIntegers.deleteNode(deleteValue);
    cout<<"list after deleting node: ";
    listOfIntegers.displayList();
    cout<<"______________________________________";
    cout << "\n";
    //______________________________________________________________________________________________
    //clearing the list
    listOfIntegers.clearList();
    cout << "List after clearing: ";
    listOfIntegers.displayList();
    cout << "\n";


    return 0;
}

