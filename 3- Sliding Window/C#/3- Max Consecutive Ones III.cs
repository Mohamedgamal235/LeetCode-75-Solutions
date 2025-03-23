public class Solution {
    public int LongestOnes(int[] nums, int k) {
        int l = 0 , r = 0 , zeros = 0 ; 
        int n = nums.Length ; 
        int ans = 0 ; 
        while(r < n){
            if (nums[r] == 0)
                zeros++ ; 
            
            while(l <= r && zeros > k){
                if (nums[l] == 0)
                    zeros-- ; 
                l++ ; 
            }

            ans = Math.Max(ans , r - l + 1);

            r++ ; 
        }

        return ans ; 
    }
}