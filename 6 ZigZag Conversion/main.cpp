class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <=1)return s;
        int gap = 2 * numRows -2;
        string result;
        int size = s.length();
        for(int i = 0;i<size;i+=gap)
        {
           result = result + s[i]; 
        }
        for(int i = 1;i<numRows - 1;i++)
        {
            int new_gap = 2*i;
            for(int j = i; j <size;j+=new_gap)
            {
                result = result + s[j];
                new_gap = gap - new_gap;
            }
        }
        for(int i = numRows-1;i<size;i+=gap)
        {
            result = result + s[i];
        }
        return result;
    }
};