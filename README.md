# LeetCode-Trip
**LeetCode刷题代码，大佬勿入。**
* 为一年后的研究生找工作准备
* 目标是BAT的算法岗哈哈哈哈哈
* 争取做到每日一更
* 嗯……
* 19.10.22：鸽了这么久，我又回来了……主要在实验室天天没啥事，过于佛系，刷刷题吧……
* 20.02.26: 再次鸽了四个多月……受疫情影响，本该在学校的时间却还待在家里。真的该准备找工作了，一边准备竞赛，一边每天至少一道题，并直接写到README里。
* 此后超链接均指向原题目地址。

## Easy
- [20. Valid Parentheses]
- [21. Merge Two Sorted Lists]
- [53. Maximum Subarray]
- [70. Climbing Stairs]
- [101. Symmetric Tree]
- [104. Maximum Depth of Binary Tree]
- [121. Best Time to Buy and Sell Stock]
- [167. Two Sum II - Input array is sorted]

## Medium
- [2. Add Two Numbers]
- [3. Longest Substring Without Repeating Characters]
- [5. Longest Palindromic Substring]
- [11. Container With Most Water]
- [15. 3Sum]
- [17. Letter Combinations of a Phone Number]
- [19. Remove Nth Node From End of List]
- [22. Generate Parentheses]
- [31. Next Permutation]
- [33. Search in Rotated Sorted Array]
- 34. Find First and Last Position of Element in Sorted Array
### [46. 全排列](https://leetcode-cn.com/problems/permutations/)
- 题目描述：给定一个没有重复数字的序列，返回其所有可能的全排列。
- 示例:
```
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```
- 思路：递归回溯问题，本科课设2的时候用过，昨天刷的组合总和问题的同类问题，可以套用固定模板。代码如下：
```cpp
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    int len;
    
    void DFS(vector<int> nums, int len) {
        if(path.size() == len) {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++) {          
            path.push_back(nums[i]);            
            vector<int> tmp = nums;
            tmp.erase(tmp.begin()+i);
            DFS(tmp,len);
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        this->len = nums.size();
        DFS(nums,nums.size());
        return ans;
    }
};
```
### [48. 旋转图像](https://leetcode-cn.com/problems/rotate-image/)

- [55. Jump Game]
- [62. Unique Paths]

## Hard
- [4. Median of Two Sorted Arrays]
