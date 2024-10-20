#include <iostream>
using namespace std;
#include<unordered_map>
#include<list>
#include<queue>
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
    bool findCycleUsingBfs(int src,unordered_map<int,bool> &visited){
    queue<int>q;
    unordered_map<int,int>parent;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    while (!q.empty())              
    {
        int frontNode = q.front();
        q.pop();
        for(auto neighbour:adjList[frontNode]){
            if(!visited[neighbour.first]){
                q.push(neighbour.first);
                visited[neighbour.first] = true;
                parent[neighbour.first] = frontNode;
            }
            // if neighbour is visited and neighboar is not the parent of frontnode then 
            // neighbour is visited by another node so cycle is present 
            if( neighbour.first != parent[frontNode]){
                return true; 
            }
        }
    }
    return true;
}
bool findCycleUsingDfs(int src,unordered_map<int,bool>&visited,int parent){
    visited[src] = true;
    for(auto neighbour : adjList[src]){
        if(!visited[neighbour.first]){
            bool ans = findCycleUsingDfs(neighbour.first,visited,src);
            if(ans == true){
                return true;
            }
        }
        if(visited[neighbour.first] && neighbour.first != parent){
            return true;
        }
    }
    return false;
}
bool findCyclicDirectedGraphUsingDfs(int src,unordered_map<int,bool> &visited,unordered_map<int,bool> dfsVisited){
    visited[src] = true;
    dfsVisited[src] = true;
    for(auto neighbour:adjList[src]){
        if(!visited[neighbour.first]){
            bool checkNextElel = findCyclicDirectedGraphUsingDfs(neighbour.first,visited,dfsVisited);
            if(checkNextElel){
                return true;
            }
        }
        if(visited[neighbour.first] && dfsVisited[neighbour.first]){
            return true;
        }
    }
    // Make the entry to false if the element is out of the recursion call stack
    dfsVisited[src] = false; // Most important line . take extra care of 
    return false;
}
};

int main() {

    Graph<int>graph;
    int node = 5;
    graph.addEdge(0,1,5,1);
    graph.addEdge(1,2,5,1);
    graph.addEdge(2,3,5,1);
    graph.addEdge(3,0,5,1);
    graph.printAdjList();

    bool isCyclePresent =false;
    unordered_map<int , bool> visited;
    unordered_map<int , bool>dfsVisited;

    for(int i = 0;i<5;i++){
        if(!visited[i]){
            isCyclePresent = graph.findCyclicDirectedGraphUsingDfs(i,visited,dfsVisited);
            if(isCyclePresent == true){
                break;
            }
        }
    }

    if(isCyclePresent){
        cout<<"Cycle is present"<<endl;
    }else{
        cout<<"Cycle is absent"<<endl;
    }

    // bool isCyclePresent =false;
    // unordered_map<int , bool> visited;
    // for(int i = 0;i<5;i++){
    //     if(!visited[i]){
    //         isCyclePresent = graph.findCycleUsingBfs(i,visited);
    //         if(isCyclePresent == true){
    //             break;
    //         }
    //     }
    // }

    // if(isCyclePresent){
    //     cout<<"Cycle is present"<<endl;
    // }else{
    //     cout<<"Cycle is absent"<<endl;
    // }

    // bool isCyclePresentDfs =false;
    // unordered_map<int , bool> visitedDfs;
    // for(int i = 0;i<5;i++){
    //     if(!visitedDfs[i]){
    //         isCyclePresentDfs = graph.findCycleUsingDfs(i,visited,-1);
    //         if(isCyclePresentDfs == true){
    //             break;
    //         }
    //     }
    // }

    // if(isCyclePresentDfs){
    //     cout<<"Cycle is present"<<endl;
    // }else{
    //     cout<<"Cycle is absent"<<endl;
    // }
    // Graph graph;
    // graph.addEdge(0,1,5,0);
    // graph.addEdge(0,2,6,0);
    // graph.addEdge(1,3,8,0);
    // graph.addEdge(2,1,9,0);
    // graph.printAdjList(); 
    
    return 0;
}