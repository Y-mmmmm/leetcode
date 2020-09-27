/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution1 
{
public:
    string replaceSpace(string s) 
    {     //字符数组
        string array;   //存储结果
        
        for(auto &c : s) //遍历s中的每一个字符
        {   //遍历原字符串
            if(c == ' ')
            {
                array.push_back('%');
                array.push_back('2');
                array.push_back('0');
            }
            else{
                array.push_back(c);
            }
        }
        return array;
    }
};


class Solution2 
{
public:
    string replaceSpace(string s) 
    {
        string res;
        for(auto c : s)
        {
            if(c == ' ')
                res += "%20";
            else
                res += c;
        }
        return res;
    }
};

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length <= 0)
            return;
        int space_cnt=0;
        for(int i=0;i<length;i++)
        {
            if(str[i] == ' ')
                space_cnt++;
        }
        if(space_cnt == 0)
            return;
        int newlen = length + space_cnt*2;//没有将\0算在内，应该是length传进来的时候算上了\0
        for(int i=length;i>=0;i--)
        {
            if(str[i] == ' ')
            {
                str[newlen--] = '0';
                str[newlen--] = '2';
                str[newlen--] = '%';
            }
            else
            {
                str[newlen--] = str[i];
            }
        }

	}
};



int main()
{
    string ss="We are Happy";
    Solution2 obj;
    cout<<obj.replaceSpace(ss)<<endl;

    return 1;
}
