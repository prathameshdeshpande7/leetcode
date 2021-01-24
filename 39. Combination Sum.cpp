class Solution {
public:
    
    void backTrack(vector<int>& candidates, int index, vector<int>& current, int currentSum, int target, vector<vector<int>>& ans) {
        if (currentSum > target)
            return;
        if (currentSum == target)
        {
            ans.push_back(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++)
        {
            current.push_back(candidates[i]);
            currentSum += candidates[i];
            
            backTrack(candidates, i, current, currentSum, target, ans);
            
            current.pop_back();
            currentSum -= candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;
        
        backTrack(candidates, 0, current, 0, target, ans);
        return ans;
    }
};
