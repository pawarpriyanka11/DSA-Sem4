#include<iostream>
using namespace std;
class BST
{
    public: 
    BST* left;
    BST* right;
    int data;

    BST(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

}*root,*next1;




//recursive-insert
void insert1(BST* root,BST* next)
{
    if(root==NULL) return;

    if(next->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left=next;
            return;
        }
        else{
            insert1(root->left,next);
        }
    }

    else{
     if(root->right==NULL)
     {
        root->right=next;
        return;
     }
     else{
        insert1(root->right,next);
     }

}
}


//creates BST
void create()
{
    int val,c;
        do{
        cout<<"\nEnter the data:";
        cin>>val;
        
        BST *next=new BST(val);
        
        if(root==NULL)
        {
          root=next;
        }
        else
        {
           insert1(root,next);
        }
        
        cout<<"\nWant to insert more?";
        cin>>c;
        }while(c!=0);

}


//display Bst
void display(BST *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    display(root->left);
      display(root->right);
}




//recursive search
BST* search1(BST* root,int key)
{
    if(root==NULL)return NULL;
    if(root->data==key)
    {
        return root;
    }
    else if(root->data>key)
    {
        search1(root->left,key);
    }
    else if(root->data<key){
        search1(root->right,key);
    }
    else{
        return NULL;
    }

}







//non-recursive search
BST* search2(BST* root,int key)
{
    if(root==NULL)return NULL;
     while(root!=NULL)
     {
        if(root->data==key)
        {
            return root;
        }
        else if(root->data>key)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
     }
return NULL;
}



//recursive delete
void delete1()
{

}




//non recursive delete
void delete2()
{

}



//iterative insertion
void insert2(BST* root,int key)
{
    BST* prev = NULL; 
    if(root==NULL)
    {BST *newNode=new BST(key);
     root=newNode;
     return;   

    }


    while(root!=NULL)
    {
        prev=root;

        if(key<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    BST* temp=new BST(key);
    if(temp->data<prev->data)
    {
        prev->left=temp;
    }
    else{
        prev->right=temp;
    }

}


int main()
{
    int ch,val;
    root=NULL;

    do{
    cout<<"\n1.CREATE BST\n2.SERACH A NODE(recursive)\n3.SERACH A NODE(iterative)\n4.DELETE A NODE(recursive)\n5.DELETE A NODE(iterative)\n6.INSERT NEW NODE(recursive)\n7.INSERT NEW NODE(iterative)\n8.DISPLAY\n9.EXIT\nEnter your choice: ";

    cin>>ch;
    switch(ch)
    {
      case 1:
      
      create();
      break;
      
      case 2:
      cout<<"Enter the key that you want to search: ";
      cin>>val;

      next1 = search1(root, val);
if (next1)
cout << "Node found: " << next1->data << endl;
else
cout << "Node not found!" << endl;
      break;

      case 3:
      cout<<"Enter the key that you want to search: ";
      cin>>val;

      next1 = search2(root, val);
if (next1)
cout << "Node found: " << next1->data << endl;
else
cout << "Node not found!" << endl;


      break;

      case 4:
      break;

      case 5:
      break;

      case 6:
      cout << "\nEnter value to insert: ";
                cin >> val;
                next1=new BST(val);
                
                insert1(root,next1);
      break;

      case 7:
      cout << "\nEnter value to insert: ";
      cin >> val;
      insert2(root, val);
      break;

      case 8:
      display(root);
      break;

      case 9:
      cout<<"\nExiting from the code!";
      break;

      default:
      cout<<"\nInvalid case!";

    }
    }while(ch!=9);
}
