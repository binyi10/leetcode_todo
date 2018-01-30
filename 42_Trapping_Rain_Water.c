int trap(int* height, int heightSize) {
    int sum = 0;
    int right = heightSize - 1,left = 0;
    int maxright = 0, maxleft = 0;
    while(left < right)
    {
        if(height[left] <= height[right])
        {
            if(height[left] >= maxleft)maxleft = height[left];
            else
            {
                sum += maxleft-height[left];
                
            }
            left++;
        }
        else
        {
            if(height[right] >= maxright)maxright = height[right];
            else
            {
                sum += maxright - height[right];
                
            }
            right--;
        }
    }
    return sum;
}