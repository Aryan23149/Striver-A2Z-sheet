class Solution {
    public:
        int check(unordered_map<char,int> & helper){
            if(helper['a']>0 && helper['b']>0 && helper['c']>0){
                return 1;
            }
            return 0;
        }
        int solve(string s){
            int n = s.length();
            int count =0;
            for(int i=0;i<n;i++){
               unordered_map<char,int> helper;
                for(int j=i;j<n;j++){
                    char element = s[j];
                    helper[element]++;
                    if(check(helper)){
                        count+=n-j;
                        break;
                    }
                }
            }
            return count;
        }
        int slidingWindows(string s){
            int low =0 , high =0;
            int  n = s.size();
            unordered_map<char,int> helper;
            int count = 0;
            while(high<n){
                char element = s[high];
                helper[element]++;
                while(check(helper)){
                    count+=n-high;
                    helper[s[low]]--;
                    low++;
                }
                high++;
            }
            return count;
        }
        int numberOfSubstrings(string s) {
            // Brute Force Approach
            // Time Complexity : O(N*N)
            // Space Complexity : O(N)
           // return solve(s);
    
           // Optimized Approach using two pointers and sliding windows
           // time complexity:O(N)
           // space complexity:O(N)
           return slidingWindows(s);
        }
    };