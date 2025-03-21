public class Solution {
    public bool IsSubsequence(string s, string t) {
        int l = 0 , r = 0 ; 
        while(l < s.Length && r < t.Length){
            if (s[l] == t[r]){
                l++ ;
                r++ ; 
            }
            else 
                r++ ; 
        }

        return l == s.Length ; 
    }
}
