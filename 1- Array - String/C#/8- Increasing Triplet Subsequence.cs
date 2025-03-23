public class Solution {
    public bool IncreasingTriplet(int[] nums) {
        int f = int.MaxValue ; 
        int s = int.MaxValue ;

        foreach(int x in nums){
            if (f >= x)
                f = x ; 
            else if (s >= x)
                s = x ; 
            else 
                return true ; 
        } 
        return false ; 
    }
}