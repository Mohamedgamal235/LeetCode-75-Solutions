public class Solution {
    public int LargestAltitude(int[] gain) {
        int maxi = Math.Max(gain[0] , 0) ; 
        
        for (int i = 1 ; i < gain.Length ; i++){
            gain[i] += gain[i-1] ; 
            maxi = Math.Max(gain[i] , maxi );
        }
        return maxi ; 
    }
}