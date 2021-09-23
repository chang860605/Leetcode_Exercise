class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0 ; i < flowerbed.size() ; i++ )
        {
            if(flowerbed[i] == 0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0))
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n<=0;
    }
};

// Time  Complexity: O(n)
// Space Complexity: O(1)
// 直覺題：
// 當下為0，或是擺在邊邊的case都考慮到就可以
