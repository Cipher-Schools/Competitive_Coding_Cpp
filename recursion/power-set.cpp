#include <bits/stdc++.h>
using namespace std;

void getPowerSet(vector<int>&vec, vector<vector<int>>& res, vector<int>& setSoFar, int len, int index) {
    if (index >= len) {
        res.push_back(setSoFar);
        return;
    }
    setSoFar.push_back(vec[index]);
    getPowerSet(vec, res, setSoFar, len, index + 1);
    setSoFar.pop_back();
    getPowerSet(vec, res, setSoFar, len, index + 1);
}

vector<vector<int>> getPowerSet(vector<int>& vec) {
    if (vec.empty()) return {};
    vector<vector<int>> result;
    vector<int> setSoFar;
    getPowerSet(vec, result, setSoFar, vec.size(), 0);
    return result;
}

int main() {
    vector<int> vec = {1, 2, 3};
    auto ans = getPowerSet(vec);
    for (auto &item : ans) {
        for (auto &num : item) cout << num <<  " " ;
        cout << endl;
    }
}