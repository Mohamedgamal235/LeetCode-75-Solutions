public class Solution {
    public string GcdOfStrings(string str1, string str2) {
        
        if (!(str1 + str2).Equals(str2 + str1))
            return "" ; 

        int a = str1.Length , b = str2.Length ; 
        while(b != 0){
            int temp = b ; 
            b = a % b ; 
            a = temp ; 
        }

        return str1.Substring(0 , a) ; 
    }
}