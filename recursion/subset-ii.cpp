#include <bits/stdc++.h>
using namespace  std;
//-------------------------------------
void subsetWithDup(map<int, int>& freq, map<int, int>::iterator itr,
                   vector<int>& setSoFar, vector<vector<int>>& powerSet) {
    if (itr == freq.end()) {
        powerSet.push_back(setSoFar);
        return;
    }
    int num = itr->first, fq = itr->second;
    ++itr;
    subsetWithDup(freq, itr, setSoFar, powerSet);
    for (int i = 0; i < fq; i++) {
        setSoFar.push_back(num);
        subsetWithDup(freq, itr, setSoFar, powerSet);
    }
    for (int i = 0; i < fq; i++) {
        setSoFar.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> powerSet;
    map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    vector<int> setSoFar;
    subsetWithDup(freq, freq.begin(), setSoFar, powerSet);
    return powerSet;
}
//-------------------------------------
void subsetWithDup(vector<int>& nums, int idx, vector<int>& setSoFar, vector<vector<int>> powerSet) {
    powerSet.push_back(setSoFar);

    for (int i = idx; i < nums.size(); i++) {
        if (i > idx && nums[i] == nums[i - 1]) continue;
        setSoFar.push_back(nums[i]);
        subsetWithDup(nums, idx + 1, setSoFar, powerSet);
        setSoFar.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> powerSet;
    vector<int> setSoFar;
    sort(nums.begin(), nums.end());
    subsetWithDup(nums, 0, setSoFar, powerSet);
    return powerSet;
}
