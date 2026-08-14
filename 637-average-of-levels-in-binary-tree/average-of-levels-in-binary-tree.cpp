/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            vector<int> level;
            for(int i = 0 ; i < size ; i++){
                TreeNode*  node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            int n = level.size();
            double sum = 0;
            for(auto num : level){
                sum+=num;
            }
            cout<<sum<<endl;
            ans.push_back(sum / n);

        }
        return ans;        
    }
};