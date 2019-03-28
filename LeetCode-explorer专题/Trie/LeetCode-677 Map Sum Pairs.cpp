/*
关键就是要在insert中把数据结构建好，构建的方法也不难，首先我们suppose原本这个key是有值的，
我们更新的时候只需要加上它的差值即可，就算key不存在默认就是0，算差值也没问题。然后我们将first值更新为val，
然后就是遍历其所有的前缀了，给每个前缀的second都加上diff即可，参见代码如下：
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
