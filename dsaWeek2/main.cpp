#include "solutions.h"

int main(){
    Solution s;
    std::cout<<"\nGroup Anagrams\n";
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> grp = s.groupAnagrams(strs);
    for(const auto& p: grp){
        for(const auto& q: p){
            std::cout<<q<<" ";
        }
        std::cout<<"\n";
    }

    std::cout<<"\nK frequent elements:\n";
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> result = s.topKFrequent(nums,2);
    for(const auto& i : result){
        std::cout<< i << " ";
    }

    std::cout<<"\nProduct Except Self:\n";
    nums = {1,2,3,4};
    result = s.productExceptSelf(nums);
    for(const auto& i : result){
        std::cout<< i << " ";
    }
}