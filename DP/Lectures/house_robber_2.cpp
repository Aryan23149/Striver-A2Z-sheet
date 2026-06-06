class Solution {
    public:
        int funcMemo(int index,int n ,vector<int> & nums,vector<int> & dp){
                if(index>=n){
                    return 0;
                }
                if(dp[index]!=-1){return dp[index];}
                int pick=funcMemo(index+2,n,nums,dp)+nums[index];
                int not_pick=funcMemo(index+1,n,nums,dp);
                dp[index]=max(pick,not_pick);
                return dp[index];
            }
        int func(vector<int> &nums, int index,int n){
            if(index>=n){
                return 0;
            }
            int pick=func(nums,index+2,n) + nums[index];
            int non_pick=func(nums,index+1,n);
            return max(pick,non_pick);
        }
        int cleanerFuncTabu(vector<int> & nums ){
            int n = nums.size();
            vector<int> dp(n + 2, 0); // extra space to avoid bounds checks
            for(int i = n - 1; i >= 0; i--){
                int pick = nums[i] + dp[i + 2];
                int not_pick = dp[i + 1];
                dp[i] = max(pick, not_pick);
            }
            return dp[0];
        }
        int spaceOptimizedTabu(vector<int> & nums){
            int n=nums.size();
            vector<int> dp(n+2,0);
            int current;
            int next1=0;
            int next2=0;
            for(int i=n-1;i>=0;i--){
                int pick=nums[i]+next2;
                int not_pick=next1;
                current=max(pick,not_pick);
                next2=next1;
                next1=current;
            }
            return current;
        }
        int rob(vector<int>& nums) {
            // brute force approach with TC: O(2 raised N) and SC: O(2N)
            // attributed to recursion stack space and given array
            // int n =nums.size();
            // if(n==1) return nums[0];
            // return max(func(nums,0,n-1),func(nums,1,n));
    
            // recursion + memoization
            // time complexity: O(2N)=O(N) is for whole algorithm , 
            // space complexity: O(5N)=O(N) for recursion stack and 2 dp and 2 array we used this accounts for auxilary space 
    
            // int n=nums.size();
            // vector<int> arr1,arr2;// O(2N)=O(N)
            // if(n==1){
            //     return nums[0];
            // }
            // for(int i=0;i<n;i++){
            //     if(i!=0) arr1.push_back(nums[i]);
            //     if(i!=n-1) arr2.push_back(nums[i]);
            // }
            // vector<int> dp1(n-1,-1);// O(N)
            // vector<int> dp2(n-1,-1);// O(N)
            // return max(funcMemo(0,n-1,arr1,dp1),funcMemo(0,n-1,arr2,dp2));
    
            // tabulation code
            //time complexity is O(N+N+N) for filling array solving dp twice
            // space complexity is O(2N + 2N)
            // int n=nums.size();
            // if(n==1){
            //     return nums[0];
            // }
            // vector<int> arr1,arr2;
            // for(int i=0;i<n;i++){
            //     if(i!=n-1){
            //         arr1.push_back(nums[i]);
            //     }
            //     if(i!=0){
            //         arr2.push_back(nums[i]);
            //     }
            // }
            // return max(cleanerFuncTabu(arr1),cleanerFuncTabu(arr2));
            // space optimized tabulation
            // time complexity is O(N+2N) for filling arrays and solving dp
            // space complexity is O(2N) arr 1 and arr 2
            int n=nums.size();
            if(n==1){
                return nums[0];
            }
            vector<int> arr1,arr2;
            for(int i=0;i<n;i++){
                if(i!=n-1){
                    arr1.push_back(nums[i]);
                }
                if(i!=0){
                    arr2.push_back(nums[i]);
                }
            }
            return max(spaceOptimizedTabu(arr1),spaceOptimizedTabu(arr2));
        }
    };