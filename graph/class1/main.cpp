#include <iostream>
using namespace std;
#include<unordered_map>
#include<list>
template <typename T>


class Graph{
public:
    unordered_map<T,list<pair<T,int>> > adjList;
    void addEdge(T src, T dest, int weight, bool direction){

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

    Graph<char>graph;
    graph.addEdge('a','b',5,0);
    graph.addEdge('b','c',5,0);
    graph.addEdge('c','b',5,0);
    graph.addEdge('c','a',5,0);
    graph.printAdjList();
    // Graph graph;
    // graph.addEdge(0,1,5,0);
    // graph.addEdge(0,2,6,0);
    // graph.addEdge(1,3,8,0);
    // graph.addEdge(2,1,9,0);
    // graph.printAdjList(); 
    return 0;
}