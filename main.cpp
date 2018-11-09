#include <iostream>
#include "BinaryTreeNode.h"
#include<queue>

using namespace std;

void printLevelWise(BinaryTreeNode<int> *root) {

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> * front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        cout<<"L:";
        if(front->left==NULL)
            cout<<-1;
        else{
            cout<<front->left->data;
            pendingNodes.push(front->left);
        }


        cout<<",R:";
        if(front->right==NULL)
            cout<<-1;
        else{
            cout<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;

    }
}


BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data:"<<endl;
    cin>>rootData;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChild;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChild);
            pendingNodes.push(child);
            front->left=child;

        }

        cout<<"Enter right child "<<front->data<<endl;
        int rightChild;
        cin>>rightChild;
        if(rightChild!=-1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChild);
            pendingNodes.push(child);
            front->right=child;
        }
    }

    return root;
}


void printTree(BinaryTreeNode<int>*root){
    if(root==NULL)
        return;

    cout<<root->data<<": ";
    if(root->left!=NULL)
        cout<<"L="<<root->left->data<<" ";
    if(root->right!=NULL)
        cout<<"R="<<root->right->data<<endl;
    printTree(root->left);
    printTree(root->right);
    cout<<endl;
}



int main()
{
    BinaryTreeNode<int>*root=takeInputLevelWise();
    printTree(root);
}
