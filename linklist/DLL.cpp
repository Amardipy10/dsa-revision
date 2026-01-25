#include<iostream>
using namespace std;

class Node{
public:
    Node* next;
    Node* prev;
    int data;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DLL{
Node* head;
Node* tail;
public:
DLL(){
    head=tail=NULL;
}

void push_front(int val){
    Node* newNode= new Node(val);
    if(head==NULL){
        head=tail=newNode;
    }
    else{
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
}


void push_back(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
            tail=newNode;
        }
}


void push_back2(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
            
}
}


void pop_front(){
    if(head == NULL){
        return;
    }
    // single node case
    else if(head->next == NULL){
        delete head;
        head = tail = NULL;
    }
    else{
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
}

void pop_back(){
    if(tail == NULL){
        return;
    }
    // single node case
    else if(tail->prev == NULL){
        delete tail;
        head = tail = NULL;
    }
    else{
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
}

void print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" <=> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
};

int main(){
    DLL dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_back2(4);

    dll.print();

    return 0;
}