#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <utility>
#include <stack>

class Solution
{
    void findTopoSort(int Start, std::vector<int>& Visited, std::vector<std::pair<int,int> > adj[], std::stack<int>& Stack)
	{
		Visited[Start] = 1;

		for (auto it : adj[Start])
		{
			if (!Visited[it.first])
			{
				findTopoSort(it.first, Visited, adj, Stack);
			}
		}
		Stack.push(Start); 

	}
public:
	void shortestPath(int src, int numberOfNodes, std::vector<std::pair<int, int> > adj[])
	{
		std::vector<int> Visited(numberOfNodes + 1, 0);
		std::stack<int> Stack;
		for (int i = 0;i < numberOfNodes;i++)
		{
			if (!Visited[i])
			{
				findTopoSort(i, Visited, adj, Stack);
			}
		}

		std::vector<int> distance(numberOfNodes + 1, INT_MAX);
		distance[src] = 0;

		while (!Stack.empty())
		{
			int node = Stack.top();
			Stack.pop();
			//if the node has been reached prev
			if (distance[node] != INT_MAX)
			{
				for (auto it : adj[node])
				{
					if (distance[node] + it.second < distance[it.first])
					{
						distance[it.first] = distance[node] + it.second;
					}
				}
			}
		}

	}
};


