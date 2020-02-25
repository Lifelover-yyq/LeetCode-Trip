/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

思路：递归回溯问题，看了解析发现包括全排列等一众问题都是类似的模板去求解，亏了之前做课设还用过全排列，现在才稍微懂了。
*/
class Solution {
public:
    vector<int> candidates;
    vector<int> path;
    vector<vector<int>> ans;
    
    void DFS(int start, int target) {
        if(target == 0) {
            ans.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            int next = target - candidates[i];
            if(next >= 0) {
                path.push_back(candidates[i]);
                DFS(i,next);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0,target);
        return ans;
    }
};
