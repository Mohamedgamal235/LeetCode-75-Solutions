public class Solution {
    public double FindMaxAverage(int[] nums, int k) {
        double sum = 0 , average = 0; 
        for (int i = 0 ; i < k ; i++)
            sum += nums[i] ; 
            
        average = Math.Round(sum / k , 5) ;
        for (int i = k ; i < nums.Length ; i++){
            sum -= nums[i-k];
            sum += nums[i] ; 
            average = Math.Max(average , Math.Round(sum / k , 5));
        }
        return average ; 
    }
}