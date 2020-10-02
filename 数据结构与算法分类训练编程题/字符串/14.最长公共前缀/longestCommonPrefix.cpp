/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"

示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:

所有输入只包含小写字母 a-z 。

*/

/*
思路：纵向扫描

依次比较每一列，只有每一列都相同才继续比较下一列，直到出现不同的元素

*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())   return "";

        int len = strs[0].size();
        int strsSize = strs.size();
        //按列比较，直到某一列不一样或者某一行长度到头了，返回公共前缀
        for (int i = 0; i < len; i++) 
        {
            char c = strs[0][i];
            for (int j = 1; j < strsSize; j++) 
            {
                if (i == strs[j].size() || strs[j][i] != c) 
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

