class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        unordered_map<char,int> map;
        for(char a : s) map[a]++;
        for(char a : t) map[a]--;
        
        for(auto a : map){
            if(a.second!=0) return false;
        }
        return true;
    }
};