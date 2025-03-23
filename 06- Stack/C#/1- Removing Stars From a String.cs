public class Solution {
    public string RemoveStars(string s) {
        Stack<char> st = new Stack<char>();

        foreach(char c in s){
            if (c != '*')
                st.Push(c);
            else if (st.Count != 0 && c == '*')
                st.Pop() ;
        }
        char[] ans = new char[st.Count] ; 
        for (int i = st.Count - 1 ; i >= 0 ; i--)
            ans[i] = st.Pop() ; 

        return new string(ans); 
    }
}
