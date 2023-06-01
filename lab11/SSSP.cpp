#include <bits/stdc++.h>
#include <iostream> 
using namespace std;

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<6;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum =distance[k];
            ind=k;
        }
    }
    return ind;
}

double DijkstraAlgo(int graph[6][6],int src) // adjacency matrix 
{
    int distance[6]; // // array to calculate the minimum distance for each node                             
    bool Tset[6];// boolean array to mark visited and unvisited for each node
    double avg;
     
    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<6; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<6; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from "<<src << " source vertex"<<endl;
    int total;
    for(int k = 0; k<6; k++)                      
    { 
         
        cout<< k <<"\t\t\t"<<distance[k]<<endl;
    }
    avg=(distance[1]+distance[2]+distance[3]+distance[4]+distance[5]+distance[0])/6.0;
    return avg;
}

int main()
{
    double avg[6];
    int graph[6][6]={
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}};
    avg[0]=DijkstraAlgo(graph,0);
    cout <<"avarage time taken is :"<<avg[0]<<"\n"<<endl;
    avg[1]=DijkstraAlgo(graph,1);
     cout <<"avarage time taken is :"<<avg[1]<<"\n"<<endl;
    avg[2]=DijkstraAlgo(graph,2);
     cout <<"avarage time taken is :"<<avg[2]<<"\n"<<endl;
    avg[3]=DijkstraAlgo(graph,3);
     cout <<"avarage time taken is :"<<avg[3]<<"\n"<<endl;
    avg[4]=DijkstraAlgo(graph,4);
     cout <<"avarage time taken is :"<<avg[4]<<"\n"<<endl;
    avg[5]=DijkstraAlgo(graph,5);
     cout <<"avarage time taken is :"<<avg[5]<<"\n"<<endl;

    double smallest = 100.0;
    vector<int> smallest_index;
    for (int i = 0; i < size(avg); i++) {
        if (avg[i] <= smallest) {
            smallest = avg[i];
        }
    }
    for (int i = 0; i < size(avg); i++) {
        if (avg[i] == smallest) {
            smallest_index.push_back(i);
        }
    }
    cout << "suitable town to place the hospital is/are vertex/vertices ";
    for(int j=0;j<size(smallest_index);j++){
        cout<<smallest_index[j]<<" ";
    }
    cout <<endl;

    return 0;                           
}
