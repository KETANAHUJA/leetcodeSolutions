class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        if(n==2)
        {
            if(nums[0]>nums[1])
                return 2;
            else
                return 0;
        }
        int smallest = INT_MAX,largest=INT_MIN;
        if(nums[0]>nums[1])
        {
            smallest = min(smallest,nums[0]);
            largest = max(largest,nums[0]);
        }
        if(nums[n-2]>nums[n-1])
        {
            smallest = min(smallest,nums[n-1]);
            largest = max(largest,nums[n-1]);
        }
        for(int i=1;i<n-1;i++)
        {
            
             if(nums[i]>nums[i+1] || nums[i]<nums[i-1])
            {
                smallest = min(smallest,nums[i]);
                largest = max(largest,nums[i]);
            }             
        }
        if(smallest==INT_MAX)
            return 0;
        int l=0,r=n-1;
        while(smallest>=nums[l])
            l++;
        while(largest<=nums[r])
            r--;
        
        return r-l+1;
        
    }
};