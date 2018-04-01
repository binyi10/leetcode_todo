lass Solution {
public:
    int trans(string str,char sign)
    {
        int MAX = 2147483647;
        int MIN = -2147483648;
        int size = str.length();
        int val = 0;
        if(sign == '+')
        {
            for(int i = 0;i<size;i++)
            {
                if((MAX - (str[i] - '0'))/10 >= val)val = val*10+(str[i] - '0');
                else return MAX;
            }
        }
        
        else
        {
            for(int i = 0;i<size;i++)
            {
                if((MIN+(str[i] - '0'))/10 <= val)val = val*10-(str[i] - '0');
                else return MIN;
            }
        }
        return val;
    }
    int myAtoi(string str) {
        int size = str.length();
        int i = 0;
        int result = 0;
        while((i < size) && ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')))
        {
            i++;
        }
        if(i < size)
        {
            
            if(str[i] == '+' || str[i] == '-' )
            {
                char sign = str[i];
                int start = i+1;
                i++;
                while(i < size && str[i] >= '0' && str[i]<= '9')i++;
                if(start != i)
                {
                    string s(&str[start],&str[i]) ;
                    result = trans(s,sign);
                }
            }
            else if(str[i] >= '0' && str[i]<= '9')
            {
                int start = i;
                while(i < size && str[i] >= '0' && str[i]<= '9')i++;
                if(start != i)
                {
                    string s(&str[start],&str[i]) ;
                    result = trans(s,'+');
                }
            }
            
        }
        return result;
    }
};