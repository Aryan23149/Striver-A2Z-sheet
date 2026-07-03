class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            // using binary search concepts
            // time complexity: O(2LogN) equivalent to O(LogN)
            // space complexity: O(1)
            vector<int> answer={-1,-1};
            int n =nums.size();
            int lower_bound_index=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(lower_bound_index==n){
                return answer;
            }
            if(nums[lower_bound_index]>target) return answer;
            int upper_bound_index=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            answer[0]=lower_bound_index;
            answer[1]=upper_bound_index-1;
            return answer;
        }
    };