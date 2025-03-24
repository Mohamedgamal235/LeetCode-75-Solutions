public class Solution {
    public IList<bool> KidsWithCandies(int[] candies, int extraCandies) {
        int maxi = candies.Max() ; 

        List<bool> ans = new List<bool>() ;
        
        foreach(int x in candies){
            if (maxi <= x + extraCandies)
                ans.Add(true) ; 
            else 
                ans.Add(false) ; 
        }

        return ans ; 
    }
}