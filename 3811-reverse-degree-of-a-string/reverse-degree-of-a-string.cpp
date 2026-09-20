class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            ans+= (26 - (c - 'a')) * (i + 1);
        }
        return ans;
    }
};