#include<iostream>
#include<vector>

class Solution
{
	bool CheckCycleDFS(int node, int parent, std::vector<int>& Visited, std::vector<int> adj[])
	{
		Visited[node] = 1;
		for (auto it : adj[node])
		{
			if (!Visited[it])
			{
				if (CheckCycleDFS(it, node, Visited, adj))
				{
					return true;
				}
			}
			else if (it != parent)
			{
				return true;
			}
		}
		return false;
	}

public:
	bool isCycle(int V, std::vector<int> adj[])
	{
		std::vector<int> Visited(V + 1, 0);
		for (int i = 0;i < V;i++)
		{
			if (!Visited[i])
			{
				if (CheckCycleDFS(i, -1, Visited, adj))
				{
					return true;
				}
			}
		}
		return false;
	}
};

