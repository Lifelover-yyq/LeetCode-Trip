/*
我是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响我偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
*/
/*
动态规划算法：
n=1时，偷A1
n=2时，偷max(A1,A2)
n=3时，偷A1+A3 或者 A2
动态转移方程为：F(n) = max(F(n-2) + An, F(n-1))
代码实现时取F(-1)=F(0)=0，用两个变量来保存当前最大金额和上一次的最大金额。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int pres = 0;
        int curr = 0;
        int temp;
        for(int i=0;i<nums.size();++i) {
            temp = curr;
            curr = max(pres + nums[i],curr);
            pres = temp;
        }
        return curr;
    }
};
