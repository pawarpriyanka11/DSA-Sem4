#include<iostream>
using namespace std;

class Node
{
   public:
   int city;
   int weight;
   Node *next;
   
   Node(int city1,int w)
   {
     city=city1;
     weight=w;
     next=NULL;
   }
};


class Graph
{
   public:
     
     string cities1[10];
     void addCities(int v)
     {
        cout<<"\nEnter the cities:";
        for(int i=0;i<v;i++)
        {
           cin>>cities1[i];
        }
        for(int i=0;i<v;i++)
        {
         cout<<i<<" "<<cities1[i]<<endl;
        }
     }
   int vert;
   Node *ad[10];
   
   Graph(int i1)
   {
     vert=i1;
     for(int i=0;i<vert;i++)
     {
      ad[i]=NULL;
     }
   }
   
   void addEdge(int s,int d,int w)
   {
      Node *newNode1=new Node(d,w);
      newNode1->next=ad[s];
      ad[s]=newNode1;
      
      Node *newNode2=new Node(s,w);
      newNode2->next=ad[d];
      ad[d]=newNode2;
      
      
   }
   
   void display()
   {
    for(int i=0;i<vert;i++)
    {
      cout<<i<<"->";
      Node *temp=ad[i];
      while(temp!=NULL)
      {
        cout<<"("<<temp->city<<" "<<temp->weight<<")"<<" ";
        temp=temp->next;
      }
       cout<<endl;
    }
   
   }
   
};

int main()
{
int e1,cv,ss,dd,u,vx;


cout<<"\nEnter the no of cities: ";
cin>>dd;


Graph g(dd);
g.addCities(dd);
cout<<"\nEnter the no of paths:";
cin>>e1;
for(int i=0;i<e1;i++)
{
 cout<<"\neneter edge (u,v) and weight:";
 cin>>u>>vx>>cv;
 g.addEdge(u,vx,cv);
 }
 
 
 cout<<"\ndisplay\n";
 g.display();


return 0;
}
