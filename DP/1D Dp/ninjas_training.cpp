#include <climits>
int func(int index,int n, vector<vector<int>> &points,int previous_choice){
    if(index>=n) return 0;
    int max_points=-1;
    for(int i=0;i<3;i++){
        if(i!=previous_choice){
            int p=func(index+1,n,points,i)+points[index][i];
            max_points=max(max_points,p);  
        }
    }
    return max_points;
}
int funcMemo(int index,int previous_choice,vector<vector<int>> &dp,int n,vector<vector<int>> & points){
    if(index>=n) return 0;
    if(previous_choice!=-1 && dp[index][previous_choice]!=-1 ){
        return dp[index][previous_choice];
    }
    int max_points=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=previous_choice){
            int p=funcMemo(index+1,i,dp,n,points)+points[index][i];
            max_points=max(max_points,p);  
        }
    }
    return dp[index][previous_choice]=max_points;
}
int funcTabu(vector<vector<int>> & points){
    int n=points.size();
    vector<vector<int>> dp(n+1,vector<int>(3,0));

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<3;j++){
            int ans=0;
            for(int act=0;act<3;act++){
                if(act!=j){
                    ans=max(ans,points[i][act]+dp[i+1][act]);
                }
            }
            dp[i][j]=ans;
        }
    }
    int a = points[0][0] + dp[1][0];
    int b = points[0][1] + dp[1][1];
    int c = points[0][2] + dp[1][2];

    return max(a,max(b,c));
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // brute force approach 
    // time complexity: O(3*(2^n-1))
    // space complexity : O(n)
    //return func(0,n,points,-1);

    // memoization approach
    // time complexity is O(3*3N)
    // space complexity is O(3N + N +N)=O(5N)
    // dp[i][j] = points achieved from ith index to n-1)th index when choice j is made on ith index
    // vector<vector<int>> dp(n,vector<int>(3,-1));
    // int a= funcMemo(1,0,dp,n,points)+points[0][0];
    // int b=funcMemo(1,1,dp,n,points)+points[0][1];
    // int c =funcMemo(1,2,dp,n,points)+points[0][2];
   // return max(max(a,b),c);

    //Tabulation Approach
    // Time Complexity : O(N*3 + N*3*3)=O(12N)=O(N)...for initializing dp ,filling dp array in loop and returning answer
    // Space Complexity :O(3*N)=O(N)
    return funcTabu(points);

    
}