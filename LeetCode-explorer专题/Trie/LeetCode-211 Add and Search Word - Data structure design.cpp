/*
���������'.'���Դ��������ַ�������һ������'.'������Ҫ�������е�������ֻҪ��һ������true��
����search�����ͷ���true�����͵�DFS�����⣬�������ָ���һ��ʵ���ֵ���û��̫�����𣬴������£�
*/ 
class WordDictionary {
public:
   struct TrieNode{
    bool isWord;
    TrieNode* child[26];
    TrieNode(): isWord(false){
        for(auto &a:child){
            a=NULL;
            }
        }
    };
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p=root;//����һ��Ҫ����P������ʵ�����µı��� 
        for(auto& a: word)
        {
            if(!p->child[a-'a']) p->child[a-'a']=new TrieNode();
            p=p->child[a-'a'];
        }
        p->isWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchword(string& word,TrieNode* p,int i)//ͨ��dfs�ķ���ʵ�ֶԳ���'.'������Ľ�� 
    {
        if(i==word.size()) return p->isWord;
        if(word[i]=='.')
        {
            for(auto& a:p->child){
                if(a&&searchword(word,a,i+1)) return true;
            }
            return false;
        }
        else {
            return p->child[word[i]-'a']&&searchword(word,p->child[word[i]-'a'],i+1);
        }
    }
    bool search(string word) {
        return searchword(word,root,0);
    }
    

private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
