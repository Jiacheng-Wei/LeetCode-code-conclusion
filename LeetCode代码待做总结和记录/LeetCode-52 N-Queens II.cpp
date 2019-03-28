class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<int> pos(n,-1);
        generate(pos,0,res);
        return res;
    }
    void generate(vector<int>& pos,int row,int& res)
    {
        int n=pos.size();
        if (row==n)
        {
            res++;
            return;
        }
        else
        {
            for (int col=0;col<n;col++)
            {
                if (isvalue(pos,row,col))
                {
                    pos[row]=col;
                    generate(pos,row+1,res);
                    pos[row]=0;
                }
            }
        }
    }
    bool isvalue(vector<int> pos,int row,int col)
    {
        for (int i=0;i<row;i++)
        {
            if(col==pos[i]||abs(row-i)==abs(col-pos[i]))
            {
                return false;
            }
        }
        return true;
    }
};
