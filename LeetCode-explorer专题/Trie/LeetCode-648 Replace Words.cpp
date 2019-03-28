/*
我们要做的就是把所有的前缀都放到前缀树里面，而且在前缀的最后一个结点的地方将标示isWord设为true，
表示从根节点到当前结点是一个前缀，然后我们在遍历单词中的每一个字母，我们都在前缀树查找，如果当前
字母对应的结点的表示isWord是true，我们就返回这个前缀，如果当前字母对应的结点在前缀树中不存在，我
们就返回原单词，这样就能完美的解决问题了。所以啊，以后遇到了有关前缀或者类似的问题，一定不要忘了
前缀树这个神器哟～ 
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
    
    void insert(TrieNode* root,string word)//注意这里的root前不能加引用符，我也不知道为什么 
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
