#include <iostream>
using namespace std;

struct Node{
    int name;
    int freq;
    int time;
    Node(int n,int f,int t) : name(n),freq(f),time(t){}
};

struct ListNode{
    Node casenum;
    ListNode *prev,*next;
    ListNode(Node c,ListNode *p,ListNode *n) : casenum(c),prev(p),next(n){}
    void insertAfter(Node c){
        ListNode *temp = new ListNode(c,this,this->next);
        temp->next->prev = temp;
        temp->prev->next = temp;
    }
    void remove(){
        this->next->prev = this->prev;
        this->prev->next = this->next;
        delete this;
    }
};

class PriorityQueue
{
public:
    PriorityQueue(){
        Node zero = Node(-1,-1,-1);
        head = new ListNode(zero,NULL,NULL);
        tail = new ListNode(zero,head,NULL);
        head->next = tail;
        //cout << "ok" << endl;
    }
    void push(Node data){
        //cout << data.name << endl;
        ListNode* cur = tail->prev;
        //cout << "ok" << endl;
        while(data.time <= cur->casenum.time){
            //cout << data.time << " " << cur->casenum.time << " " << data.name << " " << cur->casenum.name << endl;
            if(data.time == cur->casenum.time && data.name > cur->casenum.name)
                break;
            //cout << "move" << endl;
            cur = cur->prev;
        }
        cur->insertAfter(data);
    }
    Node top(){return head->next->casenum;}
    void pop(){head->next->remove();}
    bool empty(){return head->next == tail;}
    void clear(){
        while(!empty())
            pop();
    }
    ~PriorityQueue(){
        clear();
        delete head;
        delete tail;
    }
protected:
    ListNode *head,*tail;
};
int main(){
    string input;
    PriorityQueue p;
    while(cin >> input && input != "#"){
        int name,freq;
        cin >> name >> freq;
        Node temp = Node(name,freq,freq);
        //cout << temp.name << " " << temp.freq << " " << temp.time<< endl;
        p.push(temp);
    }
    //p.test();
    int time;
    cin >> time;
    //cout << time;
    for(int i = 0;i < time;i++){
        Node temp = p.top();
        cout << temp.name << endl;
        temp.time = temp.time + temp.freq;
        p.pop();
        p.push(temp);
    }
}
