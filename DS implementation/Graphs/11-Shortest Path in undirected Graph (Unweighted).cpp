#include <iostream>
#include <limits>
#include <vector>
#include <queue>

class Solution
{
public:
	void BFS(std::vector<int> adj[], int N, int src)
	{
		std::vector<int> distance(N + 1, INT_MAX);
		std::queue<int> Queue;
		distance[src] = 0;
		Queue.push(src);

		while (!Queue.empty())
		{
			int node = Queue.front();
			Queue.pop();
			for (auto it : adj[node])
			{
				if (distance[node] + 1 < distance[it])
				{
					distance[it] = distance[node] + 1;
					Queue.push(it);
				}
			}
		}

	}
};


