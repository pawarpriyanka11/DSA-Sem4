#include<iostream>
using namespace std;

class BST
{
    public:
     string nm;
     int id,sal;

     BST* left;
     BST* right;

     BST(int i1,int sal1,string s1)
     {
        id=i1;
        sal=sal1;
        nm=s1;
        left=NULL;
        right=NULL;
     }

}*root;

void insert(BST* root,BST* next)
{
    if(root->sal>next->sal)
    {
        root->left=next;
    }
    else{
           root->right=next;
    }

}
void create()
{
    int ccc;
    int ii,ss;
    string nn;
    do{
        cout<<"\nEnter id,sal,name: ";
        cin>>ii>>ss>>nn;

        BST* next=new BST(ii,ss,nn);
        if(root==NULL)
        {
            root=next;
        }
        else{
            insert(root,next);
        }


        cout<<"\nDo u want to insert more?(0/1): ";
        cin>>ccc;
    }while(ccc!=1);

}
void display(BST* root)
{
if(root==NULL)return;
cout<<root->id<<" "<<root->sal<<" "<<root->nm<<endl;
display(root->left);
display(root->right);
}
void search(BST* root,int k)
{
    if(root==NULL) return;
    if(root->sal==k)
    {
        cout<<root->id<<" "<<root->sal<<" "<<root->nm<<endl;
    }
    else if(root->sal>k)
    {
        search(root->left,k);
    }
    else if(root->sal<k)
    {
        search(root->right,k);
    }
    else{
        cout<<"not found";
    }

}
void update(BST* root,BST* next)
{
    if(root==NULL) return;
    if(root->sal==next->sal)
    {
        root->nm=next->nm;
        return;
        
    }
    else{
        update(root->left,next);
        update(root->right,next);
    }
}
void min(BST* root)
{
    if(root==NULL) return;
    while(root->left!=NULL)
    {
        root=root->left;
    }
cout<<root->id<<" "<<root->sal<<" "<<root->nm<<endl;

}
void max(BST* root)
{
    if(root==NULL) return;
    while(root->right!=NULL)
    {
        root=root->right;
    }
cout<<root->id<<" "<<root->sal<<" "<<root->nm<<endl;

    

}
int avg(BST* root) {
    if (root == NULL) return 0;
    return (root->sal + avg(root->left) + avg(root->right));
}

int cnt(BST* root)
{
    if(root==NULL)return 0;
    return 1+cnt(root->left)+cnt(root->right);
}

int main()
{int ch;
    root=NULL;
    int kk,ix,sx;
    string sd;
    BST* temp;
    int cnt1=0;
    int av1;

    do{
        cout<<"\nEnter ch: ";
        cout<<"\n1. create: ";
        cout<<"\n2. update: ";
        cout<<"\n:3. display ";
        cout<<"\n:4. search ";
        cout<<"\n:5. max ";
        cout<<"\n:6. min";
        cout<<"\n:7. avg ";
        cout<<"\n:8. exit";
        cin>>ch;
        switch(ch)
        {
            case 1:
            create();
            break;

            case 2:
        //    int ix,sx;
        //    string sd;
           cout<<"\nenter id,sal,name: ";
           cin>>ix>>sx>>sd;
           temp=new BST(ix,sx,sd);
           update(root,temp);
            break;

            case 3:
            display(root);
            break;

            case 4:
            // int kk;
            cout<<"\nEntre key: ";
            cin>>kk;
            search(root,kk);
            break;

            case 5:
        max(root);
            break;

            case 6:
            min(root);
            break;

            case 7:
            cnt1=cnt(root);
            av1=avg(root);
            if(cnt1==0) cout<<"\nTREE EMPTY!";
            else cout<<(av1/cnt1);
            break;

            case 8:
            cout<<cnt(root);
            break;

            case 9:
            cout<<"\nExiting from the code!";
            break;

            default:
            cout<<"\nInvalid case!";


        }
        
    }while(ch!=9);
    return 0;
}