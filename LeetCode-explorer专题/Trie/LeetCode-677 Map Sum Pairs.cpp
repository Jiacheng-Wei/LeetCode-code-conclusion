/*
�ؼ�����Ҫ��insert�а����ݽṹ���ã������ķ���Ҳ���ѣ���������supposeԭ�����key����ֵ�ģ�
���Ǹ��µ�ʱ��ֻ��Ҫ�������Ĳ�ֵ���ɣ�����key������Ĭ�Ͼ���0�����ֵҲû���⡣Ȼ�����ǽ�firstֵ����Ϊval��
Ȼ����Ǳ��������е�ǰ׺�ˣ���ÿ��ǰ׺��second������diff���ɣ��μ��������£�
*/ 
struct TrieNode{
    bool isWord;
    map<char,TrieNode*> child;
    int freq;
    TrieNode(): isWord(false),freq(0){};
};
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root=new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* cur=root;
        for(auto a:key)
        {
            if(!cur->child.count(a))
            {
                cur->child[a]=new TrieNode();
            }
            cur=cur->child[a];
            cur->freq+=val-visited[key];
        }
        cur->isWord=true;
        visited[key]=val;
    }
    
    int sum(string prefix) {
        TrieNode* cur=root;
        for(auto a:prefix){
            if(!cur->child.count(a)) return false;
            cur=cur->child[a];
        }
        return cur->freq;
    }
private:
    TrieNode* root;
    map<string,int>visited;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
