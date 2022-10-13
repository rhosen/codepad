// https://leetcode.com/problems/subsets-ii/

#include <vector>
#include <algorithm>
using namespace std;

class DuplicateSubset {

	void solve(vector<int>& nums, int pos, vector<int>& subset, vector<vector<int>>& result) {

		if (pos == nums.size()) {
			result.push_back(subset);
			return;
		}

		// take current element
		subset.push_back(nums[pos]);
		solve(nums, pos + 1, subset, result);
		subset.pop_back();


		// make sure we don't take the duplicate element in the next recursion call
		while (pos + 1 < nums.size() && nums[pos] == nums[pos + 1]) pos++;
		// don't take the current element
		solve(nums, pos + 1, subset, result);
	}

public:
	vector<vector<int>> subset(vector<int> nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> v;
		solve(nums, 0, v, result);
		return result;
	}
};