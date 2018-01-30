# 42. Trapping Rain Water

标签： leetcode c 双指针

---

## 题目 ##
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.



![此处输入图片的描述][1]


  [1]: /42_Trapping_Rain_Water/rainwatertrap.png
## 解析 ##
题目大意是，给出了一幅海拔图，然后通过凹下去的部分计算到底能存住多少水。


----------


理解：

 1. 初阶：直观上感受能装多少水，就是寻找有多少个突出的地方，也就是说寻找凸出的柱子，或者说，寻找在那些柱子中间能形成凹函数（将各高度连线）。
 2. 进阶：再细想，可以从左往右直接寻找，先找到第一个凹槽，然后将前一个凹槽的右边墙壁变成新凹槽的左端墙壁，接着再往下找。具体定义凹槽的细节如下：
     1. 从第一个柱子开始，后边如果有比这个柱子高的，更新这个更高的柱子成为左端杯壁，否则此柱子肯定是凹槽内的内容，那么直接和左端杯壁做差就是次柱子处能装多少水，这里有个trick，如果不断向右边寻找都没有左边杯壁高的，那么到结尾后，我们可以从结尾反过来从右往左找，这样最左边的杯壁肯定是会比右边高的，也就是说反过来找肯定能找到。所以最大就是找2n次，最小n次，因此时间开销是O(n),空间开销为O(1)。
 3. 再进阶：这样从左找完，在从右往左找，是不是能两个指针同时像中间迈进，答案是可以的（这是我从题目的评论区看来的），如果用两个指针分别从两端往中间找的话，双指针的话需要讨论的地方就是，何时从动左边的指针，何时动右边的指针。仔细一想的话，当右边指针指向的柱子比左边指针指向的高的话，说明直到碰到右边的柱子为止，左边都是凹槽下去的部分，因此此时需要动左边的指针，右边的高的柱子可以用来当作杯壁。同理可以推出左边高时动右边的指针。
## 代码 ##

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
## 思考 ##
是不是来回查找的都可以考虑是否能用双指针？
之前刷到左右双指针的题目，11题
