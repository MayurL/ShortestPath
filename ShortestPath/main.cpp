#include <iostream>
#define infinity 100
#define in 9999
#define max 10

using namespace std;

class graph
{
    int G[max][max]={
                 {0,10,0,30,100},
                 {10,0,50,0,0},
                 {0,50,0,20,10},
                 {30,0,20,0,60},
                 {100,0,10,60,0}
                 };
    int n;//it is for number of vertices
public:
    graph()
    {
        n=5;//intiliaze n for 5 ie 5 cities
    }
    void readgraph();
    void cost(int startnode); //dijstra
};

void graph::readgraph()
{
    cout<<"Enter matrix";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>G[i][j];

}
void graph::cost(int startnode)//function use to claculate distance
{
    int cost[max][max],distance[max],pred[max]; //preis use to store predeccosor value
    int visited[max],count,mindistance,nextnode,i,j;//count for no of nodes ie cities or vertices

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=G[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        //intiliaze pred , dist and visited
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=infinity;
        //nextnode give the node at minimum distance
        for(i=0;i<n;i++)
        {
            if(distance[i]<mindistance && !visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
        //verify next node has better path

        visited[nextnode]=1;
        for(i=0;i<n;i++)
        {
        if(!visited[i])
            if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        }
        count++;
    }
    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            cout<<"\nDistance of city "<<i<<" = "<<distance[i]<<"km  ";
            cout<<"\n Path is "<<i;
            j=i;
            do
            {
                j=pred[j];
                cout<<"   <====>   "<<j;
            }while(j!=startnode);
            cout<<"\n\n\n";
        }
}

int main()
{
    int startcity;
    graph g;
   // g.readgraph();
    cout << "Enter the starting city(0-5) " << endl;
    cin>>startcity;
    g.cost(startcity);
    return 0;
}
