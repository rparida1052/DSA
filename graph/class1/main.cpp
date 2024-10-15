#include <iostream>
using namespace std;
#include<unordered_map>
#include<list>


class Graph{
public:
    unordered_map<int,list<int> > adjList;
    void addEdge(int src,int dest,bool direction){

        //direction 0 -> undirected graph
        // direction 1 -> directed graph
        adjList[src].push_back(dest);
        // if graph is undirectred
        if(direction == 0){
            adjList[dest].push_back(src);
        }
    }

    void printAdjList(){
        for(auto node: adjList){
            cout<< node.first<<"-> ";
            for(auto neighbour:node.second){
                cout<<neighbour<<" , ";
            }
            cout<<endl;
        }
    }
};
int main() {
    Graph graph;
    graph.addEdge(0,1,0);
    graph.addEdge(0,2,0);
    graph.addEdge(1,3,0);
    graph.addEdge(2,1,0);
    graph.printAdjList(); 
    return 0;
}