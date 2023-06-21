#include "solutions.h"


using namespace std;

bool Solution::isPalindrome(string s) {
    for (char& c: s){
        c = tolower(c);
    }
    int start = 0;
    int end = s.length() - 1;
    while(start < end){
        if ((s[start] < 48 || s[start] > 57) && (s[start] < 97 || s[start] > 122)) {
            start++;
            continue;
        }
        if ((s[end] < 48 || s[end] > 57) && (s[end] < 97 || s[end] > 122)) {
            end--;
            continue;
        }
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

vector<int> Solution::twoSum(vector<int>& numbers, int target){
    map<int, vector<int>> mp;
    for(int i = 0; i < numbers.size(); i++){
        mp[numbers[i]].push_back(i+1);
    }
    for(int i = 0; i < numbers.size(); i++){
        int temp = target - numbers[i];
        if(mp.find(temp)!= mp.end()){
            if(temp == numbers[i]) return mp[temp];
            mp[numbers[i]].insert(mp[numbers[i]].end(), mp[temp].begin(), mp[temp].end());
            return mp[numbers[i]];
        }
    }
    return mp[numbers[0]];
}

/* Two pointers approach:
int i = 0;
    int j = numbers.size() - 1;
    vector<int> result;
    while(i < j){
        if (numbers[i] + numbers[j] > target){
            j--;
            continue;
        }
        if (numbers[i] + numbers[j] < target){
            i++;
            continue;
        }
        else{
            result.push_back(i+1);
            result.push_back(j + 1);
            return result;
        }
    }

*/

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1;
        int k = nums.size() - 1;
        int sum = 0;
        while(j < k){
            sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
                continue;
            }
            if(sum > 0){
                k--;
                continue;
            }
            else{
                result.push_back({nums[i], nums[j], nums[k]});
                int low = j, high = k;
                while(j < k && nums[j] == nums[low]) j++;
                while(j<k && nums[k] == nums[high]) k--;
            }
        }
    }
    return result;
}