class Solution {
    public:
    
        int solve(vector<int> & arr,int k){
            int n = arr.size();
            int ans=0;
            for(int i=0;i<n;i++){
                int zero_count=0;
                for(int j=i;j<n;j++){
                    int element=arr[j];
                    if(element==0){
                        zero_count++;
                        if(zero_count<=k) ans=max(ans,j-i+1);
                        else break;
                    }
                    else{
                        ans=max(ans,j-i+1);
                    }
                }
            }
            return ans;
        }
        int solveOptimal(vector<int> & nums,int k){
            int i=0;int j=0;int n=nums.size();
            int zero_count=0;
            int ans=0;
            while(j<n){
                int element=nums[j];
                if(element==0){
                    zero_count++;
                    if(zero_count>k){
                        while(zero_count>k){
                            if(nums[i]==0) zero_count--;
                            i++;
                        }
                    }
                }
                ans=max(ans,j-i+1);
                j++;
            }
            return ans;
        }
        int longestOnes(vector<int>& nums, int k) {
            // brute force : For every subarray , we find the maximum number of consecutive 1 in the array with k flips atmost.
            // This takes us O(N^2) time complexity , O(1) Space Complexity
           // return solve(nums,k);
           return solveOptimal(nums,k);
        }
    };