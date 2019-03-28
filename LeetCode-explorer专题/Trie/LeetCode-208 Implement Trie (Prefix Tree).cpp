/*
�ֵ�����Ҫ�������������ʣ�

1.���ڵ㲻�����ַ��������ڵ�����ÿ���ڵ�ֻ����һ���ַ���
2.�Ӹ��ڵ㵽ĳһ���ڵ㣬·���Ͼ������ַ�����������Ϊ�ýڵ��Ӧ���ַ�����
3.ÿ���ڵ�������ӽڵ�������ַ�������ͬ��

��ĸ���Ĳ��루Insert����ɾ���� Delete���Ͳ��ң�Find�����ǳ��򵥣���һ��һ��ѭ�����ɣ�����i ��ѭ���ҵ�ǰi ����ĸ����Ӧ��������
Ȼ�������Ӧ�Ĳ�����ʵ�������ĸ������������������鱣�棨��̬�����ڴ棩���ɣ���ȻҲ���Կ���̬��ָ�����ͣ���̬�����ڴ棩��
���ڽ��Զ��ӵ�ָ��һ�������ַ�����

1����ÿ����㿪һ����ĸ����С�����飬��Ӧ���±��Ƕ�������ʾ����ĸ����������������Ӷ�Ӧ�ڴ������ϵ�λ�ã�����ţ�
2����ÿ������һ��������һ��˳���¼ÿ��������˭��
3��ʹ����������ֵܱ�ʾ����¼�������
���ַ����������ص㡣��һ����ʵ�֣���ʵ�ʵĿռ�Ҫ��ϴ󣻵ڶ��֣�����ʵ�֣��ռ�Ҫ����Խ�С�����ȽϷ�ʱ�������֣��ռ�Ҫ����С������Է�ʱ�Ҳ���д��

������������һ��ʵ�ַ��������ַ���ʵ��������ֱ�ۣ���ĸ���ֵ���ÿ���ڵ�Ҫ����һ����СΪ26���ӽڵ�ָ�����飬
Ȼ����һ����־��������¼����ǰλ��Ϊֹ�Ƿ�Ϊһ���ʣ���ʼ����ʱ��26���ӽڵ㶼��Ϊ�ա���ôinsert����ֻ��Ҫ
����Ҫ������ַ�����ÿһ���ַ�������λ�ã�Ȼ�����Ƿ��������ӽڵ㣬�����������½�һ����Ȼ���ٲ�����һ����
���Ҵʺ���ǰ׺������insert�����������ƣ���ͬ���������������ӽڵ㣬�򷵻�false�����Ҵ����Ҫ����ʶλ��
����ǰ׺ֱ�ӷ���true���ɡ��������£�
*/ 
class TrieNode{
public:
    // Initialize your data structure here.
    TrieNode *child[26];
    bool isWord;
    TrieNode():isWord(false){
        for(auto &a: child) a=NULL;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root= new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p=root;
        for(auto &a:word){
            int i=a-'a';
            if(!p->child[i]) p->child[i]=new TrieNode();
            p=p->child[i];
        }
        p->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p=root;
        for(auto& a: word)
        {
            int i=a-'a';
            if(!p->child[i]) return false;
            p=p->child[i];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p=root;
        for(auto &a:prefix){
            int i=a-'a';
            if(!p->child[i]) return false;
            p=p->child[i];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
