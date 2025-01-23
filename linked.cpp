#include<iostream>
using namespace std;

class Node
{
   public:
    int data;
    Node* next;
    
    Node(int val)
    {
       data=val;
       next=NULL;
    }
};

class Linked
{
   public:
   Node *head;
   Linked()
   {
      head=nullptr;
   }
   
   
   void insert(int value)
   {
      Node* newNode=new Node(value);
      
      
      if(head==nullptr)
      {
         head=newNode;
         }
         else
         {
            Node* temp=head;
            while(temp->next!=nullptr)
            {
              temp=temp->next;
              
            }
            temp->next=newNode;
         }
      }
      
      
      
      void display()
      {
         Node* temp=head;
         while(temp!=nullptr)
         {
           cout<<temp->data<<endl;
         }
         temp=temp->next;
      }
};

int main()
{
   Linked ll;
   ll.insert(10);
   ll.display();
}
