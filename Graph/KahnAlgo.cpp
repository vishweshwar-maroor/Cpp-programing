/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> result;
        queue<int> q;
        for (auto &p : prerequisites)
        {
            int courses = p[0];
            int prerequisite = p[1];
            adj[prerequisite].push_back(courses);
            indegree[courses]++;
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (int neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        if (result.size() != numCourses)
            return {};
        return result;
    }
};