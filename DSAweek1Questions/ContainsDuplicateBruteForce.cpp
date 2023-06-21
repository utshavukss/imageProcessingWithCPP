//This is a brute force approach to the contains duplicate problem which exceeded the time limit at leetcode
#include<vector>
#include<iostream>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        int i = 0, j;
        for(;i<nums.size();i++){
            for(j = i + 1; j<nums.size();j++){
                if(nums[i]==nums[j]) return true;
            }
        }
        return false;
    }
};