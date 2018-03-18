class Solution {
public:
    int binary_search(vector<int>& nums,int number)
    {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == number)return mid;
            else if(nums[mid] < number)
            {
                low = mid+1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> num;
        int size = nums.size();
        if(size <= 1)return size;
        num.push_back(nums[0]);
        for(int i = 1; i < size; i++)
        {
            int number = nums[i];
            int ID = binary_search(num,number);
            if(ID == num.size())
            {
                num.push_back(number);
            }
            else
            {
                num[ID] = number;
            }
        }
        return num.size();
    }
};