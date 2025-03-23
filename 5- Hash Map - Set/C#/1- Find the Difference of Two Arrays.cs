public class Solution {
    public IList<IList<int>> FindDifference(int[] nums1, int[] nums2) {
        HashSet<int> st1 = new HashSet<int>(nums1);
        HashSet<int> st2 = new HashSet<int>(nums2);

        List<int> lst1 = new List<int>() ; 
        foreach(int x in st1){
            if (!st2.Contains(x))
                lst1.Add(x) ;
        }

        List<int> lst2 = new List<int>() ; 
        foreach(int x in st2){
            if (!st1.Contains(x))
                lst2.Add(x) ;
        }
        
        return new List<IList<int>> { lst1, lst2 };
    }
}