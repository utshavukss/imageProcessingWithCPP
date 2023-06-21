#include <vector>
#include <iostream>
#include <unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, std::vector<int>> mp;
        int i, tmp;
        for (i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        for(i = 0; i < nums.size(); i++){
            tmp = target - nums[i];
            if(mp.find(tmp) != mp.end()){
                if(tmp == nums[i] && mp[nums[i]].size()>1) return mp[nums[i]];
                if (tmp != nums[i]){
                    int a = nums[i];
                    mp[tmp].insert(mp[tmp].end(), mp[a].begin(), mp[a].end());
                    return mp[tmp];
                }
            }
        }
        return mp[target];
    }
};

int main(){
    std::vector<int> nums = {2, 7, 11, 15};
    Solution obj;
    std::vector<int> output;

    output = obj.twoSum(nums,9);
    for(int i = 0; i < output.size(); i++){
        std::cout<<" "<<output[i];
    }
    std::cout<<std::endl;
    nums = {3, 2, 4};
    output = obj.twoSum(nums, 6);
    for(int i = 0; i < output.size(); i++){
        std::cout<<" "<<output[i];
    }
    std::cout<<std::endl;
    nums = {3,3};
    output = obj.twoSum(nums, 6);
    for(int i = 0; i < output.size(); i++){
        std::cout<<" "<<output[i];
    }
    
   }