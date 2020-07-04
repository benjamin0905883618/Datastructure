#include<iostream>
using namespace std;
class Stack
{
public:
    Stack(){
        data = new int [25001];
        data[0] = 0;
    }
    int size(){return data[0];}
    bool empty(){return data[0] == 0;}
    void clear(){data[0] = 0;}
    void push(int d){
        data[0]++;
        data[size()] = d;
    }
    int top(){return data[size()];}
    void pop(){data[0]--;}
protected:
    int *data;
};
int main(){
    Stack s;
    int n;
    while(cin >> n){
        for(int i = 0;i < n;i++){
            int num;
            cin >> num;
            s.push(num);
        }
        for(int i = 0;i < n;i++){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}
