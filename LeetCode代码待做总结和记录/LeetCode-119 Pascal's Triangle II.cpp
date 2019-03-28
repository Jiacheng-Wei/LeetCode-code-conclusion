//数学问题：给出求解详细的博客：https://www.cnblogs.com/grandyang/p/4031536.html 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};
