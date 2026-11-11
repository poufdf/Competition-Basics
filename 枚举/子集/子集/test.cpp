#define _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;
//https://leetcode.cn/problems/subsets/submissions/759700430/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    temp.push_back(nums[j]);
                }

            }
            ret.push_back(temp);
        }
        return ret;
    }
};