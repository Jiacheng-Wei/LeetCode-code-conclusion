/*һ�ֵݹ鷽ʽ��Ӧ����dfs�ķ�ʽ����·��Ӧ����ѡ��'('����ѡ��')'��Ȼ��Ϊ�˽���ʱ�临�Ӷȣ���Ҫ��֦������Ҫ��open<n��close<open���жϣ�
��Ϊֻ������������С����������������ʱ��ų���*/ 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0,0,n,res,"");
        return res;
    }
    void dfs(int open,int close,int n,vector<string>& res,string r)
    {
        if(r.length()==2*n)
        {
            res.push_back(r);
            return;
        }
        if(open<n)
        {
            dfs(open+1,close,n,res,r+'(');
        }
        if (close<open)
        {
            dfs(open,close+1,n,res,r+')');
        }
    }
};
//�����һ���ɷ��������ǿ��Ե�ʱ�����һʱ�벻��������������������ķ�������Ҫ
/*
��������һ�ַ��������ַ�����CareerCup���ϸ��ķ������о�Ҳ���������һ�ַ��������ַ�����˼�����������ţ�ÿ�ҵ�һ�������ţ��������
���һ�����������ţ�������ڿ�ͷ��һ��()�����γ������е��������Ҫע����ǣ���ʱ�������ظ������������������set���ݽṹ���ô���
��������ظ��������뵽����У���������ٰ�setתΪvector���ɣ��μ���������:
n��1:    ()

n=2:    (())    ()()

n=3:    (()())    ((()))    ()(())    (())()    ()()() 
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> t;
        if (n == 0) t.insert("");
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (auto a : pre) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        a.insert(a.begin() + i + 1, '(');
                        a.insert(a.begin() + i + 2, ')');
                        t.insert(a);
                        a.erase(a.begin() + i + 1, a.begin() + i + 3);
                    }
                }
                t.insert("()" + a);
            }
        }
        return vector<string>(t.begin(), t.end());
    }
}; 
