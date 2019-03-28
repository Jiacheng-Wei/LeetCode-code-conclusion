/*递归的方法，因为BST树独特的性质，其中序排列就是递增的有序数列，所以当给你一个递增的有序数列时，任意节点都可以做根节点，然后将根节点
左右两边分别划分为左右子树，然后对左右子树进行相同的步骤，就形成了BST树，而所有BST树的数量就是左右子树数量的积*/
//递归求解
class Solution {
public:
    int numTrees(int n) 
    {
        if(n<=1)    return 1;
        int sum=0;
        for(int i=1;i<=n;++i)
            sum+=numTrees(i-1)*numTrees(n-i);
        return sum;    
    }
};
/*
另一种方法是大神所提到的卡特兰数，虽然我不是很懂卡特兰树具体的含义，也只能懂他的字面意思，但是对于其用动态规划求解问题的巧妙性还是很钦佩的， 
感觉这篇博客讲的比较详细，不懂原理的话可以直接参考https://www.cnblogs.com/springfor/p/3884009.html
若F(n)表示[1...n]能够构成的不同BST的数量，那么：
        1、特殊情况，如果结点数为0，即n=0,为空树，F(0)=1；
        2、如果结点数为1，即n=1,F(1)=1;
        3、如果结点数为2，即n=2,F(2)=2;
        4、对于n>=2的情况，事实上，1,2,..n都可以作为根节点，若i作为根节点，根据BST的性质，左子树不为空时（左子树为空，只能是i=1），
		左子树的所有节点必须小于根节点，即[1,i-1]必须位于左子树，同时，右子数节点必须值必须大于根节点值，则[i+1,n]必须位于右子树；
        5、如上分析，对于[1,n]，n>=2的情况，既然[1,n]每一个值都可以作为根节点，那我们需要遍历所有情况，时间复杂度为O(n)，对于任
		何一种情况：根节点为i，则[1,i-1]为左子树，[i+1,n]为右子树，左子树有能够构成不同的BST的数量为：F(i-1)，右子树能够构成的不
		同BST的数量为F(n-i)；
			左右植树相互独立，那么：F(n)=F(i-1)*F(n-i),i属于[1,n]，i有n种情况，须完全遍历
        6、进一步地，我们将这个问题数学化：
			F(0)=1         n=0; 
            F(1)=1         n=1;          
		     n
		G(n)=∑F(i-1)*F(n-i) n>=2;
             i=1
         7、根据上面的公式，写出代码很容易，两重循环，时间复杂度O(n^2)
*/ 
class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> nums(n+1,0);//注意细节n+1
        nums[0]=1;
        nums[1]=1;
        if(n==1||n==0) return 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                nums[i]+=nums[j-1]*nums[i-j];
            }
        }
        return nums[n];
    }
};
/*
solution里面还提到了数学的解决方法： 
时间复杂度为O(n) 
*/
class Solution {
public: 
    int numTrees(int n) {
    // Note: we should use long here instead of int, otherwise overflow
    long C = 1;
    for (int i = 0; i < n; ++i) {
      C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int) C;
  }
};
