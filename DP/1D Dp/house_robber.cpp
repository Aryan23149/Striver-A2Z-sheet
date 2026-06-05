class Solution {
    public:
        int func(int index,int n,vector<int> & nums){
            if(index>=n){
                return 0;
            }
            int pick=func(index+2,n,nums)+nums[index];
            int not_pick=func(index+1,n,nums);
            return max(pick,not_pick);
        }
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
        int funcTabu(vector<int> & nums ){
            int n= nums.size();
            vector<int> dp(n,-1);
            //dp[i] represents max robbery from index i to n -1
            dp[n-1]=nums[n-1];// represents max robbery from index n-1 to n-1 which is ofcourse picking up the ith index
            for(int i=n-2;i>=0;i--){//filling up dp array which is equivalent of solving all intermediate subproblems
                int pick=nums[i];//if we pick the element then it means its robbed amount shall be added in the pick
                if(i+2<n && dp[i+2]!=-1 ){
                    pick+=dp[i+2];// if after picking ith index we shall go to i+2 th index whose solution is already we have got so adding that if that is beyond the range of our problem then we dont add that 
                }
                int non_pick=dp[i+1];// if we dont pickup this index then we moved on to next index and from that index to n-1 is given by dp[i+1]
                dp[i]=max(pick,non_pick);// we fill our answer for the subproblem
            }
            return dp[0];// on our way to solve all the subproblems...we solved our problem
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
        int spaceOptimizedFuncTabu(vector<int> & nums){
            int next1=0;
            int next2=0;
            int current=0;
            int n = nums.size();
            for(int i=n-1;i>=0;i--){
                current=max(nums[i]+next2,next1);
                next2=next1;
                next1=current;
            }
            return current;
        }
        int rob(vector<int>& nums) {
            // brute force is recursive solution
            // time complexity is O(2 raised n) for t(n)=t(n-1)+t(n-2)....which t(n) O(2 raised n)
            //and space complexity is O(n) as max depth of recursion tree is N  O(n) 
            // return func(0,nums.size(),nums);
    
            // approach 2: recursion + memoization
            // time complexity is O(n) as there are n integers in dp to be filled and each call takes constant time for computation
            // space complexity is O(n) as we are using now recurstion stack space whose max depth is n and n for dp array
            // int n=nums.size();
            // vector<int> dp(n,-1);// dp[i] represents maximum amount that can be stolen from house ith to n-1 th house
            // return funcMemo(0,nums.size(),nums,dp);
    
            // approach 3: tabulation approach
            // time complexity: O(n) for filling n dp in linear order 
            // space complexity : O(n) for using dp array
            //    return cleanerFuncTabu(nums); this is chatgpt version
            //    return funcTabu(nums);// this is the code i wrote
    
            // approach 4: space optimized tabulation with tc: O(n) and sc:O(1)
            return spaceOptimizedFuncTabu(nums);
        }
    };