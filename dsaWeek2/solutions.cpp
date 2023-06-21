
#include "solutions.h"

using namespace std;


vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {

    vector<vector<string>> anagrams;
    unordered_map<string, vector<string>> mp;
    for(string& i: strs){
        string t = i;
        sort(t.begin(), t.end());
        mp[t].push_back(i);
    }
    for(auto& i : mp){
        anagrams.push_back(i.second);
    }
    return anagrams;
}

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
    std::map<int, int> mp;
    vector<int> op;
    for(int& i : nums){
        mp[i]++;
    }
    for(int i = 0; i < k; i++){
        int large = 0;
        int rmkey;
        for(auto& pair : mp){
            if (pair.second > large) {
            large = pair.second;
            rmkey = pair.first;
            }
        }
        op.push_back(rmkey);
        mp.erase(rmkey);
    }
    return op;
}

vector<int> Solution::productExceptSelf(vector<int>& nums) {
        vector<int> forwardSum;
        vector<int> backwardSum;
        vector<int> result;
        int prod = 1;
        for(int i = 0; i < nums.size(); i++){
            prod *= nums[i];
            forwardSum.push_back(prod);
        }
        prod = 1;
        for(int i = nums.size() - 1; i >= 0 ; i--){
            prod *= nums[i];
            backwardSum.push_back(prod);
        }
        std::reverse(backwardSum.begin(), backwardSum.end());
        result.push_back(backwardSum[1]);
        for (int i = 1; i < nums.size() - 1; i++){
            prod = forwardSum[i-1] * backwardSum[i+1];
            result.push_back(prod);
        }
        result.push_back(forwardSum[nums.size()-2]);
        return result;
}
