// https://leetcode.com/problems/permutations/

#include <vector>
#include <unordered_set>
using namespace std;

class Permutation {

	void solveWithoutSpace(vector<int>& nums, int pos, vector<vector<int>>& r) {
		if (pos == nums.size()) {
			r.push_back(nums);
			return;
		}

		// start with all index
		for (int i = pos; i < nums.size(); i++) {
			// swap elements to get permutation
			swap(nums[i], nums[pos]);
			solveWithoutSpace(nums, pos + 1, r);
			swap(nums[i], nums[pos]); // backtrack
		}

	}

	void solve(vector<int>& nums, vector<int>& perm, vector<vector<int>>& r, unordered_set<int>& s) {
		if (perm.size() == nums.size()) {
			r.push_back(perm);
			return;
		}

		// iterate all the elements and take the elements that were not taken
		for (int i = 0; i < nums.size(); i++) {
			// check if the current element is already taken
			if (s.find(nums[i]) == s.end()) {
				// mark the element as taken
				s.insert(nums[i]);
				perm.push_back(nums[i]);
				solve(nums, perm, r, s);
				// backtrack
				perm.pop_back();
				s.erase(nums[i]);
			}
		}

	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> r;
		vector<int> perm;
		unordered_set<int> s;
		//solve(nums, perm, r, s);
		solveWithoutSpace(nums, 0, r);
		return r;
	}
};