/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。
*/

//由于数组一定非空且存在众数，本题可以用很简单的方法求解。原本的思路是：用一个map来存储每个元素出现的次数，然后排序找到最大的value对应的key。
//题解里给出一种类似消消乐的解法，假定第一个数为众数，计数器count = 1，每遇到同样的数count + 1，否则count - 1，count减为 0 则取新的数为众数，
//由于众数的个数一定大于非众数，每次消去时也不用担心众数被消去，剩下的众数永远比非众数多。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int count = 1;
        int ans = nums[0];
        for(int i=1;i<nums.size();++i) {
            if(count == 0) {
                ans = nums[i];
                count++;
                continue;
            }
            if(nums[i] == ans)
                count++;
            else
                count--;
            
        }
        return ans;
    }
};
