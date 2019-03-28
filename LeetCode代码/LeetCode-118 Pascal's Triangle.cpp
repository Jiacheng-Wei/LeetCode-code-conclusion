class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > pascal;
        if (numRows==0) return pascal;
        const vector<int> firstrow=vector<int> {1};
        if (numRows>=1) pascal.push_back(firstrow);
        for (int i=1;i<numRows;i++)
        {
            vector<int> row;
            row.push_back(1);
            for (int j=1;j<i;j++)
            {
                row.push_back(pascal[i-1][j]+pascal[i-1][j-1]);
            }
            row.push_back(1);
            pascal.push_back(row);
        }
        return pascal;
    }
};
