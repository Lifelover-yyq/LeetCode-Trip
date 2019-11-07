/*
题目:
给出一个区间的集合，请合并所有重叠的区间。
示例:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

思路：
先对数组按照第一个数字进行排序，然后对于相邻的两个区间ab，若有：
a[1] >= b[0]
则两区间重叠，将他们合并。
合并后的区间：left=a[0],right=max(a[1],b[1])。
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.size() == 0)
            return ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        vector<int> tmp = {0,0};
        
        while(i < intervals.size()) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            
            while(i < intervals.size() - 1 && right >= intervals[i+1][0]) {
                ++i;
                right = max(right, intervals[i][1]);
            }
            ++i;
            tmp[0] = left;
            tmp[1] = right;
            ans.push_back(tmp);
        }
        return ans;
    }
};
