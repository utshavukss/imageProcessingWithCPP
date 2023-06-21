#include <iostream>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int i,j, temp;

        
        for(i = 0; i < s.length(); i++){
            for(j = i+1; j<s.length(); j++){
                if(s[i]>s[j]){
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
        for(i = 0; i < t.length(); i++){
            for(j = i+1; j<t.length(); j++){
                if(t[i]>t[j]){
                    temp = t[i];
                    t[i] = t[j];
                    t[j] = temp;
                }
            }
        }
        if(s == t) return true;
        else return false;
    }
};