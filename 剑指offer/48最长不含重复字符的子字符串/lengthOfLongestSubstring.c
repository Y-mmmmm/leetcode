#include <stdio.h>
#include <string.h>

/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

*/



/*
tail 指针右移，判断 tail 指向的元素是否在 [head:tail] 的窗口内；

    如果窗口中没有该元素，则将该元素加入窗口，同时更新窗口长度最大值，tail 指针继续右移；
    如果窗口中存在该元素，则将 head 指针右移，直到窗口中不包含该元素。<--这里注意，头指针要一直移动到不重复才停止

*/


#define myMAX(a, b)      ((a) > (b)? (a) : (b))

//【算法思路】hash+双指针。hash记录个数，重复即判断是否有2.
//先移动右指针，到重复为止，再移动左指针到不重复为止。
//注意字符为大小写

#define myMax(a,b)  (a)>(b)?(a):(b)

int lengthOfLongestSubstring(char* s){
    int len = strlen(s);
    if(s == NULL || len == 0)   return 0;

    int head = 0;
    int tail = 0;
    int repeat_cnt = 0; /*重复计数器*/
    int res = 0;

    int hash[128] = {0};/*128个字符的哈希表*/

    int subLen = 0;/*子串长度*/

    for(tail = 0; tail < len;tail++)
    {
        hash[s[tail]]++; /*将当前tail指向位置的字符哈希值+1*/

        repeat_cnt += hash[s[tail]] == 2 ? 1 : 0; /*当前字符哈希值=2说明重复了一个，重复计数器+1*/

        if(repeat_cnt == 0) continue;/*没有重复跳过下面的步骤，重新循环*/

        /*有重复，计算当前子串长度，数组下标计数法*/
        subLen = tail - head;
        res = myMax(res,subLen);

        /*扫描子串，找到重复的字符，然后将头指针移动到不重复的位置*/
        for(int i=head;i<tail;i++)
        {
            hash[s[i]]--;/*子串的每个字符哈希值都要减*/
            repeat_cnt -= hash[s[i]] == 1? 1:0;/*只有重复字符的哈希值减后=1，也就是检测到重复的字符，将重复计数器值减1*/
            if(repeat_cnt == 0)
            {
                head = i + 1;/*head 指针跳跃到重复字符的下一位*/
                break;
            }
        }
    }

    /*tail已经遍历完字符串，再计算当前最大长度*/
    subLen = tail - head;
    res = myMax(res,subLen);

    return res;
}

//------------------------------------------
//效率不高但容易理解的方法

/* 滑动窗口解法 */

int lengthOfLongestSubstring(char* s){
    /* 采用哈希数组表示每个字符出现的次数，大于1时则认为出现重复字符 */
    int windows[128] = {0};

    /* 滑动窗口的左标和右标 */
    int left = 0; 
    int right = 0;
    int max = 0;
    int sublen;
    int len = strlen(s);

    while (right < len) 
    {
        windows[s[right]]++; /* 右值添加进窗口 */  

        /* 如果出现重复字符（满足条件），则left右移，缩小窗口 */
        while(s[right] != '\0' && windows[s[right]] > 1) 
        {
            windows[s[left]]--; /* 左值移出窗口 */
            left++;
        }
        sublen = right - left + 1;
        max = max > sublen ? max :sublen; /* 获取结果 */
        right++; /* 继续右移窗口 */
    }
    return max;
} 
