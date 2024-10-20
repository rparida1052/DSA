#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include <algorithm>

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;


    void addEdge(int src,int dest,int weight,int direction){
        // direction = 0 undirected Graph
        // direction = 1 un directed graph
            adjList[src].push_back({dest,weight});
            if(direction == 1){
                adjList[dest].push_back({src,weight});
            }
    }

    void printAdjList(){
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto neighbour:node.second){
                cout << "(" << neighbour.first << "," << neighbour.second << ")";
            }
            cout<<endl;
        }
    }
    void shortestPath(int src,int dest){
        unordered_map<int,int> parent;
        unordered_map<int,bool> visited;
        queue<int>q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto nbr:adjList[frontNode]){
                if(!visited[nbr.first]){
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = frontNode;
                }
            }
        }

        // store the path in ans vector and print 
        vector<int>ans;
        int node = dest;
        while (node != -1)      
        {
            ans.push_back(node);
            node = parent[node];
        }
        
        reverse(ans.begin(),ans.end());
        cout<<"Printing the ans";
        for(auto i: ans){
            cout<<i<<",";
        }
        cout<<endl;
    }
    void shortestDistanceDijkstra(int src,int n){
        vector<int>distance(n,INT_MAX);
        set<pair<int,int>> st;
        // initial step

        distance[src]= 0;
        st.insert(make_pair(0,src));
        
        while(!st.empty()){
            // fetch the smallest or first element from the set
            auto topElement = *(st.begin());  //st.begin() return a iterator so we deferance by using deference operator;
            int nodeDistance = topElement.first;
            int node = topElement.second;

            //remove the entry from the set
            st.erase(st.begin());
            // neighbour traversing
            for(auto nbr:adjList[node]){
                if(nodeDistance+nbr.second < distance[nbr.first]){
                    //  update the distance with new distacne
                    auto result = st.find(make_pair(distance[nbr.first],nbr.first));
                    // if result is found then remove the result
                    if(result != st.end()){
                        st.erase(result);

                    }
                    distance[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(distance[nbr.first],nbr.first));
                }
            }
            
        }

        cout <<"Printing the answer" <<endl;
        for(int i = 0;i<n;i++){
            cout << distance[i] <<", ";
        }
        cout<<endl;
    }
};



int main(){
    Graph g;
    g.addEdge(6,3,2,1);
    g.addEdge(6,1,14,1);
    g.addEdge(3,1,9,1);
    g.addEdge(3,2,10,1);
    g.addEdge(1,2,7,1);
    g.addEdge(2,4,15,1);
    g.addEdge(4,3,11,1);
    g.addEdge(6,5,9,1);
    g.addEdge(4,5,6,1);

    g.printAdjList();
    g.shortestDistanceDijkstra(6,7);
    // g.printAdjList();
    // int src =0 ;
    // int dest = 4;
    // g.shortestPath(src,dest);
    return 0;
}