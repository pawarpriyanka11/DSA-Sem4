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



BST* delete1(BST* root, int x) {
    if (root == NULL) return NULL;

    if (x < root->data) {
        root->left = delete1(root->left, x);
    } else if (x > root->data) {
        root->right = delete1(root->right, x);
    } else {
        if (root->left == NULL || root->right == NULL) {
        (root->left != NULL) 
        {
        next1=root->left;
        }
        else
        { next1=root->right;}

            delete root;
            return temp;
        }

       //2child
        BST* successor = root->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }

        root->data = successor->data; 
        root->right = delete1(root->right, successor->data); 
    }
    return root;
}



//non recursive delte
void deletee(BST*& root, int key) {
    BST* parent = NULL;
    BST* current = root;

    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    
    if (current == NULL) {
        cout << "Node not found!\n";
        return;
    }

BST* child;
if(current->left != NULL){ current->left;} 
else{current->right;}

if (parent == NULL) {
    root = child;
} else if (parent->left == current) {
    parent->left = child;
} else {
    parent->right = child;
}
delete current;


    // Case 3: Node has two children
    else {
        BST* successorParent = current;
        BST* successor = current->right;

        // Find the inorder successor (smallest value in right subtree)
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace current node with successor's value
        current->data = successor->data;

        // Delete the successor (which is guaranteed to have at most one child)
        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;

        delete successor;
    }
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
    int ch,chh,val;
    root=NULL;

    do{
    cout<<"\n\n1.CREATE BST\n2.SERACH A NODE(recursive)\n3.SERACH A NODE(iterative)\n4.DELETE A NODE(recursive)\n5.DELETE A NODE(iterative)\n6.INSERT NEW NODE(recursive)\n7.INSERT NEW NODE(iterative)\n8.DISPLAY\n9.EXIT\nEnter your choice: ";

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
        cout << "\nEnter value to insert: ";
                cin >> val;
      next1=delete1(root,val);
      cout<<next1->data;
      break;

      case 5:
       cout << "\nEnter value to insert: ";
                cin >> val;
      deletee(root,val);
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