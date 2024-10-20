#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    void addEdge(int src,int dest , bool direction){
        adjList[src].push_back(dest);
        // if direction = 0 bidirectional 
        if(direction == 0){
            adjList[dest].push_back(src);
        }
    }

    void printAdjList(){
        for(auto node : adjList){
            cout << node.first << " -> ";
            for(auto neighbour : node.second){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
    void topoSortDfs(int src,unordered_map<int,bool> &visited,stack<int>&ans){
        visited[src] = true;
        for(auto neighbour : adjList[src]){
            if(!visited[neighbour]){
                topoSortDfs(neighbour,visited,ans);
            }
        }
        //while returning store the element in the stack
        ans.push(src);
    }
    void topoSortBfs(int src,unordered_map<int,bool> &visited,queue<int>&ans){
        queue<int>q;
        q.push(src);
        visited[src]  = true;
        ans.push(src);
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push(frontNode);
        }
    }
};
int main(){
    Graph graph;
    int n = 4;
    graph.addEdge(0,1,1);
    graph.addEdge(1,2,1);
    graph.addEdge(2,4,1);
    graph.addEdge(0,3,1);
    graph.printAdjList();
    cout<<endl;
    unordered_map<int,bool> visited;
    queue<int>ans;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            graph.topoSortBfs(i,visited,ans);
        }
    }

    cout<<"Topo sort ";
    while(!ans.empty()){
        cout<<ans.front();
        ans.pop();
    }
    // unordered_map<int,bool> visited;
    // stack<int>ans;
    // for(int i = 0;i<n;i++){
    //     if(!visited[i]){
    //         graph.topoSortDfs(i,visited,ans);
    //     }
    // }

    // cout<<"Topo sort";
    // while(!ans.empty()){
    //     cout<<ans.top();
    //     ans.pop();
    // }

    return 0;
}