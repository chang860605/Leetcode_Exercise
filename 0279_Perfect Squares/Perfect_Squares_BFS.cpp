class Solution {
public:
    int numSquares(int n) {
        
        vector<bool> visited(n+1);
        queue<int> q;
        
        int steps = 1;
        
        for(int i = 1; i*i <= n; i++ )
        {
            if( i*i == n) return steps;
            q.push(i*i);
            visited[i*i] = true; 
        }                
           
        while( !q.empty() )
        {
            steps++;
            int size = q.size();
            for (int i = 0 ; i < size; i++) 
            {            
                int num = q.front();                 
                for (int j = 1; j*j <= n ; j++) 
                { 
                    int sum = num + j*j;
                    if( sum == n) return steps;
                    if( sum < n && !visited[sum])
                    {                        
                        q.push(sum);
                        visited[sum] = true;          
                    }
                } 
                q.pop();
            }
        }
        return -1;        
    }
};


// Time  Complexity: O(n^(3/2))
// Space Complexity: O(n)
// BFS
// 先將平方數都放入queue中，以及visited設定成true以剃除多餘的
// 一趟queue代表step要+1
// queue提出一個數後為了多一步進行比對=> j*j<=n => sum = num + j*j (多的這一個+1的step)
// 如果sum == n 自然返回當前step
// 如果sum比n還小以及visited[sum]還未走過=>代表要繼續往下=>push進入下一輪queue之中，當前這個visited[sum]設為true
// 當前這個數任務完成，pop掉
// 結束當前這一個node的一個size大小為原本q.size()的一輪，接下來為push進去的下一輪

// 時間複雜度為每一個node最差經歷過一次，每個node一輪有j*j<=n次要進行=>n*√n
