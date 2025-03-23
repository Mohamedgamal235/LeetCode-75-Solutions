public class Solution {
    public int Compress(char[] chars) {
        int n = chars.Length ; 
        if (n == 1)
            return 1 ; 

        int i = 0 ; 
        int ans = 0 ; 
        int j = 0 ; 
        while(i < n){
            char curr = chars[i] ; 
            int cnt = 0 ; 

            while(i < n && curr == chars[i]){
                i++ ; 
                cnt++ ; 
            }

            chars[j] = curr ; 
            j++ ; 

            if (cnt > 1){
                string s = cnt.ToString() ; 
                foreach(char c in s){
                    chars[j] = c ; 
                    j++ ; 
                }
            }
        }
        return j ; 
    }
}