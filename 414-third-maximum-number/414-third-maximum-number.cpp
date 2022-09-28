class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long long n = nums.size();
        
     
            
        
        long long first=LONG_MIN , second=LONG_MIN , third=LONG_MIN;
        for(long long i=0 ;i<n ;i++)
        {
            if (nums[i] == first || nums[i] == second || nums[i] == third)
                continue;
            if(nums[i]>first)
            {
                third=second;
                second=first;
                first=nums[i];
            }
            
            else if(nums[i]>second)
            {
                
                third=second;
                second=nums[i];
            }
            else if(nums[i]>third)
            {
                third=nums[i];
            }
        }
       return third == LONG_MIN ? first : third;
    }
    
    
//         long one = LONG_MIN, two = LONG_MIN, three = LONG_MIN;
//         for (int num : nums) {
//             if (num == one || num == two || num == three)
//                 continue;
            
//             if (num > one) {
//                 three = two;
//                 two = one;
//                 one = num;
//             } else if (num > two) {
//                 three = two;
//                 two = num;
//             } else if (num > three) {
//                 three = num;
//             }
//         }
        
//         return three == LONG_MIN ? one : three;
//     }
};