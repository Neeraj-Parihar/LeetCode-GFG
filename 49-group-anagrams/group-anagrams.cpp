class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string , vector< string > > mp;

        for(auto s : strs){
            vector< int > count (26,0);
            for(char c : s){
                count[c - 'a']++;
            }
            string key="";
            
            for (int i=0; i< 26; i++){
                key += to_string(count[i]) + '#';
            }
            mp[key].push_back(s);

        }
        vector<vector<string>> ans;
        for( auto &p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};