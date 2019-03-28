class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        bool *p=new bool[n];
        memset(p,true,sizeof(bool)*n);
        for (int i=2;i*i<n;i++)
        {
                if(p[i])//ΪʲôҪ�ж�p[i]��Ŀ���Ǽ���ѭ����������Ϊ���i����Ͳ���������ôi*jҲ�Ͳ������� 
                {
                    for(int j=2;j*i<n;j++)
                    {
                        p[i*j]=false;
                    }//��������һ��hash��ÿһ�������ж������¼���� 
                }
        }
        int count=0;
        for (int i=2;i<n;i++)
        {
            if (p[i])
            {
                count++;
            }
        }
        
        return count;
    }
};
