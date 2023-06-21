#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char,int> mp;
        if(s.length() != t.length()) return false;

        for(auto it : s){
            mp[it]++;
        }
        for(auto it : t){
            mp[it]--;
        }
       for(auto it : t){
            if(mp[it] != 0) return false;
        }
        return true;
    }
};

int main(){
    std::string s;
    std::string t;
    Solution obj;

    s = "anagram"; t = "nagaram";
    std::cout<<std::endl<<(obj.isAnagram(s,t)? "true":"false");
    s = "rat"; t = "car";
    std::cout<<std::endl<<(obj.isAnagram(s,t)? "true":"false");
}