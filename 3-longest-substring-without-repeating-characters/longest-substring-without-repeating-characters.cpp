class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int ans = 0;
        int left = 0 , right;
        for(right = 0 ; right < n ; right++){
            char c = s[right];
            if(mp.contains(c)){
                left = max(left , mp[c] + 1);
            }
            mp[c] = right;
            ans = max(ans,right - left + 1);
        }

        return ans;
    }
};