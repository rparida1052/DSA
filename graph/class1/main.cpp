#include <iostream>
using namespace std;
#include<unordered_map>
#include<list>


class Graph{
public:
    unordered_map<int,list<pair<int,int>> > adjList;
    void addEdge(int src,int dest,int weight,bool direction){

        //direction 0 -> undirected graph
        // direction 1 -> directed graph
        adjList[src].push_back({dest,weight});
        // if graph is undirectred
        if(direction == 0){
            adjList[dest].push_back({src,weight});
        }
    }

    void printAdjList(){
        for(auto node: adjList){
            cout<< node.first<<"-> ";
            for(auto neighbour:node.second){
                cout<<"("<<neighbour.first<<","<<neighbour.second<<")"<<", ";
            }
            cout<<endl;
        }
    }
};
int main() {
    Graph graph;
    graph.addEdge(0,1,5,0);
    graph.addEdge(0,2,6,0);
    graph.addEdge(1,3,8,0);
    graph.addEdge(2,1,9,0);
    graph.printAdjList(); 
    return 0;
}