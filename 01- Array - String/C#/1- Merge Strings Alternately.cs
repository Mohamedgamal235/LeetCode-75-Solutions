public class Solution {
    public string MergeAlternately(string word1, string word2) {
        string ans = "" ; 

        int i = 0 , j = 0 ; 
        while(i < word1.Length && j < word2.Length){
            ans += word1[i] ; 
            ans += word2[j] ;
            i++ ;
            j++ ; 
        }

        while(i < word1.Length){
            ans += word1[i] ; 
            i++ ; 
        }

        while(j < word2.Length){
            ans += word2[j] ; 
            j++ ; 
        }

        return ans ; 
    }
}