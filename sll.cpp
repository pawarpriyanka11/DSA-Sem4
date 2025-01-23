#include<iostream>
using namespace std;

class Node
{
 public:
 int data;
 Node *next;
  
     Node(int val)
     {  
       data=val;
       next=NULL;
     }
     }*head,*temp,*ind;
     
     
 int main()
 {
    
    int xx,ch=1,pos;
    
    while(ch<4)
{
    cout<<"\n1. create\n2. display\n3. remove \n";
    cin>>ch;
    if(ch==1)
    {
       cout<<"\nEnter data:";
       cin>>xx;
      temp=new Node(xx);
      if(head==NULL)
      {
         head=temp;
      }else
      {
         ind=head;
         while(ind->next)
         {
            ind=ind->next; 
         }
         ind->next=temp;
         
      }
    }
    if(ch==2)
    {
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
       
    }
    if(ch==3)
    {
       temp=head;
       
     
       if(head==NULL)
       {
         cout<<"\nList is empty!";
       }
       
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
        cout<<"\nElement to be removed is :"<<ind->data;
        delete ind;
      
    }
    }
    return 0;
    
 }    
