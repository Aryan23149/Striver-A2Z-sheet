class Solution {
    public:
        int solve(string s, int k){
            int n = s.length();
            int ans=0;
            for(int i =0;i<n;i++){
                unordered_map<char,int> helper;
                int maxi_freq=0;
                for(int j=i;j<n;j++){
                    char element= s[j];
                    helper[element]++;
                    maxi_freq=max(maxi_freq,helper[element]);
                    int space_available=(j-i+1) - maxi_freq;
                    if(space_available>k){
                        break;
                    }
                    else{
                        ans=max(ans,j-i+1);
                    }
                }
            }
            return ans;
        }
        int slidingWindow(string s,int k){
            int n = s.length();
            int i = 0;
            int j = 0;
            int ans =0;
            int maxi_freq=0;
            unordered_map<int,int> help;
            while(j<n){
                char element_rhs=s[j];
                help[element_rhs]++;
                maxi_freq=max(maxi_freq,help[element_rhs]);
                if(j-i+1-maxi_freq<=k) ans = max(ans,j-i+1);
                else{
                    while(j-i+1-maxi_freq>k){
                        int element_lhs=s[i];
                        help[element_lhs]--;
                        i++;
                    }  
                }
                j++;
            }
            return ans;
        }
        int characterReplacement(string s, int k) {
            // Brute Force Approach
            // Time Complexity:O(N*N)
            // Space Complexity:O(N)
           // return solve(s,k);
    
           //  Optimal Solution: Using Two Pointers and Sliding Window
           // Time Complexity:O(N)
           // Space Complexity:O(N)
        //   this is O(N) time and O(1) auxiliary space in this specific problem because there are only 26 uppercase English letters. Your unordered_map technically gives you O(1) expected space here because the alphabet is bounded, but an array is even cleaner:
           return slidingWindow(s,k);
        }
    };