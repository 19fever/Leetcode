public class Solution {
    public int singleNumber(int[] A) {
        int result = 0;
        
        for (int num : A) {
            result ^= num;
        }
        
        return result;
    }
}
