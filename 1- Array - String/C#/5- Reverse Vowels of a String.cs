public class Solution
{
    public bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    public string ReverseVowels(string s)
    {
        int l = 0, r = s.Length - 1;
        char[] str = s.ToCharArray();
        
        while (l < r)
        {
            
            if (isVowel(str[l]) && isVowel(str[r]))
            {
                // make swap
                char c = s[l];
                str[l] = str[r];
                str[r] = c;

                l++;
                r--;
            }
            else if (!isVowel(str[l]))
                l++;
            else if (!isVowel(str[r]))
                r--; 
        }
        return new string(str) ;
    }
}