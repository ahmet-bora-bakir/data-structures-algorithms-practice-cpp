//
//  main.cpp
//  Cycle Detection and Entrance Point (Linked List)
//
//  Created by Ahmet Bora Bakır on 3/21/26.
//

/* Cycle Detection and Entrance Point
 
 Goal: Detect if a cycle exists in a Singly Linked List using Floyd’s Cycle-Finding Algorithm (Tortoise and Hare).

 Requirement: If a cycle is detected, return the specific node where the cycle begins. If no cycle exists, return NULL.
 */
#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int data) : data(data), next(nullptr){}
};

class Floyd
{
    Node* head;
    int size;
public:
    int getSize()const {return size;}
    Node* getHead()const{return head;}
    
    void setHead(Node* head){this -> head = head;}
    void setSize(int size){this -> size = size;}
    Floyd(): head(nullptr), size(0){}
    ~Floyd()
    {
        Node* current = head;
        while(current != nullptr)
        {
            Node* next = current -> next;
            delete current;
            current = next;
            size--;
        }
        head = nullptr;
    }
    Node* createNode(int data){return new Node(data);}
    void insertFront(int data)
    {
        Node* temp = head;
        head = new Node(data);
        head -> next = temp;
        size++;
    }
    void insertBack(int data)
    {
        if (head == nullptr)
        {
            insertFront(data);
            return;
        }
        
        Node* current = head;
        while(current -> next != nullptr)
            current = current -> next;
        current -> next = new Node(data);
        size++;
    }
    
    void deleteValue(int data)
    {
        Node* current = head;
        
        if(head == nullptr)
            return;
        
        if(head -> data == data)
        {
            Node* temp = current -> next;
            delete head;
            head = temp;
            size--;
            return;
        }
        while(current -> next != nullptr)
        {
            if(current -> next -> data == data)
            {
                Node* temp = current -> next;
                current -> next = current -> next -> next;
                delete temp;
                size--;
                return;
            }
            current = current -> next;
        }
    }
    
    void printList()
    {
        Node* current = head;
        while(current != nullptr)
        {
            cout << current -> data << " ";
            current = current -> next;
        }
        cout << "NULL" << endl;
    }
    
    Node* cycle()
    {
        if(head == nullptr)
            return nullptr;
        Node* slow = head;
        Node* fast = head;
        bool flag = false;
        while(fast != nullptr && fast -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow)
            {
                flag = true;
                break;
            }
        }
        if(!flag) return nullptr;
        slow = head;
        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
    
};

int main() {
    Floyd list;

    cout << "--- Basic Operations Test ---" << endl;
    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertFront(5);
    
    cout << "Current List: ";
    list.printList();

    cout << "Deleting value 20." << endl;
    list.deleteValue(20);
    list.printList();

    cout << "Deleting head(5)." << endl;
    list.deleteValue(5);
    list.printList();
    
    cout << "\n--- Cycle Detection Test ---" << endl;
    list.insertBack(40);
    list.insertBack(50);
    // Current state: 10 -> 30 -> 40 -> 50 -> NULL
    
    cout << "Is there a cycle? " << (list.cycle() ? "Yes" : "No") << endl;

    Node* head = list.getHead();
    Node* nodeSecond = head->next;          // The node with value 30
    Node* nodeLast = head->next->next->next; // The node with value 50
    
    nodeLast -> next = nodeSecond;

    cout << "Is there any circle? " << (list.cycle() ? "Yes" : "No") << endl;

    // --- Safe Cleanup ---
    // CRITICAL: We must break the cycle manually before the program ends,
    // otherwise the destructor will fall into an infinite loop.
    nodeLast->next = nullptr;
    cout << "\nCycle broken safely. Destructor will now clean up memory." << endl;

    return 0;
}
