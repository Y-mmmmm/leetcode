#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0){
            return 0;
        }
        
        int n = nums.size();
        vector<int> left_max = nums;
        vector<int> right_max = nums;
        
        left_max[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            left_max[i] = max(nums[i], left_max[i - 1] + nums[i]);
        }
        
        right_max[n - 1] = nums[n - 1];
        
        for(int i = n - 2; i >= 0; i--){
            right_max[i] = max(nums[i], right_max[i + 1] + nums[i]);
        }
        
        vector<int> prefix = left_max;
        vector<int> postfix = right_max;
        
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i - 1], prefix[i]);
        }
        
        for(int i = n - 2; i >= 0; i--){
            postfix[i] = max(postfix[i + 1], postfix[i]);
        }
        
        int result = INT_MIN;
        for(int i = 0; i < n - 1; i++){
            result = max(result, prefix[i] + postfix[i + 1]);
        }
        
        return result;
        
        
    }
};

