/*
该题的思路就是先建树，然后对board进行dfs的搜索查找单词 
*/ 
class TrieNode{
public:
    string str;//注意这里赋予str类型的巧妙之处可以直接push进res数组 
    TrieNode* child[26];
    TrieNode():str(""){
        for(auto& a:child){
            a=NULL;
        }
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.empty()||board.empty()||board[0].empty()) return res;
        vector<vector<bool> > visit(board.size(),vector<bool>(board[0].size(),false));//注意这里对二维数组赋初值的写法 
        TrieNode* root=new TrieNode();
        for(auto word:words){
            TrieNode* cur=root;
            for(int i=0;i<word.length();i++)
            {
                if(!cur->child[word[i]-'a']) cur->child[word[i]-'a']=new TrieNode();
                cur=cur->child[word[i]-'a'];
            }
            cur->str=word;
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                search(board,root->child[board[i][j]-'a'],i,j,visit,res);
            }
        }
        return res;
    }
    void search(vector<vector<char> >& board,TrieNode* p,int i,int j,vector<vector<bool> >& visit,vector<string>& res)
    {
        if(!p) return;//这里一定要有个判断，这里是dfs的边界 
        if(!p->str.empty())
        {
            res.push_back(p->str);
            p->str.clear();//不在这里return的原因是这里可能会存在子单词，如果在这里就return了，就会出现漏掉单词的情况 
        }
        int d[][2]={{0,1},{0,-1},{-1,0},{1,0}};
        visit[i][j]=true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;//注意这里的一定要回置false 
    }
};
