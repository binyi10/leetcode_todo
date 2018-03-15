#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;
int colision(vector<int> vec,int col)
    {
        if(vec.size() == 0)return 0;
        for(int i = 1;i <= vec.size();i++)
        {
            int now_col = vec[vec.size() - i];
            if(now_col == col)return 1;
            if(now_col == col - i)return 1;
            if(now_col == col + i)return 1;
        }
        return 0;
    }
    void DFS1(vector<int> vec1, int &count,int N)
    {
        if(vec1.size() == N)
        {
            count++;
            return;
        }
        for(int i = 1;i<=N;i++)
        {
            if(!colision(vec1,i))
            {
                vec1.push_back(i);
                DFS1(vec1,count,N);
				vec1.erase(vec1.end() -1);
            }
            
        }
    }
    int main() {
		int n  =8;
        int total  = 0;
        vector<int> vec;
		vec.clear();
        DFS1(vec,total,n);
        cout<<total;
		return 0;
    }