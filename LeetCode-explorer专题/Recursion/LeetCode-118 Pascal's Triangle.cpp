class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if(numRows==0) return res;
        res.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> newRow;
            newRow.push_back(1);
            for(int j=1;j<=i;j++)
            {
                if(j==i) newRow.push_back(1);
                else newRow.push_back(res[i-1][j]+res[i-1][j-1]);
            }
            res.push_back(newRow);
        }
        return res;
    }
};
