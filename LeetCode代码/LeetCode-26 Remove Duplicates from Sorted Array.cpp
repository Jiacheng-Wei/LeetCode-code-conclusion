class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int>::iterator it1;
        it1=nums.begin();
        vector<int>::iterator it2;
        while (it1!=nums.end())
        {
            it2=it1+1;
            while(it2!=nums.end())//����ȷ���ˣ�end()�������صĵ�ַ�����һ��Ԫ�غ�һ���ĵ�ַ��һ����ס 
            {
                if (*it1==*it2)
                {
                    nums.erase(it2);
                    //it2++;
                }
                else break;
            }
            it1++;
        }
        return nums.size();
    }
};
//ע�⵱ʹ��vectorģ���е�erase()����ʱ��ע��һ��ɾ������ڵ㣬vector�����ͻ�ı����Բ�Ҫֱ�Ӿ�it++�ˣ����������runtime error������ ��ʵ���ǵ�it�Ѿ���
//����ĩβʱҲ�����Ҳ�պ�ɾ�����һ����㣬��ʱ�Ѿ���nums.end(),Ȼ���ټ�һ���ͻ�������������⣻ͬʱ������������ֵ��Ҫɾ��ʱ��Ҳ�����©ɾ�������
//���Ե�����erase(),������Ͳ�Ҫֱ��+1��
