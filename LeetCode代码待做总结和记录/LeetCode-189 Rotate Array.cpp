class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		k%=nums.size();
		for (int i=0;i<k;i++)
        {
            vector<int>::iterator it=nums.end()-1;
            nums.insert(nums.begin(),*it);
            nums.pop_back();
        }
    }
};
/*
class Solution {
public:
    // Use reverse
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
private:
    void reverse(vector<int>& nums, int start, int end)
    {
        int left = start;
        int right = end;
        while (left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
};
*/ 
// ��k�����Ŀ���ǽ���ִ�д�������Ϊ���������ԣ���������ʵ��һ�μ��ɵó��𰸡�����̫�ɣ��Ҳ�֪����ô�ܽ��ˣ��϶���ʲô��ѧԭ���̺����С� 
// �ڶ����㷨���ܿ�����������⣬���������ϸ����һ�µĻ������Ǿ��ú��ɵ�һ�ַ���������������¡� 
// ��һ��������ʹ�����������У��ڶ���ִ�к� ��ʹ�õ�ת�������ڵ����������У�������ʹ�ĵ�ת�����Ժ�����ָ�����˳�� 
