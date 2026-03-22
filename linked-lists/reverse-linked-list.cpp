//
//  main.cpp
//  reverse-linked-list
//
//  Created by Ahmet Bora Bakır on 3/22/26.
//

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr){}
};

class List
{
    Node* head;
    int size = 0;
public:
    List(): head(nullptr){}
    ~List()
    {
        Node* current = head;
        
        while(current != nullptr)
        {
            Node* temp = current;
            current = current -> next;
            delete temp;
        }
        size = 0;
        head = nullptr;
    }
    void reverse()
    {
        if(head == nullptr || head -> next == nullptr)
            return;
        
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while(current != nullptr)
        {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    void addLast(int data)
    {
        Node* temp = new Node(data);
        if(head == nullptr)
        {
            head = temp;
            size++;
            return;
        }
        Node* current = head;
        while(current -> next != nullptr)
            current = current -> next;
        current -> next = temp;
        size++;
    }
    
    void print()
    {
        Node* current = head;
        while(current != nullptr)
        {
            cout << current -> data << " ";
            current = current -> next;
        }
        
        cout << "NULL" << endl;
    }
};


int main()
{
    List intergerList;
    
    while(true)
    {
        int data;
        string exit;
        cout << "Input: ";
        cin >> data;
        
        intergerList.addLast(data);
        cout << "enter \"exit\" else otherwise: ";
        cin >> exit;
        
        if(exit == "EXIT" || exit == "exit")
            break;
    }
    
    cout << "Normal list: ";
    intergerList.print();
    
    
    intergerList.reverse();
    cout << "\nReversed list: ";
    intergerList.print();
}
