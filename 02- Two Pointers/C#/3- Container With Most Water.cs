public class Solution {
    public int MaxArea(int[] height) {
        int n = height.Length ; 
        int l = 0 , r = n - 1 ;
        int maxi = int.MinValue ; 
        while(l < r){
            int curr = Math.Min(height[l] ,height[r]) * (r - l);
            maxi = Math.Max(maxi , curr);
            if (height[l] > height[r])
                r-- ;
            else 
                l++ ; 
        }
        return maxi ; 
    }
}