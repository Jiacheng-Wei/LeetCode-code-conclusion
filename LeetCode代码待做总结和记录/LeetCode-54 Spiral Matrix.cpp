//�ķ����������ڶ�άƽ�����ƶ���ԭ��һ�£����ж��Ƿ񳬽磬���Ƿ��Ѿ������� 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size()==0) return res;
        int row=matrix.size(),col=matrix[0].size();
        bool seen[row][col]={false};
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        int r=0,c=0,di=0;
        for(int i=0;i<row*col;i++)
        {
            res.push_back(matrix[r][c]);
            seen[r][c]=true;
            int nr=r+dr[di];
            int nc=c+dc[di];
            if(0<=nr&&nr<row&&0<=nc&&nc<col&&!seen[nr][nc])
            {
                r=nr;
                c=nc;
            }
            else
            {
                di=(di+1)%4;
                r+=dr[di];
                c+=dc[di];
            }
        }
        return res;
    }
};
/*
����������ǽ�һ������������˳���ӡ����������ֻ��һ����һ���ߵĴ�ӡ����������Ҫ�Ӹ�����mxn�ľ��������������˳���м�������ע��
���ռ�Ļ�������һ�����֣�Ҳ������һ�л���һ�С������ļ��㹫ʽ�� min(m, n) / 2��֪���˻��������ǿ��Զ�ÿ�����ı߰�˳���ӡ�������
����Ŀ�и����Ǹ����ӣ��������ɵ�˳����(����ɫ���������) Red -> Green -> Blue -> Yellow -> Black 

1��2��3

4��5��6

7��8��9

 

���Ƕ���p��qΪ��ǰ���ĸ߶ȺͿ�ȣ���p����qΪ1ʱ����ʾ���һ����ֻ��һ�л���һ�У���������ѭ����������ѵ������±��ת���������ȷ��
ת���±��ǽ����Ĺؼ������ǿ��Զ����������3x3������������±����д���������£�
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
        int p = m, q = n;
        for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
            for (int col = i; col < i + q; ++col) 
                res.push_back(matrix[i][col]);
            for (int row = i + 1; row < i + p; ++row)
                res.push_back(matrix[row][i + q - 1]);
            if (p == 1 || q == 1) break;
            for (int col = i + q - 2; col >= i; --col)
                res.push_back(matrix[i + p - 1][col]);
            for (int row = i + p - 2; row > i; --row) 
                res.push_back(matrix[row][i]);
        }
        return res;
    }
};
/*
�����������ⷨ�е��±��ת���Ƚ���Ū�Ļ������ǿ���ʹ�����������������Լ��һЩ�ķ����������������������ķ�������Ҫ����Ҫȷ������
���������ߵ�λ�ã���ô��ʼ����ʱ���ϱ�up����0���±�down����m-1�����left��0���ұ�right��n-1��Ȼ�����ǽ���whileѭ�����ȱ����ϱߣ�
������Ԫ�ؼ�����res��Ȼ���ϱ�����һλ�������ʱ�ϱߴ����±ߣ�˵����ʱ�Ѿ���������ˣ�ֱ��break��ͬ������±ߣ���ߣ��ұߣ����ν�
�����Ӧ�Ĳ����������ͻ�ʹ��������й��ɣ����Ҳ��׳����μ��������£�
*/ 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true) {
            for (int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int j = right; j >= left; --j) res.push_back(matrix[down][j]);
            if (--down < up) break;
            for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};
