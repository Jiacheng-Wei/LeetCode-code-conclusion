/*
����Ҫ���ľ��ǰ����е�ǰ׺���ŵ�ǰ׺�����棬������ǰ׺�����һ�����ĵط�����ʾisWord��Ϊtrue��
��ʾ�Ӹ��ڵ㵽��ǰ�����һ��ǰ׺��Ȼ�������ڱ��������е�ÿһ����ĸ�����Ƕ���ǰ׺�����ң������ǰ
��ĸ��Ӧ�Ľ��ı�ʾisWord��true�����Ǿͷ������ǰ׺�������ǰ��ĸ��Ӧ�Ľ����ǰ׺���в����ڣ���
�Ǿͷ���ԭ���ʣ��������������Ľ�������ˡ����԰����Ժ��������й�ǰ׺�������Ƶ����⣬һ����Ҫ����
ǰ׺���������Ӵ�� 
*/
struct TrieNode
{
    bool isWord;
    TrieNode* child[26];
    TrieNode():isWord(false){
        for (auto &a : child) a = NULL;
    };
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res = "", t = "";
        istringstream is(sentence);
        TrieNode *root = new TrieNode();
        for (string word : dict) {
            insert(root, word);
        }
        while (is >> t) {
            if (!res.empty()) res += " ";
            res += findpre(root, t);
        }
        return res;
    }
    
    void insert(TrieNode* root,string word)//ע�������rootǰ���ܼ����÷�����Ҳ��֪��Ϊʲô 
    {
        for(auto c:word){
            if(!root->child[c-'a']) root->child[c-'a']= new TrieNode();
            root=root->child[c-'a'];
        }
        root->isWord=true;
    }
    string findpre(TrieNode* root, string word){
        string cur="";
        for(auto a : word){
            if(!root->child[a-'a']) break;
            cur.push_back(a);
            root=root->child[a-'a'];
            if(root->isWord) return cur;
        }
        return word;
    }
};
