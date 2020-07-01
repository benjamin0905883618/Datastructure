#include<iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left,*right;
    TreeNode(int d) : data(d),left(NULL),right(NULL){}
};
class BinaryTree{
public:
    BinaryTree(int r){
        root = new TreeNode(r);
    }
    void push(int data){
        TreeNode *cur = root;
        while(true){
            if(data < cur->data){
                if(cur->left != NULL)
                    cur = cur->left;
                else{
                    cur->left = new TreeNode(data);
                    break;
                }
            }
            else if(data >= cur->data){
                if(cur->right != NULL)
                    cur = cur->right;
                else{
                    cur->right = new TreeNode(data);
                    break;
                }
            }

        }
    }
    TreeNode *r(){return root;}
private:
    TreeNode *root;
};
void Inorder(TreeNode *root){
    if(root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main(){
    BinaryTree b(10);
    for(int i = 0;i < 5;i++){
        int num;
        cin >> num;
        b.push(num);
    }
    TreeNode *root = b.r();
    Inorder(root);



}
