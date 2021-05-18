//
//  main.cpp
//  list1
//
//  Created by Devang Papinwar on 18/02/21.
//

#include <iostream>
using namespace std;

struct Person
{
    int data;
    Person* next;
};

void display( Person* head )
{
    cout << "\nDisplaying Information : " << endl ;
    int counter = 0;
    while(head != NULL)
    {
        counter++;
        cout << "Data " << counter << " : " << head->data << " - > ";
        head = head->next;
    }
    cout << endl;
}

void search(Person* p1)
{
    int data;
    cout << "Enter the Data : ";
    cin >> data;
    Person* head = p1;
    int counter = 1;
    while(head->next != NULL)
    {
        if(head->data == data)
        {
            cout << " DATA : " << head->data << " Counter : " << counter << endl;
        }
        head = head->next;
        counter++;
    }
}

void insertAtBeg(Person** head)
{
    struct Person* new_node = (struct Person*) malloc(sizeof(struct Person));
    cout << "Enter Data : ";
    cin >> new_node->data;
    new_node->next = *head;
    *head = new_node;
}

void insertInMiddle(Person* head,int loc)
{
    struct Person* new_node = (struct Person*) malloc(sizeof(struct Person));
    Person* temp = new Person();
    Person* tem = head;
    cout << "Enter Data : ";
    cin >> new_node->data;
    for(int i=0; i<=loc-1 ; i++)
    {
        tem = head;
        temp = tem->next;
        head = head->next;
    }
    new_node->next = temp;
    tem->next = new_node;
}

void insertAtEnd(Person* head)
{
    struct Person* new_node = (struct Person*) malloc(sizeof(struct Person));
    cout << "Enter Data : ";
    cin >> new_node->data;
    new_node->next = NULL;
    Person* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void deleteInBeg(Person** head)
{
    struct Person* temp = (struct Person*) malloc(sizeof(struct Person));
    temp = *head;
    *head = temp->next;
}

void deleteFromMiddle(Person* head,int loc)
{
    struct Person* new_node = (struct Person*) malloc(sizeof(struct Person));
    Person* temp = new Person();
    Person* tem = new Person();
    for(int i=0; i<=loc-1 ; i++)
    {
        tem = head;
        temp = tem->next;
        head = head->next;
    }
    new_node = temp->next;
    tem->next = new_node;
    temp->next = NULL;
}

void deleteFromBack(Person* head)
{
    while(head->next->next != NULL)
    {
        head = head->next;
    }
    head->next = NULL;
}

Person* reverse(Person* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Person* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main(int argc, const char * argv[])
{
    Person* p1 = new Person();
    Person* p2 = new Person();
    Person* p3 = new Person();
    Person* head = new Person();
    
    p1->data = 10;
    p2->data = 20;
    p3->data = 30;
    
    head = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;
    
    insertAtBeg(&head);
    insertAtEnd(head);
    //insertInMid(head,1);
    //deleteInBeg(&head);
    //deleteFromBack(head);
    //deleteFromMiddle(head, 1);
    //head = reverse(head);
    display(head);
    //search(head);
}
