class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        it=nums.begin();
        while(it!=nums.end())
        {
            if(val==*it)
            {
                nums.erase(it);
                continue;
            }
            it++;
        }
        return nums.size();
    }
};
//ע�⵱ʹ��vectorģ���е�erase()����ʱ��ע��һ��ɾ������ڵ㣬vector�����ͻ�ı����Բ�Ҫֱ�Ӿ�it++�ˣ����������runtime error������ ��ʵ���ǵ�it�Ѿ���
//����ĩβʱҲ�����Ҳ�պ�ɾ�����һ����㣬��ʱ�Ѿ���nums.end(),Ȼ���ټ�һ���ͻ�������������⣻ͬʱ������������ֵ��Ҫɾ��ʱ��Ҳ�����©ɾ�������
//���Ե�����erase(),������Ͳ�Ҫֱ��+1��
