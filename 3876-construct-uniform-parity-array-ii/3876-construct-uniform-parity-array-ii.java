class Solution {
    public boolean uniformArray(int[] nums1) {
       int MinOdd = Integer.MAX_VALUE;

       for (int num : nums1){
        if (num % 2 != 0 ){
            MinOdd = Math.min(MinOdd,num);
        }
       }
       if (MinOdd == Integer.MAX_VALUE ) return true;
       for (int num : nums1){
        if (num % 2 == 0 && num <=MinOdd ){
            return false;
        }
       }return true;
    }
}