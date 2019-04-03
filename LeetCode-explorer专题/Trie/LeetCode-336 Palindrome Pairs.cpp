/*
考虑单词"lls"和"sssll"连接起来"llssssll"是回文串，是因为反向看sssll是由lls开头的

因此把输入的单词反向建立Trie树，并存储其真实值(用index)

建立好Trie树后，对于每一个word，查找由其部分或全部为开头的反向单词

例如words=["abcd","cba","dcba","ecba","edcba"]
见博客：https://blog.csdn.net/zmq570235977/article/details/51926304 
*/
class TrieNode{
public:
    TrieNode* child[26];
    int index;
    vector<int> vec;
    TrieNode():index(-1){
        for(auto &a:child){
            a=NULL;
        }
    }
};
class Solution {
public:
    TrieNode* root;
    void insert(string word,int index){
        TrieNode* node=root;
        int n=word.length();
        for(int i=n-1;i>=0;i--){
            if(!node->child[word[i]-'a']) node->child[word[i]-'a']=new TrieNode();
            node->vec.push_back(index);
            node=node->child[word[i]-'a'];
        }
        node->index=index;
        if(n==0){
            node->vec.push_back(index);
        }
    }
    
    vector<int> search(string word){
        vector<int> res;
        TrieNode* node=root;
        if(node->index!=-1){
            res.push_back(node->index);
        }
        for(char c:word){
            node=node->child[c-'a'];
            if(!node) return res;
            if(node->index!=-1) res.push_back(node->index);
        }
        for(int i:node->vec){
            res.push_back(i);//这里一定是push的i 
        }
        return res;
    }
    bool ispd(string word,int i,int j){
        while(i<j)
        {
            if(word[i++]!=word[j--]) return false;
        }
        return true;
    }
    bool ispd(string s1,string s2){
        int n1=s1.length(),n2=s2.length();
        if(n1<n2) return ispd(s2,0,n2-n1-1);
        return ispd(s1,n2,n1-1);//这里的回文数判断很重要，两个字符串的回文数，因为已经对应了一部分的回文数，所以只用判断超出部分自身是否为回文数即可 
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > res;
        root=new TrieNode();
        int n=words.size();
        for(int i=0;i<n;i++){
            insert(words[i],i);
        }
        for(int i=0;i<n;i++){
            vector<int> index=search(words[i]);
            for(int j:index){
                if(j==i) continue;
                if (ispd(words[i],words[j]))
    			{
    				vector<int> vec(2);
    				vec[0] = i; vec[1] = j;
    				res.push_back(vec);
    			}

            }
        }
        return res;
    }
};
