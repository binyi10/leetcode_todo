class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> num;
        int size = nums.size();
        if(size <= 1)return size;
        int result = 1;
        num.push_back(1);
        for(int i = 1; i < size; i++)
        {
            int number = nums[i];
            int max = 1;
            for(int j = i -1 ; j>=0;j--)
            {
                if(nums[j] < nums[i])
                {
                    max = max > (num[j]+1) ? max : (num[j]+1);
                }
            }
            num.push_back(max);
            result = result > max ? result:max;
        }
        return result;
    }
};