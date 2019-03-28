class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minu=triangle[triangle.size()-1];
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                minu[j]=(minu[j]<minu[j+1]?minu[j]:minu[j+1])+triangle[i][j];
            }
        }
        return minu[0];
    }
};
/*
��̬�滮���⣬�ܾ��䣬���������ˣ����ǻ���Ҫ�����ϰ��̽�����ɵķ����� 
�����ķ������������ڴ������µı�����ʽ���������ϵı�����ʽ���򵥣�Ҳ���ܹ�������Ŀ�Կռ临�Ӷ�O(n)�����ƣ�������һ�������
����Ϊ���һ������ĳ��ȣ�Ȼ������������ڵ���ת���ɶ�ά����һһ��Ӧ�������ʵ���Ͼ��������������Ǻ�minu[j]��minu[j+1]���ڣ�Ȼ��
����ֻ��Ҫ����minu���鼴�ɣ�ֻ������������ռ临�Ӷ�ΪO(n)����������������ϣ� 
*/
