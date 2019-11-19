/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

思路：动态规划，用一个二维数组来记录到达每个节点的最短路径和。从左上角或者从右下角开始本质一样。
状态转移方程为：dp[i][j] = grid[i][j] + min(dp[i + 1][j],dp[i][j + 1]);
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();//行
        int n = grid[0].size();//列
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                else if(i==0) grid[i][j] += grid[i][j-1];
                else if(j==0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);//在原数组上进行该操作，节省了空间，不需要额外数组，复杂度为1          
            }
        }
        return grid[m-1][n-1];
    }
};
