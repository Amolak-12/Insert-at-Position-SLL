#include <iostream>
using namespace std;

//Creating a class node as done in the earlier code
class Node{
  public:
    int data;
    Node* next;

    Node () {
     data = 0;
     next = NULL;
    }

    Node (int data) {
    this->data = data;
    next = NULL;
   }
};

//get Length function
int getLength(Node* head) {
  int len = 0;
  while(head != NULL) {
    head = head->next;
    len++;
  }
  return len;
}

//Insert at head
void insertatHead(Node* &head, int data) {
  //Step 1
  Node* newnode = new Node(data);
  //Step 2
  newnode -> next = head;
  //Step 3
  head = newnode;
}

//Insert at Tail
void insertatTail(Node* &tail , int data) {
  //Step 1
  Node* newnode = new Node(data);
  //Step 2
    tail -> next = newnode;
  //Step 3
  tail = newnode;

}

//Insert at Position
void insertatPos(Node* &head, Node* &tail, int pos, int data) {
  //Step 1 : Check empty 
  if(head == NULL) 
    return;
  //Step 2 : Check for the position
  if(pos == 1) {
    insertatHead(head, data);
    return;
  }
  else if(pos > getLength(head)) {
    insertatTail(tail, data);
    return;
  }
  //Step 3 : Insert at any position

    //subStep 1 : Find prev and curr
    Node* prev = head;
    Node* curr = head;
    int cnt = 1;
    while(cnt < pos-1) {
      prev = curr;
      curr = curr -> next;
      cnt++;
    }

    //subStep 2 : Create a new node
    Node* newnode = new Node(data);

    //subSTep 3 : newNode->next = ucrr;
    newnode -> next = curr;
  
    //subStep 4 : prev->next = newNode;
    prev -> next = newnode;
}


//Print function as use din previous code
void print ( Node* &head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << " ";
  temp = temp->next;
  }
  cout << endl;
}

int main() {
  //Making a node
  Node* first;
  //Created a node in heap memory
  first = new Node(10);

  Node* second;
  second = new Node(20);
  Node* third;
  third = new Node(30);
  Node* fourth;
  fourth = new Node(40);
  Node* fifth;
  fifth = new Node(50);

  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  
  print(first);

  insertatPos(first, fifth, 2, 100);
  print(first);
}