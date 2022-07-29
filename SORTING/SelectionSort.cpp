#include <iostream>
#include <vector>

using std::vector;
using std::cout;

template<typename T>
int find_smallest(vector<T>& arr)
{
	T smallest = arr[0];
	int smallest_index = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			smallest_index = i;
		}
	}
	return smallest_index;
}
template<typename T>
vector<T> SelectionSort(vector<T> arr)
{
	vector<T> Sorted;
	while (!arr.empty())
	{
	int smallest_index = find_smallest(arr);
	Sorted.push_back(arr[smallest_index]);
	arr.erase(arr.begin() + smallest_index);
    }
	return Sorted;
}
int main()
{
	vector<int> V1 = { 1,4,2,5,-1,7,6 };
	vector<int> V2 = SelectionSort(V1);
	auto i = 0;
	for (auto i : V2)
	{
		cout << i << "\n";
	}
}
