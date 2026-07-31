class Solution {
    public:
        int solve(vector<int> & nums,int goal){
            int n = nums.size();
            int count=0;
            for(int i=0;i<n;i++){
                int sum =0;
                for(int j=i;j<n;j++){
                    sum+=nums[j];
                    if(sum>goal){
                        break;
                    }
                    else if (sum==goal) count++;
                }
            }
            return count;
        }
        int slidingWindows(vector<int> &nums,int goal){
            int n = nums.size();
            if(goal<0) return 0;
            int low = 0;
            int high =0;
            int sum=0;
            int count=0;
            while(high<n){
                sum+=nums[high];
                while(sum>goal){
                    sum-=nums[low];
                    low++;
                }
                count+=high-low+1;
                high++;
            }
            return count;
        }
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            // brute force approach
            // tc:O(N*N)
            // sc :O(1)
            // checking all possible subarrays cleverly
           // return solve(nums,goal);
    
           // optimal approach using two pointers and sliding windows
           //time complexity : O(N)
           //space complexity: O(1)
           // concept: exact sum = atmost(sum)-atmost(sum-1)
           return slidingWindows(nums,goal)-slidingWindows(nums,goal-1);
        }
    };