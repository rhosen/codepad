// https://leetcode.com/problems/combination-sum-ii/

#include <vector>
#include <algorithm>
using namespace std;

class DuplicateCombinationSum {

	void solve(vector<int>& candidates, int target, int pos, vector<int>& subset, vector<vector<int>>& result) {

		if (pos == candidates.size() || target <= 0) {
			if (target == 0) result.push_back(subset);
			return;
		}

		// take the current element
		subset.push_back(candidates[pos]);
		solve(candidates, target - candidates[pos], pos + 1, subset, result);
		subset.pop_back();

		// make sure we don't take the duplicate element in the next recursion call
		while (pos + 1 < candidates.size() && candidates[pos] == candidates[pos + 1]) pos++;
		// don't take the current element
		solve(candidates, target, pos + 1, subset, result);
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		// sort the elemens so all the duplicate elements are adjacent 
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> v;
		solve(candidates, target, 0, v, result);
		return result;
	}
};