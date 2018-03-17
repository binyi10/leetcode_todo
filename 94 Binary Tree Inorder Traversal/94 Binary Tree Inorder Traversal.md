# 94. Binary Tree Inorder Traversal

标签： leetcode c++ stl backstracking DFS

---

## 题目 ##
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree [1,null,2,3],
![此处输入图片的描述][1]
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?



## 解析 ##
嘻嘻，最近因为马上要面试，就回忆一下树的遍历，快排，最长公共子序列，八皇后之类的基础题。言归正传，这道题就是写树的中序遍历，当然最好能写出递归和非递归两个版本。


----------


理解：

 1. 初阶：最简单的方法就是递归，所谓的中序遍历就是先遍历左孩子，再输出根节点，再遍历右孩子。所以递归的写法按照这个舒徐一目了然。
 2. 进阶：就像题目描述，递归是很trivial，想增加挑战就是非递归，与先序遍历的简单不同，中序遍历的非递归比较具有技巧性和启发性，能想到的是挺天才的。基本想法就是，既然要先输出左孩子，那就先不断的从根开始往下，只要有左孩子的就进栈，并且让当前的根指向其左孩子，直到出现没有左孩子的情况。然后自然这个时候要处理的问题是，如果之前存的某个节点被pop之后，怎么确保不会再一次把它的左孩子又进栈造成死循环。当然有很好的方法就是pop之后，让其指向其右孩子，这样会出现的情况就是，
        1. 如果没有右孩子，当前结点就指向空，自然不会再再寻找其左孩子，那么就会进入下一个pop，因此确保了不会进入左孩子又进栈的死循环：
        2. 如有有右孩子，也就是依照之前的情况，对右孩子进行中序遍历，直到出现情况1即右孩子遍历结束，又继续pop，因此也确保不会进入死循环。
     

## 代码 ##
非递归

    class Solution {
            public:
            void inorder(TreeNode* root, vector<int> & vec){
            if(root -> left != NULL)
            {
                inorder(root -> left,vec);
            }
            vec.push_back(root -> val);
            if(root -> right != NULL)
            {
                inorder(root -> right,vec);
            }
        
        }
            vector<int> inorderTraversal(TreeNode* root) {
                vector<int> vec;
                if(root == NULL)return vec;
                inorder(root,vec);
                return vec;
    }
};
递归

    class Solution {
    public:
    void inorder(TreeNode* root, vector<int> & vec)
    {
        if(root -> left != NULL)
        {
            inorder(root -> left,vec);
        }
        vec.push_back(root -> val);
        if(root -> right != NULL)
        {
            inorder(root -> right,vec);
        }
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root == NULL)return vec;
        inorder(root,vec);
        return vec;
    }
};


  [1]: /94%20Binary%20Tree%20Inorder%20Traversal/94.png