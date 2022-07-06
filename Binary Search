#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using std::sort;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;

template <typename T>
int BinarySearch(vector<T> v, int item)
{
	int low = 0;
	int high = v.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		T guess = v[mid];
		if (guess == item)
		{
			return mid;
		}
		if (guess > item)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;

}
int main()
{
	vector<int> v = { 1,2,3,4,5,6 };
	cout <<BinarySearch(v, 5) << "\n";
}
