//n皇后问题 
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> pos(n,-1);
        generate(pos,0,res);
        return res;
    }
    void generate(vector<int>& pos ,int row,vector<vector<string> >& res)//递归完成 
    {
        int n=pos.size();
        if (row==n)//递归终点 
        {
            vector<string> out(n,string(n,'.'));
            for(int i=0;i<n;i++)
            {
                out[i][pos[i]]='Q';
            }
            res.push_back(out);
        }
        else
        {
            for(int col=0;col<n;col++)
            {
                if (isvalue(pos,row,col))//在递归的中间就判断可以节省很多的时间，该方法被称为剪枝 
                {
                    pos[row]=col;
                    generate(pos,row+1,res);
                    pos[row]=-1;
                }
            }
        }
    }
    bool isvalue(vector<int>& pos, int row,int col )//判断是否在列上和对角线上练成了一条线 
    {
        for (int i=0;i<row;i++)
        {
            if (col==pos[i]||abs(row-i)==abs(pos[i]-col))
            {
                return false;
            }
        }
        return true;
    }
};
