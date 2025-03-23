public class Solution {
    public int PivotIndex(int[] nums) {
        int n = nums.Length ; 
        long[] prefix = new long[n+1] ;
        for (int i = 1 ; i <= n ; i++)
            prefix[i] += prefix[i-1] + nums[i-1] ; 

        for (int i = 1 ; i <= n ; i++){
            long left = prefix[i] - nums[i-1] ; 
            long right = prefix[n] - prefix[i] ; 
            if (left == right)
                return i - 1 ; 
        }

        return -1 ;  
    }
}