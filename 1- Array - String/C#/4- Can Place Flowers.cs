public class Solution {
    public bool CanPlaceFlowers(int[] flowerbed, int n) {

        int sz = flowerbed.Length ; 
        if (n == 1 && sz == 1 && flowerbed[0] == 0)
            return true ; 
        
        for (int i = 0 ; i < sz - 1; i++){
            if (i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1 ; 
                n-- ; 
            }
                
            else if (i > 0 && flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1 ; 
                n-- ; 
            }
        }

        if (sz > 1 && n > 0 && flowerbed[sz-2] == 0 && flowerbed[sz-1] == 0)
            n-- ; 

        Console.Write(n) ; 

        return n <= 0 ; 
    }
}