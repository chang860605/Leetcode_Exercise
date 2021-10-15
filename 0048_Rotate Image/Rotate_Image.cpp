class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp = INT_MIN;
        for(int i = 0 ; i < n/2 ; i++ )
        {
            for(int j = 0 ; j < (n+1)/2 ; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
                
                
            }
        }
    }
};


// Time  Complexity: O(n^2)
// Space Complexity: O(1)

// 調整1/4個matrix size次數，每次做4個位置互換，奇數自然中間不換
// 以3x3為例
//   [0,0] , [0,2] , [2,2] , [2,0] 
// =>[2,0] , [0,0] , [0,2] , [2,2]

//   [0,1] , [1,2] , [2,1] , [1,0]
// =>[1,0] , [0,1] , [1,2] , [2,1]

// x,y軸各4個位置對應 j , i , n-1-j , n-1-i
// 以一個斜對應，x=>對到下一個y
// 此題也能用 reverse+transpose操作