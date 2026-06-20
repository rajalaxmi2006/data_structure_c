void moveZeroes(int* nums, int numsSize) {
    int nonzero = 0;
    int temp;

    for ( int index = 0 ; index < numsSize ; index ++) {
            if(nums[index] != 0){
                temp=nums[index];
                nums[index]=nums[nonzero];
                nums[nonzero]=temp;

                nonzero++;
            }
        }
    }