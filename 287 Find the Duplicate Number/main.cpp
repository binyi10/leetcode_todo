class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size >= 2)
        {
            int fast = nums[nums[0]];
            int slow = nums[0];
            while(fast != slow)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            
            fast = 0;
            while(fast != slow)
            {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
        
    }
};