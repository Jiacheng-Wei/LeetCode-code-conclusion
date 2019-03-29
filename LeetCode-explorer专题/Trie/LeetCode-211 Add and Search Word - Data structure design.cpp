/*
这道题里面'.'可以代替任意字符，所以一旦有了'.'，就需要查找所有的子树，只要有一个返回true，
整个search函数就返回true，典型的DFS的问题，其他部分跟上一道实现字典树没有太大区别，代码如下：
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
        TrieNode* p=root;//这里一定要定义P，才能实现向下的遍历 
        for(auto& a: word)
        {
            if(!p->child[a-'a']) p->child[a-'a']=new TrieNode();
            p=p->child[a-'a'];
        }
        p->isWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchword(string& word,TrieNode* p,int i)//通过dfs的方法实现对出现'.'的情况的解决 
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
