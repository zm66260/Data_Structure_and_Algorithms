// 207 course schedule
// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:

// Input: 2, [[1,0]] 
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.


// DAG directed acycle graph store as edge

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjacentList(numCourses, vector<int>());
        if(prerequisites.size() == 0){return true;}

        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
            adjacentList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0 ){
                q.push(i);}
        }

        vector<int> rest;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            rest.push_back(course);
            for(int adj : adjacentList[course]){
                inDegree[adj]--;
                if(inDegree[adj]==0){q.push(adj);}
            }
        }

        if(rest.size() == numCourses){return true;}
        return false;

    }
};