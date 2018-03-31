class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int first = 0;
        int last = size -1;
        int first_one = -1;
        if(size >= 2)
        {
            while(first <= last )
            {
                while(first <= last && nums[first] <2 )
                {
                    if(first_one == -1)
                    {
                        if(nums[first] == 1)
                        {
                            first_one = first;
                            break;
                        }
                    }
                    if(nums[first] == 0)
                    {
                        if(first_one != -1)
                        {
                            int t = nums[first];
                            nums[first] = nums[first_one];
                            nums[first_one] = t;
                            first_one = first_one + 1;
                        }
                    }
                    first++;
                }
                while(first <= last && nums[first] <2)
                {
                    if(nums[first] == 0)
                    {
                        if(first_one != -1)
                        {
                            int t = nums[first];
                            nums[first] = nums[first_one];
                            nums[first_one] = t;
                            first_one = first_one + 1;
                        }
                    }
                    first++;
                }
                while(first <= last && nums[last] ==2)
                {
                    last--;
                }
                if(first <= last)
                {
                    if(nums[last] == 1)
                    {
                        int t = nums[last];
                        nums[last] = nums[first];
                        nums[first] = t;
                    }
                    else if(nums[last] == 0)
                    {
                        if(first_one == -1)
                        {
                            int t = nums[last];
                            nums[last] = nums[first];
                            nums[first] = t;
                        }
                        else
                        {
                            int t = nums[last];
                            nums[last] = nums[first];
                            nums[first] = t;
                            t = nums[first];
                            nums[first] = nums[first_one];
                            nums[first_one] = t;
                            first_one = first_one + 1;
                        }
                    }
                }
                
            }
        }
        
              
    }
};