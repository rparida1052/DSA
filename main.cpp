#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(){
            this->data = 0;
            this->prev  =NULL;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

void addNode(){
    
}
void printNode(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int getLength(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }

    return length;
}
int main() {
    Node*  a = new Node(10);
    Node*  b = new Node(20);
    Node*  c = new Node(30);
    Node*  d = new Node(40);

    a->next = b;
    b->prev = a;

    b->next = c;
    c->prev = b;


    printNode(a);


    return 0;
}