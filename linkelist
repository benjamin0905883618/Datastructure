#include<iostream>
using namespace std;

struct Node{
  int data;
  Node *prev,*next;
  Node(int d,Node *p,Node *n) : data(d),prev(p),next(n){}

  void insertAfter(int datum){
    Node *temp = new Node(datum,this,this->next);
    temp->next->prev = temp;
    temp->prev->next = temp;
  }
  void insertBefore(int datum){
    Node *temp = new Node(datum,this->prev,this);
    temp->next->prev = temp;
    temp->prev->next = temp;
  }
  void remove(){
    this->next->prev = this->prev;
    this->prev->next = this->next;
    delete this;
  }
};

Node *head,*tail;
int main(){
  head = new Node(0,NULL,NULL);
  tail = new Node(0,head,NULL);
  head->next = tail;
  head->insertAfter(5);
  cout << head->next->data << endl;
}
