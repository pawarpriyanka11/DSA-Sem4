#include<iostream>
#include<stack>
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
     
}*root,*current;

    
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
    
    
    void preoreder1(BT* root)
    {
    if(root==NULL) return;
    stack <BT*> s;
    s.push(root);
    
    while(!s.empty())
    {
      BT* current = s.top();
      s.pop();  
       
      cout<<current->data<<" ";
      if(current->right!=NULL)
      {
        s.push(current->right);
      }
      if(current->left!=NULL)
      {
       s.push(current->left);
      }
    }
    
    }
    
    int count(BT *root)
    {
     
      
       if(root==NULL) return 0;
      return 1 + count(root->left) + count(root->right);
    }
    
   
    void leaf(BT *root)
    {
      
      if(root==NULL) return;
      if (root->left == NULL && root->right == NULL) 
      {
        cout << root->data << " ";
      }
     leaf(root->left);
     leaf(root->right);
    }
    
    
    int height(BT *root)
    {
    
    if(root==NULL) return -1;
    int lh=height(root->left);
    int rh=height(root->right);

    
    return 1 + max(lh, rh);
    }
    
    
    
    
    
    bool ancestors(BT* root, int target) 
    {
    if(root==NULL) return false;
    
    if(root->data==target) return true;
        
    if(ancestors(root->left,target)||ancestors(root->right,target))
    {
       cout<<root->data<<" ";
       return true;
    }
    return false;
    }
    
    
    
    
    
    
    
   
    
    
    
    
    
    int main()
    {
      int cc;
      root=NULL;
       do
       {
          cout<<"\n\n1.CREATE\n2.PREOREDER\n3.INOREDER\n4.POSTORDR\n5.PREORDER-ITERATIVE\n6.COUNT-NODE\n7.DISPLAY-LEAF\n8.COUNT-HEIGHT\n9.ANCESTOR\n10.EXIT\nEnter your choice: ";
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
            preoreder1(root);
            break;
            
            case 6:
            cout<<"no of nodes in a tree: "<<count(root);
            break;
            
            case 7:
            leaf(root);
            break;
            
            case 8:
            cout<<"\nHeight of tree:"<<height(root);
            break;
            
            case 9:
            int t;
            cout<<"\nEnter target node:";
            cin>>t;
            ancestors(root,t);            
            break;

            case 10:            
            cout<<"\nExiting from the code!";
            return 0;
            break;
            
            default:
            cout<<"\nInvalid Case!";
            
          }
       }while(cc!=10);
       return 0;
    } 
