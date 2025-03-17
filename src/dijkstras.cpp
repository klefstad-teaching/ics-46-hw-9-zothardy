#include "dijkstras.h"
#include <algorithm>
#include <iostream>
#include <queue>

vector<int> dijkstra_shortest_path(const Graph &G, int source, vector<int> &previous){
    int numVertices = G.numVertices;
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    //cout << "distances\n";
    previous.assign(numVertices, -1);
    //cout << "previous\n";

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
    minHeap.push({0, source});

    while(!minHeap.empty()){
        int dist = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(Edge edge : G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if(!visited[v] && dist + weight < distances[v]){
                distances[v] = dist + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }

    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> v;
    stack<int> stk;

    for(int i = destination; i != -1;){
        stk.push(i);
        i = previous[i];
    }

    while(!stk.empty()){
        v.push_back(stk.top());
        stk.pop();
    }
    return v;
}

void print_path(const vector<int>& path, int total){
    for(size_t i = 0;i < path.size(); ++i){
        cout << path[i] << " ";
    }
    cout << "\nTotal cost is " << total << endl;
}