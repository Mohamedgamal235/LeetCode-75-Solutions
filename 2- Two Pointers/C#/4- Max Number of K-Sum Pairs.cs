public class Solution {
    public int MaxOperations(int[] nums, int k) {
        int l = 0 , r = nums.Length - 1 ; 
        int ans = 0 ; 
        Array.Sort(nums) ; 
        while(l < r){
            if (nums[l] + nums[r] > k)
                r-- ;
            else if (nums[l] + nums[r] < k)
                l++ ; 
            else {
                ans++ ; 
                l++ ; 
                r-- ;
            }
        }

        return ans ;
    }
}