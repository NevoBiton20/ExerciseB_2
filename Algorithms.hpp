//Id: 214173957
// Email: nevobiton0@gmail.com
#include "Graph.hpp"
#include <string.h>
#include <iostream>

namespace ariel
{
    class Algorithms
    {
        public:
            static bool isConnected(ariel::Graph g); // returns 1 if the graph is strongly connected and 0 otherwise.
            static string shortestPath(ariel::Graph g, int a, int b); // returns the shortest path (or lightest path) in the graph, if there is not such path, returns -1.
            static bool isContainsCycle(ariel::Graph g); // returns true if there is a cycle in the graph and false otherwise.
            static string isBipartite(ariel::Graph g); // returns the partition of the graph to the bipartite graph, if there is not such partition, returns 0.
            static string negativeCycle(ariel::Graph g); // finds a negative cycle in the graph, if there is no negative cycle, prints that there is not.
    };
}