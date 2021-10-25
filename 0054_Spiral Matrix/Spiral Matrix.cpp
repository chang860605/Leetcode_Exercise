class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        for(int x=0, y=0;x<=m&&y<=n;x++,y++,m--,n--){
            for(int j = y;j <= n; j++){
                res.push_back(matrix[x][j]);
            }
            for(int i = x+1; i <= m; i++){
                res.push_back(matrix[i][n]);
            }
            for(int j = n-1; j >= y && x != m;j--){
                res.push_back(matrix[m][j]);
            }
            for(int i = m-1; i > x && y!= n;i--){
                res.push_back(matrix[i][y]);
            }
        }
        return res;
    }
};

// Time  Complexity: O(mn)
// Space Compelixty: O(1)

// 總共四輪一圈 每圈x,y軸各+1
// 第一輪 => 往右移，起始index為x軸當前紀錄的值+1，並右移x軸size的量
// 第二輪 => 往下移，起始index為y軸當前紀錄的值+1，並下移y軸size-1的量
// 第三輪 => 往左移，起始index為x軸size最後值往回-1，並左移x軸size-1的量
// 第四輪 => 往上移，起始index為y軸size最後值往回-1，並上移y軸size-1的量

// 做完一圈後，整個vector size自然x,y軸各-1，而記錄位置用的x,y變因為要內縮而+1