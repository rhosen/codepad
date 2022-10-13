// https://leetcode.com/problems/subsets/

#include <vector>
using namespace std;

class Subset {

	void solve(vector<int>& nums, int pos, vector<int>& subset, vector<vector<int>>& result) {

		if (pos == nums.size()) {
			result.push_back(subset);
			return;
		}

		// take current element
		subset.push_back(nums[pos]);
		solve(nums, pos + 1, subset, result);
		subset.pop_back();

		// don't take it
		solve(nums, pos + 1, subset, result);
	}

public:
	vector<vector<int>> subset(vector<int> nums) {
		vector<vector<int>> result;
		vector<int> v;
		solve(nums, 0, v, result);
		return result;
	}
};
