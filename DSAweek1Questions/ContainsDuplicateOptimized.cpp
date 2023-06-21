#include <iostream>
#include <unordered_map>
#include<vector>

class Solution{
    public:
    bool ContainsDuplicate(std::vector<int>& nums){
        int i;
        std::unordered_map<long, long> mp;
        for(i = 0; i < nums.size(); i++){
            if(++mp[nums[i]]>1) return true;
        }
        return false;
    }
};

int main(){
    std::vector<int> nums = {1,2,3,1};
    Solution obj;
    std::cout<<std::endl<<(obj.ContainsDuplicate(nums)?"true":"false");

    nums = {1,2,3,4};
    std::cout<<std::endl<<(obj.ContainsDuplicate(nums)? "true":"false");

    nums = {1,1,2,1,3,3,3,4,5,1};
    std::cout<<std::endl<<(obj.ContainsDuplicate(nums)?"true":"false");

   }