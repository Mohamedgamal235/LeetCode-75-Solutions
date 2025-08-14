/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
#define ll long long
    int guessNumber(int n) {
        ll l = 0 , r = n , mid = 0;
        while (l <= r) {
            mid = (l + r) / 2 ;
            if (guess(mid) == -1)
                r = mid - 1 ;
            else if (guess(mid) == 1)
                l = mid + 1 ;
            else
                break;
        }
        return mid ; 
    }
};