/*
brute force(暴力方法） 
Initialize dist[i][j]=INT_MAX for all {i,j} cells.
Iterate over the matrix.
If cell is 0, dist[i][j]=0,
Else, for each 1 cell,
Iterate over the entire matrix
If the cell is 0, calculate its distance from current cell as abs(k-i)+abs(l-j).
If the distance is smaller than the current distance, update it.
显然会超时，相当于对matrix数组遍历了两次，时间复杂度为O((r*c)^4) 
*/
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0)
                dist[i][j] = 0;
            else {
                for (int k = 0; k < rows; k++)
                    for (int l = 0; l < cols; l++)
                        if (matrix[k][l] == 0) {
                            int dist_01 = abs(k - i) + abs(l - j);
                            dist[i][j] = min(dist[i][j], abs(k - i) + abs(l - j));
                        }
            }
        }
    }
    return dist;
}
/*
BFS
 A better brute force: Looking over the entire matrix appears wasteful and hence, we can use Breadth First Search(BFS) to 
 limit the search to the nearest 0 found for each 1. As soon as a 0 appears during the BFS, we know that the 0 is nearest, 
 and hence, we move to the next 1.

Think again: But, in this approach, we will only be able to update the distance of one 1 using one BFS, which could in fact, 
result in slightly higher complexity than the Approach #1 brute force. But hey,this could be optimised if we start the BFS 
from 0s and thereby, updating the distances of all the 1s in the path.

Algorithm

For our BFS routine, we keep a queue, q to maintain the queue of cells to be examined next.
We start by adding all the cells with 0s to q.
Intially, distance for each 0 cell is 0 and distance for each 1 is INT_MAX, which is updated during the BFS.
Pop the cell from queue, and examine its neighbours. If the new calculated distance for neighbour {i,j} is smaller, we 
add {i,j} to q and update dist[i][j].

将所有0点置位0,1点置位INT_MAX，然后从0点开始遍历，当遇到1时，判断其值与相邻点加一是否更大，如果更大则置位相邻点加一，这样时间复杂度在
O(r*c)。 
*/ 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        int rows=matrix.size();
        if(rows==0){
            return matrix;
        }
        int cols=matrix[0].size();
        vector<vector<int> > dist(rows,vector<int>(cols,INT_MAX));
        queue<pair<int,int> > q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int new_r=cur.first+dx[i],new_c=cur.second+dy[i];
                if(new_r>=0&&new_c>=0&&new_r<rows&&new_c<cols){
                    if(dist[new_r][new_c]>dist[cur.first][cur.second]+1){
                        dist[new_r][new_c]=dist[cur.first][cur.second]+1;
                        q.push({new_r,new_c});
                    }
                }
            }
        }
        return dist;
    }
};
/*
DP 动态规划：
The distance of a cell from 0 can be calculated if we know the nearest distance for all the neighbours, 
in which case the distance is minimum distance of any neightbour + 1. And, instantly, the word come to mind DP!!
For each 1, the minimum path to 0 can be in any direction. So, we need to check all the 4 direction. In one iteration 
from top to bottom, we can check left and top directions, and we need another iteration from bottom to top to check 
for right and bottom direction.

Algorithm

Iterate the matrix from top to bottom-left to right:
Update dist[i][j]=min(dist[i][j],min(dist[i][j-1],dist[i-1][j])+1) i.e., minimum of the current dist and distance from top or left neighbour +1, 
that would have been already calculated previously in the current iteration.
Now, we need to do the back iteration in the similar manner: from bottom to top-right to left:
Update dist[i][j]=min(dist[i][j],min(dist[i][j+1],dist[i+1][j])+1) i.e. minimum of current dist and distances calculated from bottom and 
right neighbours, that would be already available in current iteration. 
*/
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

    //First pass: check for left and top
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0)
                dist[i][j] = 0;
            else {
                if (i > 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j > 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }

    //Second pass: check for bottom and right
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i < rows - 1)
                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            if (j < cols - 1)
                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        }
    }

    return dist;
}

