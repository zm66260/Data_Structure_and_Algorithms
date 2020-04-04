// 684 redundant connection
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

// The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

// Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

// Example 1:
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given undirected graph will be like this:
//   1
//  / \
// 2 - 3
// Example 2:
// Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
// Output: [1,4]
// Explanation: The given undirected graph will be like this:
// 5 - 1 - 2
//     |   |
//     4 - 3

// 用并查集查找无向图是否存在环

#include<vector>
#include<map>
using namespace std;

class UF{
public:
    UF(int N){
        for(int i = 0; i < N; i++){
            vertex.insert(pair<int, int>(i, i));
        }
    }

    int find(int p){
        return vertex[p];
    }

    void uniontwo(int p, int q){
        int pID = find(p);
        int qID = find(q);
        if(pID == qID) {return;}
        for(int i = 0; i < vertex.size(); i++){
            if(vertex[i] == pID){vertex[i] = qID;}
        }
        return;
    }

    bool connect(vector<int> edge){
        int pID = find(edge[0]);
        int qID = find(edge[1]);
        if(pID == qID){
            return true;
        }
        return false;

    }

private:
    map<int, int> vertex;

};

class Solution{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int vnum = edges.size() + 1;
        UF vertexset(vnum);
        for(auto edge : edges){
            if(vertexset.connect(edge))
                return edge;
            vertexset.uniontwo(edge[0], edge[1]);
        }
        return {};
    }

};

