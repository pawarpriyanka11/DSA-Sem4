#include<iostream>
using namespace std;


class BT
{
   public:
     int data;
     BT *left;
     BT *right;
     
     BT(int x)
     {
        data=x;
        left=NULL;
        right=NULL;
        }     
     
}*root;

    
    void preorder(BT *root)
    {
      if(root==NULL)
      {
        return;
      }
      cout<<root->data<<" ";
      
      preorder(root->left);
      preorder(root->right);
    }
    
    
    void inorder(BT *root)
    {
      if(root==NULL)
      {
        return;
      }
     
      
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
    }
    
    
    void postorder(BT *root)
    {
      if(root==NULL)
      {
        return;
      }
      
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
    }
    
    
    
    void insert(BT *root1,BT *next1)
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
        int val,c;
        do{
        cout<<"\nEnter the data:";
        cin>>val;
        
        BT *next=new BT(val);
        
        if(root==NULL)
        {
          root=next;
        }
        else
        {
           insert(root,next);
        }
        
        cout<<"\nWant to insert more?";
        cin>>c;
        }while(c!=0);
    } 
    
    
    
    int main()
    {
      int cc;
      root=NULL;
       do
       {
          cout<<"\n\n1.CREATE\n2.PREOREDER\n3.INOREDER\n4.POSTORDR\n5.EXIT\nEnter your choice: ";
          cin>>cc;
          switch(cc)
          {
            case 1:
            create();
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
            cout<<"\nExiting from the code!";
            return 0;
            break;
            
            default:
            cout<<"\nInvalid Case!";
            
          }
       }while(cc!=5);
       return 0;
    } 
