/*
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
给出两个整数 x 和 y，计算它们之间的汉明距离。
注意：
0 ≤ x, y < 231.
*/
/*
很简单的一道题，两个数先异或，然后判断得到的结果二进制有多少个1即可。与1 然后右移。
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int c = 0;
        while(z) {
            c += z&1;
            z = z >> 1;
        }
        return c;
    }
};
