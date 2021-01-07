#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *prev,*next;
};
void swap(Node *a,Node *b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
int main(){
	Node *a = new Node;
	a->data = 3;
	Node *b = new Node;
	b->data = 5;
	swap(a,b);
	cout << a->data << " " << b->data << endl;
	
}
