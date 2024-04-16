class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans[n];
        int max = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(max<height[i]) max = height[i];
            ans[i] = max;
        }
        max = 0;
        int sol = 0;
        for(int i=0;i<n;i++)
        {   if(max<height[i]) max = height[i];
            sol+=min(max,ans[i])-height[i];
        }

        return sol;
    }
};