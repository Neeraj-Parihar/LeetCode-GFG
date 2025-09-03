class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for(char a : s){
            map1[a]++;
        }
        for(char a : t){
            map2[a]++;
        }
        if(map1==map2)  return true;
        return false;
    }
};