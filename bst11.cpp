#include<iostream>
using namespace std;
class BST
{
  public:
  int data;
  BST* left;
  BST* right;
  
  
  BST(int val)
  {
  data=val;
  left=NULL;
  right=NULL;
  }
}*root,*current,*temp;



void insert(BST* root,int key)
{

 if(root==NULL)
 {
   temp=new BST(key);
   return;
 }
 else
 {
  current=root;
  BST* prev;
 while(current!=NULL)
 {
 prev=current;
   
   if(key<current->data)
   {
     current=current->left;
   }
   else
   {
     current->right;
   }
 }
 
   BST* n=new BST(key);
   if(prev->data>key)
   {
     prev->left=n;
   }
   else
   {
     prev->right=n;
   }
 
 
   
 }
}


void preorder(BST* root)
{
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}


void inorder(BST* root)
{
  if(root==NULL)return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void postorder(BST* root)
{
  if(root==NULL)return;
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
}


int main()
{
root=NULL;
 int ch,key;
 
 do
 {
   cout<<"\nEnter your choice\n1.Insert\n2.preorder\n3.inorder\n4.postoredre\n5.Exit";
   cin>>ch;
   switch(ch)
   {
   case 1:
   cout<<"\nEnter the key you want to insert:";
   cin>>key;
   insert(root,key);
   break;
   
   case 2:
   preorder(root);
   break;
   
   case 3:
   inorder(root);
   break;
   
   case 4:
   postorder(root);
   break;
   
   case 5:
   cout<<"\nexitng from the code!";
   return 0;
   break;
   
   default:
   cout<<"\nInvalid case!";
   
   }
   
 }while(ch!=5);
 return 0;
}
