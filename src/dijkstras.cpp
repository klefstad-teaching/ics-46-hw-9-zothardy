#include "dijkstras.h"
#include <algorithm>
#include <iostream>
#include <queue>

vector<int> dijkstra_shortest_path(const Graph &G, int source, vector<int> &previous){
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    //cout << "distances\n";
    previous.assign(numVertices, -1);
    //cout << "previous\n";

    priority_queue<pair<int,int>> minHeap;
    minHeap.push({source, 0});

    while(!minHeap.empty()){
        //cout << "entered while loop\n";
        int u = minHeap.top().first;
        cout << u << endl;
        minHeap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(Edge edge : G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }

    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    for(int at = destination; at != -1; at = previous[at]){
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& path, int total){
    for(size_t i = 0;i < path.size(); ++i){
        cout << path[i] << " ";
    }
    cout << "Total cost is " << total << endl;
}