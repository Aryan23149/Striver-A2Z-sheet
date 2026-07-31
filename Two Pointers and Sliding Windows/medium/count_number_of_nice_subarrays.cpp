class Solution {
    public:
        int solve(vector<int> & nums,int k){
            int n = nums.size();
            int count =0;
            for(int i =0;i<n;i++){
                int count_of_odd_numbers=0;
                for(int j=i;j<n;j++){
                    int element = nums[j];
                    if(count_of_odd_numbers<=k){
                        if(element%2==1){
                            count_of_odd_numbers++;
                        }
                        if(count_of_odd_numbers==k){
                            count++;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            return count;
        }
        int sliding_Windows(vector<int> &nums , int k){
            int i=0,j=0;
            int n= nums.size();
            int odd_count=0;
            int count=0;
            while(j<n){
                int element = nums[j];
                if(element%2==1) odd_count++;
                while(odd_count>k){
                    if(nums[i]%2==1) odd_count--;
                    i++;
                }
                count+=j-i+1;
                j++;
            }
            return count;
        }
        int numberOfSubarrays(vector<int>& nums, int k) {
            // brute force approach : 
            // tc : O(N*N)
            // sc : O(1)
            // return solve(nums,k);
    
    
            //optimal approach
            // tc: O(2N+2N) which is equivalent to O(N)
            // sc : O(1)
            return sliding_Windows(nums,k)-sliding_Windows(nums,k-1);
        }
    };