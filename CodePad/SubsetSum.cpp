// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

#include<vector>
#include<numeric>
using namespace std;

class SubsetSum {

	void solve(vector<int>& arr, int pos, vector<int>& subset, vector<int>& sum, int total) {

		if (pos == arr.size()) {
			sum.push_back(total);
			return;
		}

		// take the current element
		subset.push_back(arr[pos]);
		solve(arr, pos + 1, subset, sum, total + arr[pos]);
		subset.pop_back();

		// don't take it
		solve(arr, pos + 1, subset, sum, total);
	}

public:
	vector<int> subsetSums(vector<int> arr)
	{
		vector<int> sum;
		vector<int> subset;
		solve(arr, 0, subset, sum, 0);
		return sum;
	}
};