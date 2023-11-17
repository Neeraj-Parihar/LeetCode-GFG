//implementation of binary tree and traversals in binary tree
#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root){
    cout<<"enter the data: ";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter the data to the left part: "<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the data to insert to the right: "<<endl;
    root->right=buildTree(root->right);
    return root;
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); // this is basically a separater for each level of the binary tree.

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root=NULL;
    root=buildTree(root);
    //nodes 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Printing on the basis of the level order traversal: "<<endl;
    levelOrderTraversal(root);
    cout<<"preOrder traversal is:"<<endl;
    preOrder(root);
    cout<<endl<<"inOrder traversal is:"<<endl;
    inOrder(root);
    cout<<endl<<"postOder traversal is:"<<endl;
    postOrder(root);
    return 0;
}
