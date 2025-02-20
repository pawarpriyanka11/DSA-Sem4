#include<iostream>
using namespace std;


class Family
{
   public:
   Family* left;
   Family* right;
   string name;
   
   Family(string name1)
   {
      left=NULL;
      right=NULL;
      name=name1;
   }
   
   
}*root,*next2;



void insert(Family* root1,Family *next1)
{

    char ch;
       cout<<"\nWhere do you want to insert(L/R): ";
       cin>>ch;
       if(ch=='l'||ch=='L')
       {
         if(root1->left==NULL)
         {
            root1->left=next1;
         }
         else
         {
           insert(root1->left,next1);
         }
       }
       else 
       {
         if(root1->right==NULL)
         {
            root1->right=next1;
         }
         else
         {
           insert(root1->right,next1);
         }
          
       }
  
}



void create()
{
  
 int cc;
  string name;
  do{
  cout<<"\nEnter the name:";
  cin>>name;
  Family* next=new Family(name);
     if(root==NULL)
     { root=next;}
     else
     {
     insert(root,next);
     cout<<"\nDo you want to insert more?(0/1)";
     cin>>cc;
     }
  }while(cc!=1);

}


 void preorder(Family *root)
    {
      if(root==NULL)
      {
        return;
      }
      cout<<root->name<<" ";
      
      preorder(root->left);
      preorder(root->right);
    }
    
    
    void inorder(Family *root)
    {
      if(root==NULL)
      {
        return;
        
      }
      inorder(root->left);
      cout<<root->name<<"";
      inorder(root->right);
    }


   void postorder(Family* root)
   {
     if(root==NULL) return;
     postorder(root->left);
     postorder(root->right);
     cout<<root->name<<"";
   }
   
   
   int count(Family *root)
    {
     
      
       if(root==NULL) return 0;
      return 1 + count(root->left) + count(root->right);
    }
    
   
    void leaf(Family *root)
    {
      
      if(root==NULL) return;
      if (root->left == NULL && root->right == NULL) 
      {
        cout << root->name << " ";
      }
     leaf(root->left);
     leaf(root->right);
    }
    
    
    int height(Family *root)
    {
    
    if(root==NULL) return -1;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1 + max(lh, rh);
    }
    
    
    
    void ancestors(Family* root) 
    {
    if(root==NULL) return;
    cout<<root->name;
    }
    
    
    void sibling(Family* root,val1)
    {
    if(root==NULL)return;
    next2=root;
    if(next2->left->name==val1)
    {
    cout<<next2->right->name;
      
    }
    else
    {
    cout<<next2->right->name;
    }
    
       
    }
    
   
int main()
{
  int ch;
  
  string val;
  root=NULL;
  
  do
  {
     cout<<"\n\n1.create\n2.Insert\n3.Preoreder\n4.Inoreder\n5.Postorder\n6.Height\n7.Number of nodes\n8. Leaft nodes\n9. Ancestor of all\n10.sibiling\n11.exit\nEnter your choice:";
     cin>>ch;
     
     switch(ch)
     {
       case 1:
       create();
       break;
       
       case 2:
       cout<<"\nEnter the string:";
       cin>>val;
       next2=new Family(val);
       insert(root,next2);
       break;
       
       case 3:
       preorder(root);
       break;
       
       case 4:
       inorder(root);
       break;
       
       case 5:
       postorder(root);
       break;
       
       case 6:
       cout<<"\nheight of atree is:"<<height(root);
       break;
       
       case 7:
       cout<<"\nnumber of family members:"<<count(root);
       break;
       
       case 8:
       leaf(root);
       break;
       
       case 9:
       ancestors(root);
       break;
       
       case 10:
       string x;
       cout<<"\nEnter the name of child for which yiu have to find out sibiling:";
       cin>>x;
       sibling(root,x);
       break;
       
       case 11:
       cout<<"\nExiting from the code!";
       return 0;
       break;
       
       default:
       cout<<"\nInvalid case!";
       
     }
  }while(ch!=11);
}
