# 300. Longest Increasing Subsequence

标签： leetcode c++ stl DP

---

## 题目 ##
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?



## 解析 ##
本来还想更一个并查集的题目的，没时间更新写了，因为和老师讨论了文章和代码很久。
这个题目就是DP的入门题目，所谓动态规划就是两部，定义状态和状态转移方程，这里推荐一些知乎这个问题大家可以弄清楚。[动态规划摸我][2]。
当然对于LIS来说，trivial的是O(n^2)的解法，还有一个更优秀的O(nlogn)的解法


----------


理解：

 1. 初阶：对于输入数组nums,既然是动态规划,那么就
          1. 先定义状态，状态S[i]可以定义成，当遍历到某个数的时候，以它为结尾的LIS的长度。显然这个状态满足DP的要求，也就是说此状态值S[i]只与此状态之前的状态的值s[1]~s[i-1]相关，与之后的无关，初始的所有状态值都是1。
          2. 再定义状态转移方程，状态转移方程为，比较第i个数之前的所有数k，即k = [1,i-1]中所有的数，如果nums[i] > num[k]，那么更新一个s[i] = max(s[k]+1,s[i])就行。
 2. 进阶：如果要是O(nlogn)的算法，logn复杂度第一个想到就应该是二分查找，于是我们只要有一个有序的数组order[]，方便我们去查找，那么这个有序数组order[]是啥，我们回顾一下，既然我们是要找的是到底状态S[i]是1，2，3...m(其中m<=i),那么就简单了，我们把对应于每种长度的最小nums[i]值表示出来就行，那我们只需要检查在这个数组里边nums[i]到底处于什么位置，我们就能知道他的状态S[i]应该是多少了，具体
         （（ 状态1. 是如果找到相同的数，那么S[i] = m,其中m为返回的位置。
         （（ 状态2. 如果没找到相同的数，情况肯定就是夹在一个比它小的数和一个比它大的数中间，那自然应该返回这个大的数的位置m，把S[i] = m,同时更新order[m] = nums[i]，也就是把当前长度为i的LIS的结尾最小值进行更新，
现在我们来看一个例子：
     假设nums = [3,1,4,1]
     round1: 对于初始点，肯定S[1] = 1，毕竟到1只有一个数，同时也更新有序数组order[1] = nums[1] = 3
     round2: 对于nums[2] = 1,首先在order中做二分查找，没找到，符合情况2，于是返回m = 1，并且做两个更新，S[2] = 1, order[1] = nums[2] = 1.
     round3: 对于nums[3] = 4,首先在order中做二分查找，没找到，符合情况2，于是返回m = 2，因为4是夹在order[1] = 1, order[2] = 无穷大（因为目前还没有长度为2的LIS，所以自然对用的值是无穷大），之间的，所以返回较大的数的下标，也就是m = 2, 于是更新S[3] = 2, order[2] = nums[3] = 4;
     round4: 对于nums[4] = 1, 首先在order中做二分查找，找到了，发现nums[4] = 1 = order[1]，满足状态1，于是返回m = 1,所以S[4] = 1.
     结束，返回order.size()。
     

## 代码 ##
O(n2)

    class Solution {
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


O(nlogn)

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
## 思考 ##
遇到动态规划的难题，一定要定义好状态和状态转移方程

  [1]: /94%20Binary%20Tree%20Inorder%20Traversal/94.png
  [2]: https://www.zhihu.com/question/23995189/answer/35429905