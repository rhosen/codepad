// https://leetcode.com/problems/combination-sum/

#include <vector>
using namespace std;

class CombinationSum {

	void solve(vector<int>& candidates, int target, int pos, vector<int>& subset, vector<vector<int>>& result) {
		if (pos == candidates.size() || target <= 0) {
			if (target == 0) result.push_back(subset);
			return;
		}

		// take current element
		if (candidates[pos] <= target) {
			subset.push_back(candidates[pos]);
			solve(candidates, target - candidates[pos], pos, subset, result);
			subset.pop_back();
		}

		// don't take it
		solve(candidates, target, pos + 1, subset, result);
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> v;
		solve(candidates, target, 0, v, result);
		return result;
	}
};