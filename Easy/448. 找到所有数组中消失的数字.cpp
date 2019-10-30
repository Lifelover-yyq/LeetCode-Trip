/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务,假定返回的数组不算在额外空间内。
*/
/*
这道题的思路其实很简单，一开始也想的很好。通过不断的交换把数字 a[i] 放到它该去的位置 a[a[i]-1]上去。
最后a[i] != i+1 的位置上就是消失的数字。返回下标 i+1 即可。
然而实现的时候总是报 访问非法内存的错误，看了半天也没找到错在哪，无奈看了解析里的同样思路的代码，确实精简了很多。

还有一种方法是：对于每一个数字，把它对应位置上的数字 +len，最后判断小于 len 的则是消失的数字，省去了交换的步骤。
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        vector<int> ans;
        if(len == 0) return ans;
        for(i=0; i<len; ++i) {
            while(nums[i] != nums[nums[i]-1]) {
              //交换部分使用了C++自带的交换函数，自己写由于额外空间限制不能借助temp变量，要使用异或，而且速度会更快。
              swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int j=0;j<len;++j) {
            if(nums[j] != j+1)
                ans.push_back(j+1);
        }
        return ans;
    }
};
