/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

题目里也给出了一个直观的思路，统计数组中012出现的次数，然后按顺序重写数组即可，这样需要两次遍历数组。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red,white,blue;
        red = 0;
        white = 0;
        blue = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == 0) red++;
            if(nums[i] == 1) white++;
            if(nums[i] == 2) blue++;
        }
        white += red;
        blue += white;
        int j = 0;
        while(j < nums.size()) {
            if(j < red) nums[j] = 0;
            if(j >= red && j < white) nums[j] = 1;
            if(j >= white && j < blue) nums[j] = 2;
            j++;
        }
    }
};
