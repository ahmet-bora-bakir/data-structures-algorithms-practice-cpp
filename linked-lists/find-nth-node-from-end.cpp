//
//  main.cpp
//  find-nth-node-from-end
//
//  Created by Ahmet Bora Bakır on 3/22/26.
//

/*Find the n-th Node from the End

 Goal: Find the n-th node from the end of the list in a single pass.

 Constraint: You are not allowed to calculate the total length of the list first. (Hint: Use two pointers with a gap of n).*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data): data(data), next(nullptr){}
};

class List
{
    Node* head;
    
public:
    List(): head(nullptr){}
    ~List()
    {
        Node* current = head;
        while(current != nullptr)
        {
            Node* temp = current -> next;
            delete current;
            current = temp;
        }
        if(head != nullptr)
            head = nullptr;
    }
    void destroy_nth(int n)
    {
        if(n <= 0)
            return;
        int counter = 0;
        Node* w1 = head;
        Node* w2 = head;       //far from w1
        
        while(counter != n)
        {                                           // 1 2 3 4 5 null
            w2 = w2 -> next;
            counter++;
            if(w2 == nullptr)
                break;
        }
        if(w2 == nullptr && counter == n)
        {
            Node* temp = head -> next;
            delete head;
            head = temp;
            return;
        }
        else if(counter != n) return;
        while(w2 -> next != nullptr)
        {
            w1 = w1 -> next;
            w2 = w2 -> next;
        }
        Node* temp = w1 -> next;
        w1 -> next = w1 -> next -> next;
        delete temp;
    }
    
    void push(int data)
    {
        if(head == nullptr)
        {
            head = new Node(data);
            return;
        }
        Node* current = head;
        while(current -> next != nullptr)
            current = current -> next;
        current -> next = new Node(data);
    }
    void print()
    {
        Node* current = head;
        
        while(current != nullptr)
        {
            cout << current << " ";
            current = current -> next;
        }
        cout << "NULL" << endl;
    }
};


int main()
{
    List list;
    
    while(true)
    {
        int input;
        cout << "Input: ";
        cin >> input;
        
        list.push(input);
        
        string exit;
        
        cout << "Enter e/E/exit/EXIT to exit else otherwise: ";
        cin >> exit;
        
        if(exit == "e" || exit == "E" || exit == "exit" || exit == "EXIT")
            break;
    }
    
    while(true)
    {
        int n;
        cout << "Input the n-th node from the end of the list: ";
        cin >> n;
         
        list.destroy_nth(n);
        cout << "New list: " << endl;
        list.print();
        string exit;
        
        cout << "Enter e/E/exit/EXIT to exit else otherwise: ";
        cin >> exit;
        
        if(exit == "e" || exit == "E" || exit == "exit" || exit == "EXIT")
            break;
    }
}
