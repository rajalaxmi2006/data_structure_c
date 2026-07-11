void sortColors(int* nums, int numsSize) {
    int zero = 0 ;
    for(int index = 0 ; index < numsSize ; index ++){
        if(nums[index] == 0){
            int temp = nums[index];
            nums[index] = nums[zero];
            nums[zero] = temp;

            zero++;
        }
    }
    int one = zero;
    for( int index = zero ; index < numsSize ; index++){
        if(nums[index] == 1){
            int temp = nums[index];
            nums[index] = nums[one];
            nums[one] = temp;

            one++;
        }
    }
}