#include<iostream>
#include<vector>
#include<queue>
#include <utility>


class Solution
{
public:
	bool bipartiteBFS(int start, std::vector<int> adj[], std::vector<int>& Color)
	{
		std::queue<int>q;
		q.push(start);
		Color[start] = 1;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			for (auto it : adj[node])
			{
				if (Color[it] == -1)
				{
					Color[it] = 1 - Color[node];
					q.push(it);
				}
				else if (Color[it] == Color[node])
				{
					return false;
				}
			}
		}
		return true;
    }


	bool checkBipartite(std::vector<int> adj[], int n)
	{
		std::vector<int> Color(n+1, -1);
		for (int i = 0;i < n;i++)      //more than component in the graph
		{
			if (Color[i] == -1)
			{
				if (!bipartiteBFS(i, adj, Color))
				{
					return false;
				}
			}
		}
		return true;
	}

};

