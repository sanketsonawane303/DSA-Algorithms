#include <iostream>
#include <vector>
using namespace std;


// generate all subsets of a given vector

void subsets(int i, vector<int> nums, vector<int> temp, vector<vector<int>> &result) {
    if (i == nums.size()) {
        result.push_back(temp);
        return;
    }

    subsets(i+1, nums, temp, result);
    temp.push_back(nums[i]);
    subsets(i+1, nums, temp, result);
}

int main() {
    vector<int> v = {1, 2, 3};
    vector<vector<int>> result;
    subsets(0, v, {}, result);

    for (auto i: result) {
        for (auto j: i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}
