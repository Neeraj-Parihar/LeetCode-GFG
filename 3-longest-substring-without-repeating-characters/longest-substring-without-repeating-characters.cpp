class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0 , right , ans = 0;

        unordered_map<char,int> mp;

        for(right = 0 ; right < s.length() ; right++){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};