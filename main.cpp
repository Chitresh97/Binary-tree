#include <iostream>
#include<algorithm>
#include "BinaryTreeNode.h"
#include<queue>

using namespace std;

void printLevelATNewLine(BinaryTreeNode<int> *root){

  if(root==NULL)
    return;

  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  pendingNodes.push(NULL);

  while(pendingNodes.size()!=0){
    BinaryTreeNode<int> *current=pendingNodes.front();
    pendingNodes.pop();

    if(current!=NULL){
      cout<<current->data<<" ";

      if(current->left!=NULL){
        pendingNodes.push(current->left);
      }


      if(current->right!=NULL){
        pendingNodes.push(current->right);
      }

    }

    else{

      cout<<endl;

      if(pendingNodes.size()!=0)
      	pendingNodes.push(NULL);
    }
  }
}

bool isBalanced(BinaryTreeNode<int> *root) {
  if(root==NULL)
    return true;

  if(abs(height(root->left)-height(root->right))<=1)
    return(isBalanced(root->left)&&isBalanced(root->right));
  else
    return false;
}

int height(BinaryTreeNode<int> *root){
  if(root==NULL)
    return 0;
  return 1+max(height(root->left),height(root->right));
}

int sumOfAllNodes(BinaryTreeNode<int>* root) {
  if(root==NULL)
    return 0;
  else
  	return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
}

void postOrder(BinaryTreeNode<int> *root) {
    if(root==NULL)
    	return;
    postOrder(root->left);
    postOrder(root->right);
  	cout<<root->data<<" ";
}

void preOrder(BinaryTreeNode<int> *root) {
  if(root==NULL)
    return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
  if(root==NULL)
    return;
  BinaryTreeNode<int>*temp=root->left;
  root->left=root->right;
  root->right=temp;
  mirrorBinaryTree(root->left);
  mirrorBinaryTree(root->right);
}


bool isNodePresent(BinaryTreeNode<int>* root, int x) {
  bool v=false;
  if(root->data==x)
    return true;
  else{
    if(root->left!=NULL)
    	if(isNodePresent(root->left,x))
      		v=true;
    if(root->right!=NULL)
    	if(isNodePresent(root->right,x))
      		v=true;
    return v;
  }

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
