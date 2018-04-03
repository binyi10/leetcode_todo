class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1;
        stack<int > st2;
        if(s[0] == ')')return false;
        else if(s[0]=='(')st1.push(0);
        else st2.push(0);
        for(int i = 1;i<s.length();i++)
        {
            char c = s[i];
            if(c == ')')
            {
               if(!st1.empty())
               {
                   st1.pop();
               }
                else
                {
                    if(!st2.empty()) st2.pop();
                    else return false;
                }
                
            }
            else if(c== '*')
            {
                st2.push(i);
            }
            else
            {
                st1.push(i);
            }
        }
        while(!st1.empty() && !st2.empty())
        {
            int a = st1.top();
            int b = st2.top();
            if(a > b)return false;
            st1.pop();
            st2.pop();
        }
        if(!st1.empty())return false;
        return true;
    }
};