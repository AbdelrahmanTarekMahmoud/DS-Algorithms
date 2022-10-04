#include <iostream>
#include <vector>
#include <queue>
class solution
{
 public:
	std::vector<int>BFS(int V, std::vector<int> adj[])
	{
		std::vector<int> BFSresult;
		std::vector<int> Visited(V + 1, 0); 
		for (int i = 1; i <= V;i++)
		{
			if (!Visited[i])
			{
				std::queue<int> Queue;
				Queue.push(i);
				Visited[i] = 1;
				while (!Queue.empty())
				{
					int Node = Queue.front();
					Queue.pop();
					BFSresult.push_back(Node);

					for (auto it : adj[Node])
					{
						if (!Visited[it])
						{
							Queue.push(it);
							Visited[it] = 1;
						}
					}
				}
			}
		}
		return BFSresult;
	}
};
