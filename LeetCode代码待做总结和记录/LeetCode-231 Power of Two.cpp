class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        int rest;
        while(n>2)
        {
            rest=n%2;
            if(rest!=0) return false;
            n=n/2;
        }
        return true;
    }
};
//����Ҫע������������nС�ڵ���0������� 
