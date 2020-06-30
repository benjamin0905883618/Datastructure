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
//假設數字越大優先序越高
class PriorityQueue{
public:
    PriorityQueue(){
        head = new Node(9999999,NULL,NULL);//由於優先序是看數字較大決定，因此要把他設成無限大(這裡不完全正確)
        tail = new Node(9999999,head,NULL);
        head->next = tail;
    }
    void push(int data){
        Node *cur = tail->prev;
        while(data > cur->data)
            cur = cur->prev;
        cur->insertAfter(data);
    }
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
    PriorityQueue pq;
    int n;
    while(cin >> n){
        for(int i = 0;i < n;i++){
            int num;
            cin >> num;
            pq.push(num);
        }
        for(int i = 0;i < n;i++){
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
}
