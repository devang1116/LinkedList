//
//  main.cpp
//  LinkedList
//
//  Created by Devang Papinwar on 09/05/23.
//

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int val)
    {
        this->data = val;
    }
};

class LinkedList
{
public:
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
    
    int getSize()
    {
        Node* temp = head;
        int size = 0;
        
        while(temp->next != NULL)
        {
            size++;
            temp = temp->next;
        }
        
        return size;
    }
    void display()
    {
        Node* temp = head;
        
        cout << endl << "Size : " << getSize() << endl;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
    void insertAtStart(int data)
    {
        Node* newNode = new Node(data);
        
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        
        newNode->next = head;
        head = newNode;
    }
    
    void insertAtLoc(int data , int loc)
    {
        int size = getSize();
        
        if(loc < 0 || loc > size)
            return;
        
        if(loc == size)
            insertAtEnd(data);
        
        if(loc == 0)
            insertAtStart(data);
        
        Node* newNode = new Node(data);
        int length = 0;
        Node* temp = head;
        
        while(temp->next != NULL && length != loc - 1)
        {
            temp = temp->next;
            length++;
        }
        
        Node* nextNext = temp->next;
        
        temp->next = newNode;
        newNode->next = nextNext;
    }
    
    void insertAtEnd(int data)
    {
        Node* newNode = new Node(data);
        
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = newNode;
    }
    
    void deleteAtStart()
    {
        int size = getSize();
        
        if(size <= 1)
            head = NULL;
        else
        {
            head = head->next;
        }
    }
    
    void deleteAtEnd()
    {
        int size = getSize();
        
        if(size <= 1)
            deleteAtStart();
        
        Node* temp = head;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = NULL;
    }
    
    void deleteAtLoc(int loc)
    {
        int size = getSize();
        
        if(size <= 1)
        {
            deleteAtStart();
            return;
        }
        if(loc == size)
        {
            deleteAtEnd();
            return;
        }
        
        Node* temp = head;
        int length = 0;
        
        while(temp->next->next != NULL && length != loc - 1)
        {
            length++;
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
    }
};



int main(int argc, const char * argv[])
{
    LinkedList list ;
    
    list.insertAtStart(4);
    list.insertAtStart(2);
    list.insertAtStart(1);
    list.insertAtEnd(5);
    list.insertAtLoc(3, 2);
    list.display();
    
    list.deleteAtStart();
    list.deleteAtEnd();
    list.deleteAtLoc(1);
    list.display();
    return 0;
}
