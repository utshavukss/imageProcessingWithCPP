//bruteForceApproach
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        std::vector<int> output;

        for (i = 0; i<nums.size(); i++){
            for (j = i+1; j<nums.size(); j++){
                if (nums[i]+nums[j] == target ){
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
            }
        }
    return output;
    }
};