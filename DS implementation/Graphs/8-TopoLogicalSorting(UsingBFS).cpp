#include<iostream>
#include<vector>
#include<queue>
#include <utility>
#include <stack>


class Solution
{
public:
     
    std::vector<int> topoSort(int N, std::vector<int> adj[])
    {
        std::queue<int> Queue;
        //first we will calculate indegree of every Node
        /*
        * Example :
        * 0 -> -
        * 1 -> -
        * 2 -> 3
        * 3 -> 1
        * 4 -> 0 , 1
        * 5 -> 0 , 2
        */
        std::vector<int> inDegree(N + 1, 0);
        for (int i = 0; i < N;i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it] ++;
            }
        }
        //Then we will push Node with zero degree into out Queue
        for (int i = 0; i < N;i++)
        {
            if (inDegree[i] == 0)
            {
                Queue.push(i);
            }
        }
        //Third we will process our nodes (-1 for indegree every time we visit it node to remove dependency )
        std::vector<int> topoResult;
        while (!Queue.empty())
        {
            int node = Queue.front();
            Queue.pop();
            topoResult.push_back(node);
            
            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    Queue.push(it);
                }
            }
        }
        return topoResult;
    }
};

