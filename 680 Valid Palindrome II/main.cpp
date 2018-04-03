class Solution {
public:
    bool val(string s,int low,int high)
    {
        while(low <= high)
        {
            if(s[low] != s[high])return false;
            low ++;
            high--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int size = s.size();
        if(size <= 1)return true;
        int low = 0;
        int high = size-1;
        while(low <= high)
        {
            if(s[low] != s[high])return (val(s,low+1,high) || val(s,low,high-1));
            low ++;
            high --;
        }
        return true;
    }
};