class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        if(s.length()<=1)return s.length();
        map<char,int> strmap;
        int start  = 0;
        int i = 0;
        for(;i<s.length();i++)
        {
           if(strmap.find(s[i]) == strmap.end())
           {
               strmap[s[i]] = i;
           }
           else if(strmap[s[i]] >= start)
           {
               max = max > (i - start) ? max : (i - start) ;
               start = strmap[s[i]] + 1;
               strmap[s[i]] = i;
           }
           else
           {
               strmap[s[i]] = i;
           }
          
        }
        return max > (i - start) ? max : (i - start) ;
    }
};