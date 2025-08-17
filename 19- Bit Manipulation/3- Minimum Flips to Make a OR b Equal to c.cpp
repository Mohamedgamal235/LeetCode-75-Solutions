class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0 ;
        while (a || b || c) {
            if (c % 2 == 1) {
                if (a % 2 == 0 && b % 2 == 0)
                    flip++ ;
            }
            else {
                if (a % 2 == 1)
                    flip++ ;
                if (b % 2 == 1)
                    flip++ ;
            }
            a >>= 1 ;
            b >>= 1 ;
            c >>= 1 ;
        }
        return flip;
    }
};