#include <bits/stdc++.h>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int > mp;
        for(auto a : nums){
            mp[a]++;
        }
        priority_queue<pair< int , int > ,vector<pair<int , int>>, greater<pair<int ,int>>> minHeap;
        for(auto a : mp){
            minHeap.push({a.second, a.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while (!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};