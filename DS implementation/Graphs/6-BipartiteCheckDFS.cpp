#include<iostream>
#include<vector>
#include<queue>
#include <utility>


class Solution
{
public:
	bool bipartiteDFS(int start, std::vector<int> adj[], std::vector<int>& Color)
	{
		if (Color[start] == -1) Color[start] = 1;

		for (auto it : adj[start])
		{
			if (Color[it] == -1)
			{
				Color[it] = 1 - Color[start];
				if (!bipartiteDFS(it, adj, Color))
				{
					return false;
				}
			}
			else if (Color[it] == Color[start])
			{
				return false;
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
				if (!bipartiteDFS(i, adj, Color))
				{
					return false;
				}
			}
		}
		return true;
	}

};

