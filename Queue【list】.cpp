#include<iostream>
using namespace std;
class Queue
{
public:
    Queue(){
        data = new int [25001];
        front = 0;
        back = 0;
    }
    int size(){return back - front;}
    bool empty(){return back - front == 0;}
    void clear(){
        back = 0;
        front = 0;
    }
    void push(int d){
        data[back] = d;
        back++;
    }
    int top(){return data[front];}
    void pop(){front++;}
protected:
    int *data;
    int front,back;
};
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
