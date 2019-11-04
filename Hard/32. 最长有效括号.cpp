/*
题目：
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

思路：
1、很容易想到用栈来处理，遇到左括号push，遇到右括号跟栈top比较，如果是'('，则+2并pop，不等则下一个，过程中不断比较更新max值。见解法1。
2、结果发现这样只能得到所有有效的括号数量，如果它们不连续就会出错，比如"()(()"这个就会输出4而不是2。
3、解析里同样有使用栈的解法，不过不是对括号字符进行操作，而是对其下标进行操作，计算方法很巧妙，见解法2。
4、还有一种方法用L R两个计数器，不需使用额外空间，可以说更nb了。见解法3。
*/

//解法1 理解错题意的版本
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int sum = 0;
        stack<char> a;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '(')
                a.push(s[i]);
            else if(s[i] == ')') {
                if(a.empty())
                    continue;
                if(a.top() != '(') {
                    ans = ans>=sum ? ans:sum;
                    sum = 0;
                }
                    
                if(a.top() == '(') {
                    sum += 2;
                    ans = ans>=sum ? ans:sum;
                    a.pop();
                }
            }
                
        }
        return ans;
    }
};

//解法2 用栈处理字符下标
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> a;
        a.push(-1);
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '(')
                a.push(i);
            else {
                a.pop();
                if (a.empty()) {
                    a.push(i);
                } else {
                    ans = max(ans, i - a.top());
                }
            }   
        }
        return ans;
    }
};

//解法3 使用Left 和 Right 两个计数器
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};
