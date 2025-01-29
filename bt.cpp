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

    
    void display(BT *root)
    {
      if(root==NULL)
      {
        return;
      }
      cout<<root->data<<" ";
      
      display(root->left);
      display(root->right);
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
          cout<<"\nEnter your choice: \n1.CREATE\n2.DISPLAY\n3.EXIT: ";
          cin>>cc;
          switch(cc)
          {
            case 1:
            create();
            break;
            
            case 2:
            display(root);
            break;
            
            case 3:
            cout<<"\nExiting from the code!";
            return 0;
            break;
            
            default:
            cout<<"\nInvalid Case!";
            
          }
       }while(cc!=3);
       return 0;
    } 
