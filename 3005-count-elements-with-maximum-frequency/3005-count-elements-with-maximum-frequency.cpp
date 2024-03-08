class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;//declare map 

        int max=0,c=0;//initialize variable
        
        for(int i=0;i<nums.size();i++){

            m[nums[i]]++; //storing the key and values !!
            if(max<m[nums[i]]){   //compare that the max frequncy is maximun or not !!
                max=m[nums[i]];c=0;}//if not restart the counting of max frequency variables  !!
            if(m[nums[i]]==max)c++; // count variables with max frequencies  !!
        }
        
        return max*c;// total no. of elements= frequency* no.of elements have that frequncy !!

    }
};