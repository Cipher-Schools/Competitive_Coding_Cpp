#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return true;
        } else {
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
            return false;
        }
    }
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        bool isFalse = nextPermutation(nums);
        result.push_back(nums);
        while(!isFalse) {
            isFalse = nextPermutation(nums);
            result.push_back(nums);
        }
        return result;
    }

};

// ------ Map Solution
class Solution1 {
public:
    void permuteUnique(unordered_map<int, int>& freq, int idx, const int N, vector<int>& permutation,
                    vector<vector<int>>& uniqPermutations) {
        if (idx == N) {
            uniqPermutations.push_back(permutation);
            return;
        }

        for (auto itr = freq.begin(); itr != freq.end(); itr++) {
            if (itr->second > 0) {
                itr->second--;
                permutation[idx] = itr->first;
                permuteUnique(freq, idx + 1, N, permutation, uniqPermutations);
                itr->second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        vector<vector<int>> uniqPermutations;
        vector<int> permutation(nums.size());
        permuteUnique(freq, 0, nums.size(), permutation, uniqPermutations);
        return uniqPermutations;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);
    for (auto res: result) {
        for (int n : res) {
            cout << n << ", ";
        }
        cout << "\n";
    }
}
