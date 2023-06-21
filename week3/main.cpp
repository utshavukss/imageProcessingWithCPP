#include "solutions.h"

using namespace std;

int main(){
    Solution ob;
    cout<<"\nValid Palindrome:\n";
    string s = "A man, a plan, a canal: Panama";
    cout<<"\n"<<(ob.isPalindrome(s)? "True":"False");
    s = "race a car";
    cout<<"\n"<<(ob.isPalindrome(s)? "True":"False");

    cout<<"\nTwo Sums:\n";    
    vector<int> nums = {2,7,11,15};
    nums = ob.twoSum(nums, 9);
    for(int& i : nums){
        cout<<i<<" ";
    }
    nums = {2,3,4};
    nums = ob.twoSum(nums, 6);
    for(int& i : nums){
        cout<<i<<" ";
    }

    cout<<"\nThreeSum\n";
    nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> op = ob.threeSum(nums);
    for(auto& i : op){
        for(int& j : i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }

}