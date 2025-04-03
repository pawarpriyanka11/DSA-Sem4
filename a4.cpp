#include<iostream>
using namespace std;

#define v 5



int graph[v][v]={0};
string cities[v];




void display()
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}


void prims()
{
    int visited[v]={0};
    int total=0;
    visited[0]=1;

    for(int e=0;e<v-1;e++)
    {

        int min=9999,u=-1,v1=-1;
        for(int i=0;i<v;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<v;j++)
                {
                    if(!visited[j]&&graph[i][j]&&graph[i][j]<min)
                    {
                        min=graph[i][j];
                        u=i;
                        v1=j;
                    }
                }
            }
        }
        if(u!=-1&&v1!=-1)
        {
            cout<<cities[u]<<" "<<cities[v1]<<"-"<<min<<endl;
            visited[v1]=1;
            total+=min;
        }
    }
   
    cout<<"total weight: "<<total;
}

int main()
{
   int edges,weight;
   string city1,city2;

   cout<<"\nEnter city names :";
   for(int i=0;i<v;i++)
   {
   cin>>cities[i];}

   cout<<"\nEnter no of edges: ";
   cin>>edges;

   cout<<"\nEnter city1,city2,weight: ";
   for(int i=0;i<edges;i++)
   {
    cin>>city1>>city2>>weight;


    int u=-1,v1=-1;
   for(int j=0;j<v;j++)
   {
    if(cities[j]==city1) u=j;
    if(cities[j]==city2) v1=j;


    if(u!=-1&&v1!=-1)
    {
        graph[i][j]=weight;
        graph[j][i]=weight;
    }
   }


   }

   display();
   prims();
}