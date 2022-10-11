#include<iostream>
#include<vector>

class Solution
{
	void DFS(int node, std::vector<int>& Visited, std::vector<int> adj[], std::vector<int>& DFSresult)
	{
             DFSresult.push_back(node); //push back the current node
	     Visited[node] = 1;        // remark it visited 
             for (auto it : adj[node]) // loop over the neightbors of current node
	     {
		 if (!Visited[it])
		 {
			 DFS(it, Visited, adj, DFSresult);
		 }
	     }
	}
public:
	std::vector<int>DfsOfTotalGraph(int V, std::vector<int> adj[])
	{
		std::vector<int> DFSresult;
		std::vector<int> Visited(V + 1, 0);
		for (int i = 0; i <= V; i++) // in case there are more than one component in the graph
		{
			if (!Visited[i])
			{
				DFS(i, Visited, adj, DFSresult);
			}
		}
		return DFSresult;
	}
};

