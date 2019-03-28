//���õݹ�ķ���ʵ�֣�����ĵݹ�����������ʱ�͵��õݹ飬ͬʱmap���Զ�����Ĺ��ܣ��������ʱ������ĸ������� 
class Solution {
public:
    string countOfAtoms(string formula) {
        string res="";
        int pos=0;
        map<string,int> mp=parse(formula,pos);
        for (auto a: mp)
        {
            res+=a.first+(a.second==1? "":to_string(a.second));
        }
        return res;
    }
    map<string,int> parse(string& str,int& pos){
        map<string,int> res;
        while (pos<str.size())
        {
            if (str[pos]=='(')
            {
                pos++;
                for(auto a: parse(str,pos)) res[a.first]+=a.second;
            }
            else if (str[pos]==')')
            {
                int i = ++pos;
                while (pos<str.size()&&isdigit(str[pos])) pos++;
                int multi=stoi(str.substr(i,pos-i));
                for (auto a : res) res[a.first]*=multi;
                return res;
            }
            else 
            {
                int i=pos++;
                while (pos<str.size()&&islower(str[pos])) pos++;
                string elem=str.substr(i,pos-i);
                i=pos;
                while (pos<str.size()&&isdigit(str[pos])) pos++;
                string cnt=str.substr(i,pos-i);
                res[elem]+=cnt.empty()? 1:stoi(cnt);
            }
        }
        return res;
    }
};
//�ݹ�ķ�����ʵ����ת���ɵ����ķ��������ǵ���������Ҫ�õ�ջ�����Խ���������ջ��ʵ�֡�
class Solution {
public:
    string countOfAtoms(string formula) {
        string res="";
        int pos=0;
        map<string,int> cur;
        stack<map<string,int> > st;
        while (pos<formula.size())
        {
            if (formula[pos]=='(')
            {
                pos++;
                st.push(move(cur));
            }
            else if (formula[pos]==')')
            {
                int i = ++pos;
                while (pos<formula.size()&&isdigit(formula[pos])) pos++;
                int multi=stoi(formula.substr(i,pos-i));
                for (auto a : cur) st.top()[a.first]+=a.second*multi;
                cur=move(st.top());
                st.pop();
            }
            else 
            {
                int i=pos++;
                while (pos<formula.size()&&islower(formula[pos])) pos++;
                string elem=formula.substr(i,pos-i);
                i=pos;
                while (pos<formula.size()&&isdigit(formula[pos])) pos++;
                string cnt=formula.substr(i,pos-i);
                cur[elem]+=cnt.empty()? 1:stoi(cnt);
            }
        }
        for (auto a: cur)
        {
            res+=a.first+(a.second==1? "":to_string(a.second));
        }
        return res;
    }
};
 //���ﲻ������move()�������÷����Ҿ�������÷��е��ԡ�
 //����move�����Ľ�����վ 
 //https://www.jb51.net/article/125150.htm
 //https://www.cnblogs.com/swarmbees/p/5621408.html 
 //���Ǵ�����ܵ���վ��https://www.cnblogs.com/grandyang/p/8667239.html 
