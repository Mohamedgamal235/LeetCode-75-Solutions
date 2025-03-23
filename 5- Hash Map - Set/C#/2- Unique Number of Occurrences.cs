public class Solution {
    public bool UniqueOccurrences(int[] arr) {
        Dictionary<int , int> freq = new Dictionary<int, int>() ; 

        foreach(int x in arr){
            if (freq.ContainsKey(x))
                freq[x]++ ; 
            else 
                freq[x] = 1 ; 
        }
            
        HashSet<int> st = new HashSet<int>() ; 
        foreach(KeyValuePair<int , int> p in freq){
            if (!st.Contains(p.Value))
                st.Add(p.Value);
            else 
                return false ; 
        }
        return true ; 
    }
}