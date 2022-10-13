// https://leetcode.com/problems/permutations/

#include <vector>
#include <unordered_set>
using namespace std;

class Permutation {

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
        solve(nums, perm, r, s);
        return r;
    }
};