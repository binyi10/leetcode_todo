# 52. N-Queens II

标签： leetcode c++ stl backstracking DFS

---

## 题目 ##
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.

![此处输入图片的描述][1]


  [1]: /52 N-Queens II/52.png
## 解析 ##
就是传统的N皇后问题，当n >= 4或者n = 1的时候有解。


----------


理解：

 1. 初阶：N皇后问题的最初版本是一个8皇后问题，也就是教科书上讲回溯的经典题目，在一个8x8的棋盘下边，任意两个棋子都不能在同一行，同一列，同一个对角线。
 ![此处输入图片的描述][1]

  [1]: /52 N-Queens II/example.png
 2. 进阶：再细想，得到一个搜索方案，我们一行一行的往下搜索，比如说我们把第一行的棋子位置固定，也就是说第一行的棋子的列数固定，那么接下来再搜第二行，从第二行的第一列开始搜索，然后开始进行判断：
     1. 当前这个棋子的同一列和所在的两个对角线上不存在棋子，自然认为其合法，于是接着往下一行搜索，重复此判断的过程。
     2. 如果存在冲突，那么，就从此行此列的下一列开始搜，只要下一列不超过N，又重复此判断过程。如果超过N了就返回即可。
 3. 再进阶：这样再一想，这就是一个深度优先的搜索（DFS），以第i行的第j列有一个棋子为例，我们首先要查询从第1行起到第i-1行中记录的这i-1个棋子的位置是否和[i,j]这个位置的棋子有冲突，有冲突就分成三种情况：
     1. 这i-1个棋子中有某些棋子所在列col == j。
     2. 这i-1个棋子中有某个棋子与[i,j]在45°对角线，即某个棋子的坐标[x,y] == [i-m,j-m]，其中m为1到max(i-1,j-1)这个范围的某个数。
     3. 这i-1个棋子中某个棋子在[i,j]在135°的对角线，即某个棋子的坐标[x,y] == [i-m,j+m],其中m为1到max(i-1,N-j)这个范围某个数。

 所以我们就能够根据上面的3种情况判定当前的[i,j]是否是合法的存在
     1. 如果合法，且i != N我们就i++,j = 1(即从i+1行的第一列开始搜索)继续往下搜，如果已经i == N了，那我们则找到一个合法状态，这样合法状态++，并且可以回溯到上一层的下一个状态接着往下搜。
     2. 如果不合法，且 j != N的话我们就j++（即从i行的j+1列继续往下搜索）继续往下重复上边的搜索过程，如果已经j == N了，那证明此状态不可行，这样就直接回溯到上一层的下一个状态接着往下搜。

## 代码 ##

    class Solution {
    public:
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
    void DFS(vector<int> vec, int &count,int N)
    {
        if(vec.size() == N)
        {
            count++;
            return;
        }
        for(int i = 1;i<=N;i++)
        {
            if(!colision(vec,i))
            {
                vec.push_back(i);
                DFS(vec,count,N);
                vec.erase(vec.end()-1);
            }
            
        }
    }
    int totalNQueens(int n) {
        int total  = 0;
        vector<int> vec;
        DFS(vec,total,n);
        return total;
    }
};


## 思考 ##
通常的backtracking，都可以想成深搜DFS，这样就要定义好终结的状态也就是何时返回，通常有合法状态返回，对应于N皇后的行数i == N，此时无冲突就可以返回。非法状态返回，对应于N皇后中的列数j > N，此时列数超出，可以返回。其余条件下就对应与当前各个状态的下一个状态继续递归调用即可。
