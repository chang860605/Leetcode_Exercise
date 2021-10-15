class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n;i !=0; i/=2)
        {
            if(i%2!=0) res*=x;
            x*=x;
        }
        if(n<0)return 1/res;
        return res;
    }
};


// Time  Complexity: O(log(n))
// Space Complexity: O(1)
// 拆成2進位去算每次有1代表要乘上乘數，乘數每次移一位自然就是乘上自己
//27 => (11011)2
// 1*(2^1)*(2^2)*(skip)*(2^8)*(2^16) = (2^27)

