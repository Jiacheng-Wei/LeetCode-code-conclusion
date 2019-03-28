class Solution {
public:
    bool _isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        int length1=s.length();
        int length2=t.length();
        if (length1!=length2) return false;
        if (length1==0&&length2==0) return true;
        else if (length1==0||length2==0) return false;
        for (int i=0;i<length1;i++)
        {
            if (mp.find(s[i])!=mp.end()&&mp.find(s[i])->second!=t[i]) return false;
            else 
            {
                mp[s[i]]=t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t){
        return _isIsomorphic(s, t)&&_isIsomorphic(t, s);
    }
};
/*���������ַ���s��t���ж������Ƿ���ͬ���ġ�����ַ���s����ͨ���ַ��滻�ķ�ʽ�õ��ַ�
��t�����s��t��ͬ���ġ��ַ���ÿһ�γ��ֶ����뱻���Ӧ�ַ����滻��ͬʱ����Ҫ��֤ԭʼ˳
�򲻷����ı䡣�����ַ�����ӳ�䵽ͬһ���ַ��������ַ�����ӳ�䵽�䱾��*/
/*����ķ�����ֱ���õ�map�������ж϶�Ӧ��ӳ�䣬����������Ϊ("ab","aa")ʱ��Ӧ���Ǵ���ģ��������ֻͨ��ӳ���жϵĻ�������ȷ��;
�������뽻��һ�£�����Ϊ("aa","ab")��������������Ǵ�����ˣ��������ж�ʱҪ��������˳���жϣ���ȥ���Ľ��*/
//���������һ��˼·����һ��set���жϳ�t�е�ֵ�Ƿ񷴸����֡� 
/*ʹ��һ����ϣ��mapά�������ַ������ַ���ӳ���ϵ��ͬʱ��һ��set����ӳ���ֵ��(s[i], t[i])������s[i]��û����map�г��ֹ���
��t[i]û����set�г��ֹ����ͼ��뵽ӳ���ϵ�У�t[i]ֵ�Ѿ����ֹ���˵���Ƕ��һӳ�䣬�����Ϸ���false��s[i]������Ѿ����ֹ���
��Ϊs[k]����Ӧ��ӳ��ֵΪt[k]),��s[i]==s[k],���ҳ�s[k]�ĶԶ�Ӧֵt[k]�����t[i]!=t[k],˵��һ��ͬһ���ַ�����������ͬ��ӳ�䣬
�����ַ�������ͬ���ģ�����false������������һ���ַ���ֱ��������*/


