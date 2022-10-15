#include<iostream>
#include<vector>
#include<queue>
#include <utility>


class Solution
{
	bool CheckCycleBFS(int Start, std::vector<int> adj[], std::vector<int>& Visited)
	{
		std::queue<std::pair<int, int>> Queue;
		Visited[Start] = true;
		Queue.push({ Start,-1 });

		while (!Queue.empty())
		{
			int node = Queue.front().first;
			int parent = Queue.front().second;
			Queue.pop();

			for (auto it : adj[node])
			{
				if (!Visited[it])
				{
					Visited[it] = true;
					Queue.push({ it,parent });
				}
				else if (it != parent)
				{
					return true;
				}
			}
        }
		return false;
	}

public:
	bool isCycle(int V, std::vector<int> adj[])
	{
		std::vector<int> Visited(V + 1, 0);
		for (int i = 1;i <= V;i++)
		{
			if (!Visited[i])
			{
				if (CheckCycleBFS(i, adj, Visited)) return true;
			}
		}
		return false;
	}
};

