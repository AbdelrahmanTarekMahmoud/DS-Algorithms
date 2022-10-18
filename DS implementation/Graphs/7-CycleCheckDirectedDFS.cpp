#include<iostream>
#include<vector>
#include<queue>
#include <utility>


class Solution
{
public:
	bool CyclicDFS(int Start, std::vector<int> adj[], std::vector<int>& Visited, std::vector<int>& DFSVisited)
	{
		Visited[Start] = 1;
		DFSVisited[Start] = 1;
		
		for (auto it : adj[Start])
		{
			if (!Visited[it])
			{
				if (CyclicDFS(it, adj, Visited, DFSVisited))
				{
					return true;
				}
			}
			else if (DFSVisited[it])
			{
				return true;
			}
		}
		DFSVisited[Start] = 0;
		return false;
	}


	bool isCyclic(int V, std::vector<int> adj[])
	{
		std::vector<int> Visited(V + 1, 0);
		std::vector<int> DFSVisited(V + 1, 0);

		for (int i = 0;i < V;i++)
		{
			if (!Visited[i])
			{
				if (CyclicDFS(i, adj, Visited, DFSVisited))
				{
					return true;
				}
			}
		}
		return false;
    }

};

