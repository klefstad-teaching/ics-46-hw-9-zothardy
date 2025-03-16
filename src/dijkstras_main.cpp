#include "dijkstras.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    string filename = "small.txt";
    Graph G;


    file_to_graph(filename, G);
    cout << "file to graph\n";

    int source = 0;
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    cout << "dijkstras\n";

    int destination;
    cin >> destination;

    vector<int> path = extract_shortest_path(distances, previous, destination);
    print_path(path, distances[destination]);

    return 0;
}