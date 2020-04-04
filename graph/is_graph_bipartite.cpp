//785 is graph bipartite?
// Given an undirected graph, return true if and only if it is bipartite.

// Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

// The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

// Example 1:
// Input: [[1,3], [0,2], [1,3], [0,2]]
// Output: true
// Explanation: 
// The graph looks like this:
// 0----1
// |    |
// |    |
// 3----2
// We can divide the vertices into two groups: {0, 2} and {1, 3}.
// Example 2:
// Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
// Output: false
// Explanation: 
// The graph looks like this:
// 0----1
// | \  |
// |  \ |
// 3----2
// We cannot find a way to divide the set of nodes into two independent subsets.

// UCG undirected cycle graph store as vertex

#include<vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N, -1);
        for(int i = 0; i < N; i++){
            if(color[i]==-1 && !dfs(graph, color, 0, i))
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& colorarray, int color, int vertex){
        if(colorarray[vertex] != -1)
            return colorarray[vertex] == color;

        colorarray[vertex] = color;
        for(int nextvertex : graph[vertex]){
            if(!dfs(graph, colorarray, 1-color, nextvertex))
                return false;
        }
        return true;
    }
};
