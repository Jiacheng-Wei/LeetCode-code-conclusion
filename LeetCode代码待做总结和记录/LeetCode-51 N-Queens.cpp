//n�ʺ����� 
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> pos(n,-1);
        generate(pos,0,res);
        return res;
    }
    void generate(vector<int>& pos ,int row,vector<vector<string> >& res)//�ݹ���� 
    {
        int n=pos.size();
        if (row==n)//�ݹ��յ� 
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
                if (isvalue(pos,row,col))//�ڵݹ���м���жϿ��Խ�ʡ�ܶ��ʱ�䣬�÷�������Ϊ��֦ 
                {
                    pos[row]=col;
                    generate(pos,row+1,res);
                    pos[row]=-1;
                }
            }
        }
    }
    bool isvalue(vector<int>& pos, int row,int col )//�ж��Ƿ������ϺͶԽ�����������һ���� 
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
