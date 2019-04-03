/*
���ǵ���"lls"��"sssll"��������"llssssll"�ǻ��Ĵ�������Ϊ����sssll����lls��ͷ��

��˰�����ĵ��ʷ�����Trie�������洢����ʵֵ(��index)

������Trie���󣬶���ÿһ��word���������䲿�ֻ�ȫ��Ϊ��ͷ�ķ��򵥴�

����words=["abcd","cba","dcba","ecba","edcba"]
�����ͣ�https://blog.csdn.net/zmq570235977/article/details/51926304 
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
            res.push_back(i);//����һ����push��i 
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
        return ispd(s1,n2,n1-1);//����Ļ������жϺ���Ҫ�������ַ����Ļ���������Ϊ�Ѿ���Ӧ��һ���ֵĻ�����������ֻ���жϳ������������Ƿ�Ϊ���������� 
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
