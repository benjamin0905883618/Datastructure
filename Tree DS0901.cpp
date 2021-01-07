#include<iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left,*right;

    TreeNode(int d):data(d),left(NULL),right(NULL){}
};
struct Node{
    int data;
    Node *prev,*next;

    Node(int d,Node *p,Node *n) : data(d),prev(p),next(n) {}

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

class List{
public:
    List(){
        head = new Node(0,NULL,NULL);
        tail = new Node(0,head,NULL);
        head->next = tail;
    }
    void push(int data){tail->insertBefore(data);}
    int top(){return tail->prev->data;}
    int front(){return head->next->data;}
    void pop(){
        if(!empty())
            head->next->remove();
    }
    void popback(){tail->prev->remove();}
    bool empty(){return head->next == tail;}
    void clear(){
        while(!empty())
            pop();
    }
    ~List(){
        clear();
        delete head;
        delete tail;
    }
private:
    Node *head,*tail;
};

TreeNode* genTree(List &inorder,List &postorder){
        if(inorder.empty())
            return NULL;
        TreeNode *root = new TreeNode(postorder.top());
        //cout << root->data << endl;
        postorder.popback();
        List inleft,postleft;
        //cout << "ok" << endl;
        while(inorder.front() != root->data && !postorder.empty()){
            inleft.push(inorder.front());
            postleft.push(postorder.front());
            inorder.pop();
            postorder.pop();
       }
        inorder.pop();
        root->left = genTree(inleft,postleft);
        root->right = genTree(inorder,postorder);
        //cout << "ok" << endl;
       return root;
}
struct Result{
    int sum,leaf;
};
//重載運算子
Result operator + (const Result &r, int add) {
    Result ans;
    ans.sum = r.sum + add;
    ans.leaf = r.leaf;
    return ans;
}

bool operator < (const Result &r1, const Result &r2) {
    return (r1.sum < r2.sum || (r1.sum == r2.sum && r1.leaf < r2.leaf));
}
//最小路徑
Result minPath(TreeNode *root)
{
    if(root->left == NULL && root->right == NULL){
        Result ans;
        ans.sum = root->data;
        ans.leaf = root->data;
        return ans;
    }else if(root->right == NULL){
        return minPath(root->left) + root->data;
    }else if(root->left == NULL){
        return minPath(root->right) + root->data;
    }else{
        Result left = minPath(root->left);
        Result right = minPath(root->right);
        if(left < right)
            return left + root->data;
        else
            return right + root->data;
    }
}
bool readList(List &list)
{
    list.clear();
    int input;
    if(!(cin >> input))
        return false;
    list.push(input);
    while(cin.get() != '\n'){
        cin >> input;
        list.push(input);
    }
    return true;
}

int main(){
    List inorder,postorder;
    string input;
    while(readList(inorder)){
        readList(postorder);
        TreeNode *root = genTree(inorder,postorder);
        cout << minPath(root).leaf << endl;
    }
}
