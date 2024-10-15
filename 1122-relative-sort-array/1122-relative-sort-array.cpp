class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//map to store the frequency
        map<int,int>mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
//Storing elements present in arr2 in their relative order
        vector<int>arr3;
        for(int i=0;i<arr2.size();i++){
            if(mp[arr2[i]]>0){
                while(mp[arr2[i]]--){
                    arr3.push_back(arr2[i]);
                }
            }
        }
//Storing remaining elements
        map<int,int> ::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second>0){
                int i=it->second;
                while(i--){
                    arr3.push_back(it->first);
                }
            }
        }
        return arr3;
    }
};