class Solution {
    // same as leetcode 704 solution
    public:
        int rsearch(vector<int> & nums,int low,int high,int target){
            if(low>high) return -1;
            int mid = low + (high-low)/2;
            if(nums[mid]>target) return rsearch(nums,low,mid-1,target);
            if(nums[mid]<target) return rsearch(nums,mid+1,high,target);
            return mid;
        }
        int search(vector<int>& nums, int target) {
            // the iterative approach 
            // time complexity : O(logN)
            // space complexity: O(1)
            // int low=0,high=nums.size()-1,mid;
            // while(low<=high){
            //     mid=low+(-low+high)/2;
            //     if(nums[mid]>target){
            //         high=mid-1;
    
            //     }
            //     else if(nums[mid]<target){
            //         low=mid+1;
            //     }
            //     else{
            //         return mid;
            //     }
            // }
            // return -1;
    
            // recursive approach
            // time complexity: O(LogN)
            // space complexity: O(LogN)
            int n = nums.size();
            return rsearch(nums,0,n-1,target);
        }
    };