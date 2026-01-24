#include<iostream>
using namespace std;
class Node{

public:
    int data;
    Node* next;


    Node(int value){
        data=value;
        next=NULL;
    }

};
class List{
Node* head;
Node* tail;
public:
List(){
    head=tail=NULL;
}

void push_front(int value){
    Node* newNode=new Node(value);
    if(head==NULL){
        head=tail=newNode;
        return;}
    else{
        newNode->next=head;
        head=newNode;
    }
};


void push_back(int value){
    Node* newNode=new Node(value);
    if(head==NULL){
        head=tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

void pop_front(){
    if(head==NULL){
        cout<<"LL is empty \n";
        return;
    }
    else{
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
}

void pop_back(){
    if(head==NULL){
        cout<<"LL is empty \n";
        return;
    }
    else{
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
}


void insert(int value,int pos){
    if(pos<0){
        cout<<"Invalid Position \n";
    }
    if(pos==0){
        push_front(value);
        return;
    }
    else{
        Node* temp=head;
        for (int i = 0; i < pos-1; i++)
        {
            if(temp==NULL){
                cout<<"Invalid pos\n";
                return;
            }
            temp=temp->next;
        }

        Node* newNode=new Node(value);
        newNode->next=temp->next;
        temp->next=newNode;
    }

}


int search(int key){
    Node* temp=head;
    int i=0;
    while(temp!=NULL){
        if(temp->data==key){
            return i;
        }
        temp=temp->next;
        i++;

    }
    return -1;
}

void printLL(){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.insert(4,1);

    ll.printLL();
    cout<<ll.search(4)<<endl;

    return 0;
}