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

class Queue{
public:
    Queue(){
        head = new Node(0,NULL,NULL);
        tail = new Node(0,head,NULL);
        head->next = tail;
    }
    void push(int data){tail->insertBefore(data);}
    int top(){return head->next->data;}
    void pop(){head->next->remove();}
    bool empty(){return head->next == tail;}
    void clear(){
        while(!empty())
            pop();
    }
protected:
    Node *head,*tail;
};
Node *head,*tail;
int main(){
    Queue q;
    int n;
    while(cin >> n){
        for(int i = 0;i < n;i++){
            int num;
            cin >> num;
            q.push(num);
        }
        for(int i = 0;i < n;i++){
            cout << q.top() << " ";
            q.pop();
        }
        cout << endl;
    }
}
