 // 2 Loops
 int findDuplicate_2loops(int nums[]) {
        int len=sizeof(nums)/sizeof(nums[0]);
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }

        return len;
    }

// Visited
    public static int findDuplicate_mark(int[] nums) {
        int len = nums.length;
        for (int num : nums) {
            int idx = Math.abs(num);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }

        return len;
    }

int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[nums[i]%nums.size()]+=nums.size();
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]/nums.size()>1)
                return i;
        }
        return -1;
    }

//The best efficient approach is using slow and fast pointers.Didnt understand quite correctly,will revisit.