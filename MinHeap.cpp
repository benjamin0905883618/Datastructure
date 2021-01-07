#include<iostream>
using namespace std;


void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
class Heap{
private:
    int parent(int idx){return idx/2;}
    int left(int idx){return 2*idx;}
    int right(int idx){return 2*idx + 1;}
public:
    Heap(){data[0] = 0;}
    int size(){return data[0];}
    bool empty(){return size() == 0;}
    void clear(){data[0] = 0;}
    void push(int d){
        data[0]++;
        int cur = size();
        data[size()] = d;
        while(cur > 1 && data[cur] < data[parent(cur)]){
            swap(data[cur],data[parent(cur)]);
            cur = parent(cur);
        }
    }
    int pop(){
        int ret = data[1];
        data[1] = data[size()];
        int cur = 1;
        while(true){
            if(right(cur) < size() && data[right(cur)] < data[left(cur)] && data[right(cur)] < data[cur]){
                swap(data[right(cur)],data[cur]);
                cur = right(cur);
            }
            else if(left(cur) < size() && data[left(cur)] < data[right(cur)] && data[left(cur)] < data[cur]){
                swap(data[left(cur)],data[cur]);
                cur = left(cur);
            }
            else break;
        }
        data[0]--;
        return ret;
    }
    ~Heap(){
    }
protected:
    int data[25001];
};

int main(){
    Heap minh;
    int n;
    for(int i = 0;i < 5;i++){
        cin >> n;
        minh.push(n);
    }
    for(int i = 0;i < 5;i++){
        cout << minh.pop() << " ";
    }
    cout << endl;
}
