public class Solution {
    public string ReverseWords(string s) {
        string ans = "" ; 
        for (int i = 0 ; i < s.Length ; i++){
            if (i + 1 < s.Length && s[i] == ' ' && s[i+1] != ' ')
                ans += ' ' ; 
            else if (s[i] != ' ')
                ans += s[i] ; 
        }

        string[] str = ans.Split(" ");
        Array.Reverse(str) ; 
        string sss = string.Join(" " , str);

        return sss.Trim(); 
    }
}