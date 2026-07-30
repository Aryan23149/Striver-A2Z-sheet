class Solution {
    public:
        int solve(string s){
            int n = s.length();
            int ans=0;
            for(int i=0;i<n;i++){
                set<char> helper;
                string substring="";
                for(int j=i;j<n;j++){
                    char letter= s[j];
                    helper.insert(letter);
                    substring+=letter;
                    if(substring.length()==(int)helper.size()){
                        ans=max(ans,(int)helper.size());   
                    }
                    else{
                        break;
                    }
                }
            }
            return ans;
        }
        int solveOptimal(string s){
            int n =s.length();
            int i=0;
            int j=0;
            unordered_set<char> helper;
            int ans =0;
            while(j<n){
                char letter=s[j];
                if(helper.contains(letter)){
                    helper.erase(s[i]);
                    i++;
                }
                else{
                    helper.insert(letter);
                    ans=max(ans,j-i+1);
                    j++; 
                }
            }
            return ans;
        }
        int lengthOfLongestSubstring(string s) {
            // extreme brute force approach
            // time complexity is O(N square LogN)
            // as we have N square strings and N square characters and each insertion in set takes log(N) times...see my logic is for i=0...we shall have n insertions in set then for i=1 we have n-1 insertion ...for i=n-1 one insertion thus total roughly O(N^2) insertions each takingg logN tima 
            // Space complexity is O(N) for set used in each iteration n times ans substring of lenght O(N)
            //return solve(s);
    
            // Optimal Approach Using SLiding Windows and Sliding windows
            // Time Complexity : O(NLOGN) as there are n characters that get inserted in set each taking logN charactere....if we would use set then time complexity becomes O(N) as insertion , contains and erase takes O(1) time
            // Space Complexity: O(min(n,128)) for set if we have ascii O(min(n,256))
            return solveOptimal(s);
        }
    };