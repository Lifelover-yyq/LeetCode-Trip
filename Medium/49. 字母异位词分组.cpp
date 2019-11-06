/*
题目：
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
示例如下:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

思路：
1、使用map构建一个映射，将字符串排序后的值作为key，字符串本身为value。
2、遍历所给的数组，将每个字符串加入到map对应位置，最后将map中所有value放到vector返回。
通过本题熟悉了vector和map的遍历方法。
*/
//题解
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        vector<vector<string>> ans;
        for(auto i:strs) {
            string tmp = i;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(i);
        }
        map<string,vector<string>>::iterator it;
        for(it = m.begin(); it != m.end(); ++it)
            ans.push_back(it->second);
        return ans;
    }
};

//使用for循环auto进行遍历
    vector<int> v;
    map<int, string> m;
    for(auto i : v)
        i = 0;
    for(auto &j : m)
        key = j.first,value = j.second;
        
//使用迭代器iterator进行遍历
    vector<int> v;
    map<int, string> m;
    vector<int>::iterator viter;
    for(viter = v.begin(); viter != v.end(); ++viter)
        *viter = 0;
    map<int, string>::iterator miter;
    for(miter = m.begin(); miter != m.end(); ++miter)
        key = m->first, value = m->second;
        
