/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行Z字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
输出需要从左往右逐行读取，产生出一个新的字符串，"LCIRETOESIIGEDHN"。
*/
//本题是通过独立思考写出来的，虽然耗时耗内存较大，但比较有意义
class Solution {
public:
    string convert(string s, int numRows) {
        int i,t;
        int len = s.length();
        string ss = "";
        int x = 2*(numRows-1);
        int j = 0;
        if(numRows>=len || numRows == 1)
            return s;
        while(j<len) {//第一行
            ss = ss + s[j];
            j = j + x;
        }
        for(i=1;i<numRows-1;++i) {//第2~n-1行
            t = i;
            while(t < len) {
                ss = ss + (s[t]);
                t = t + x - 2*i;
                if(t < len)
                   ss = ss + (s[t]);
                t = t + 2*i;
            }
            continue;
        }
        j = numRows-1;
        while(j<len) {//第n行
            ss = ss + s[j];
            j = j + x;
        }
        return ss;
    }
};
