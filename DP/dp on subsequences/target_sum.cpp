class Solution {
    public:
        int solve(vector<int> & nums,int target,int i){
            if(i==nums.size()){
                if(target==0){
                    return 1;
                }
                return 0;
            }
            int element = nums[i];
            int pick_plus=solve(nums,target-element,i+1) ;
            int pick_minus=solve(nums,target+element,i+1);
            return pick_plus+pick_minus;
        }
        int solveMemo(vector<int> & nums,int target,int i,vector<vector<int>> & dp_pos,vector<vector<int>> & dp_neg){
            if (abs(target) > dp_pos[0].size()-1) return 0;
            if(i==nums.size()){
                if(target==0){
                    return 1;
                }
                return 0;
            }
            if(target>=0 && dp_pos[i][target]!=-1001){
                return dp_pos[i][target];
            }
            else if(target<0 && dp_neg[i][-1*target]!=-1001){
                return dp_neg[i][-1*target];
            }
    
            int element = nums[i];
            int pick_plus=solveMemo(nums,target-element,i+1,dp_pos,dp_neg) ;
            int pick_minus=solveMemo(nums,target+element,i+1,dp_pos,dp_neg);
            if(target>=0){
                return dp_pos[i][target]=pick_plus+pick_minus;
            }
            return dp_neg[i][-1*target]=pick_plus+pick_minus;
        }
        int solveTabu(vector<int> & nums,int target){
            int n = nums.size();
            int sum=0;
            for(int i : nums) sum+=i;
            if(abs(target)>sum) return 0;
            vector<vector<int>> dp_pos(n+1,vector<int>(sum+1,-1001));
            vector<vector<int>> dp_neg(n+1,vector<int>(sum+1,-1001));
            for(int i = 1;i<=target;i++){
                dp_pos[n][i]=0;
                dp_neg[n][i]=0;
            }
            dp_pos[n][0]=1;
            for(int i=n-1;i>=0;i--){
                int element= nums[i];
                int upper_limit=target;
                if(upper_limit<0){
                    upper_limit*=-1;
                }
                for(int j=upper_limit;j>=0;j--){
                    int pick_plus=target-element;
                    if(pick_plus>=0){
                        pick_plus=dp_pos[i+1][pick_plus];
                    }
                    else pick_plus=dp_neg[i+1][-1*pick_plus];
                    int pick_minus=target+element;
                    if(pick_minus>=0){
                        pick_minus=dp_pos[i+1][pick_minus];
                    }
                    else pick_minus=dp_neg[i+1][-1*pick_minus];
                    if(target<0) dp_neg[i][j]=pick_plus+pick_minus;
                    else dp_pos[i][j]=pick_plus+pick_minus;
                }
            }
            if(target>=0){
                return dp_pos[0][target];
            }
            return dp_neg[0][-1*target];
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            // brute force approach
            // time complexity is O(2 raised N)
            // space complexity is O(N)
            // return solve(nums,target,0);
    
            // memoization approach
            // time complexity :  O(2*n*sum)
            // space complexity: O(2*n*sum+n) for dp vectors and recursion stack space
            // int sum=0;
            // for(int i : nums) sum+=i;
            // vector<vector<int>> dp_pos(nums.size(),vector<int>(sum+1,-1001));
            // vector<vector<int>> dp_neg(nums.size(),vector<int>(sum+1,-1001));
            // return solveMemo(nums,target,0,dp_pos,dp_neg);
    
            // tabulation appraoch
            return solveTabu(nums,target);
        }
    };