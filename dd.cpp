#include<iostream>
using namespace std;


class Node
{
 public:
 Node* next;
 int roll,marks;
 string name;
 
 Node(int r,string n,int m)
 {
 
 roll=r;
 name=n;
 marks=m;
 next=NULL;
 }
}*node;

class Hash
{
  public:
  
 Node* aa[10];

 void insert(int rn,string nm,int mk)
 {
  Node* temp=new Node(rn,nm,mk);
  
  
  for(int i=0;i<10;i++)
  {
    if(aa[node]==NULL)
    {
       aa[node]=temp;
    }
    
    
  }
 /*if(node==NULL)
 {
   node=temp;
 }
 else
 {
   while(node->next!=NULL)
   {
   node=node->next;
      insert(rn,nm,mk);
      
   }
 }*/
  
 }
 
 void display()
 {
 cout<<"\ndisplay:";
    while(node!=NULL)
    {
      cout<<node->roll;
    }
 }
   
};

int main()
{
  Hash hh;
  string n1;
  int rn1,mk1;
  cout<<"\nEnter the roll, name, marks: ";
  cin>>rn1>>n1>>mk1;
  hh.insert(rn1,n1,mk1);
  hh.display();
   
   return 0;
}
