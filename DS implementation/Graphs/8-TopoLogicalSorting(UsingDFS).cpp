#include<iostream>
#include<vector>
#include<queue>
#include <utility>
#include <stack>


class Solution
{
	void findTopoSort(int Start, std::vector<int>& Visited, std::stack<int>& Stack, std::vector<int> adj[])
	{
		Visited[Start] = 1;

		for (auto it : adj[Start])
		{
			if (!Visited[it])
			{
				findTopoSort(it, Visited, Stack, adj);
			}
		}
		Stack.push(Start); //only difference between DFS and Topo using DFS

	}

public:
	std::vector<int> topoSort(int N, std::vector<int> adj[])
	{
		std::stack<int> Stack;
		std::vector<int> Visited(N + 1, 0);
        
		for (int i = 0;i < N;i++)
		{
			if (!Visited[i])
			{
				findTopoSort(i, Visited, Stack, adj);
			}
		}
		std::vector<int> TopoResult;
		while (!Stack.empty())
		{
			TopoResult.push_back(Stack.top());
			Stack.pop();
		}
		return TopoResult;
	}





};

