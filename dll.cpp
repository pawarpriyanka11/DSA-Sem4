#include<iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node *prev;
  Node *next;
  
  
  Node(int val)
  {
     data=val;
     next=NULL;
     prev=NULL;
  }
}*head,*temp,*ind;


int main()
{

  int ch,x,pos;
  do
  {
  
  cout<<"\nEnter your choice \n1. create\n2. display\n3. remove\n4. exit: ";
  cin>>ch;
  
  
  switch(ch)
  {
    case 1:
    cout<<"\nEnter the data: ";
    cin>>x;
    temp=new Node(x);
    if(head==NULL)
    {
     head=temp;
     
     }
     else
     {
        ind=head;
        while(ind->next)
        {
          ind=ind->next;
        }
        ind->next=temp;
        temp->prev=ind;
        
     }
     
    break;
    
    case 2:
    
   if(head==NULL)
       {
         cout<<"\nList is empty!";
       }
      else
      {
       ind=head;
       while(ind)
       {
          cout<<ind->data<<endl;
          ind=ind->next;
  
       }
       } 
    break;
    
    
    case 3:
    if(head==NULL)
    {
      cout<<"\nList is empty!";
    }
    else
    {
     cout<<"\nEnter the node you want to remove:";
       cin>>pos;
       
       for(int i=1;i<pos-1&&temp!=NULL;i++)
       {
        temp=temp->next;
       }
       
       if(temp->next==NULL)
       {
          cout<<"\nElement is not there in list!";
       }
        
        ind=temp->next;
        temp->next=ind->next;
        ind->next=ind->next->prev;
    
       
    }
    break;
    
    
    
    case 4:
    cout<<"\nExiting from the code";
    return 0;
    break;
    
    default:
    cout<<"\nInvalid case!";
    
  }
  }while(ch!=3);
 return 0;
 
}
