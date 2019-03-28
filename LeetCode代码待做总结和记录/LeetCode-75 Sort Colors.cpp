//������Ҫ��Ĵ��룬���Ի���Ҫ�Լ���һ������ 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};
//two pointer ���
/*
��Ŀ�л�Ҫ��ֻ����һ����������⣬��ô����Ҫ��˫ָ���������ֱ��ԭ�������β�������ƶ���
- ����redָ��ָ��ͷλ�ã�blueָ��ָ��ĩβλ��
- ��ͷ��ʼ����ԭ���飬�������0���򽻻���ֵ��redָ��ָ���ֵ������redָ�����һλ��������2���򽻻���ֵ��blueָ��ָ���ֵ����
��blueָ��ǰ��һλ��������1�������������
*/
class Solution {
public:
    void sortColors(int A[], int n) {int red = 0, blue = n - 1;
        for (int i = 0; i <= blue; ++i) {
            if (A[i] == 0) {
                swap(A[i], A[red++]);
            } else if (A[i] == 2) {
                swap(A[i--], A[blue--]);
            } 
        }
    }
}; 
/*
����������Ҫ�����������飬��ô���������ַ�������Ϊ������ֻ��������ͬ��Ԫ�أ�����ʵ�����������ס�
- ���ȱ���һ��ԭ���飬�ֱ��¼0,1,2�ĸ���
- Ȼ�����ԭ���飬�������ֱ���0��1��2
*/ 
class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0}, idx = 0;
        for (int i = 0; i < n; ++i) ++count[A[i]];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                A[idx++] = i;
            }
        }
    }
};

