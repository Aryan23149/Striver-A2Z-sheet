#include <iostream>
#include <vector>
using namespace std;

bool subsequences_with_sumk(vector<int> & sequence,int index,int n,int sum){
    if(index==n){
        if(sum==0){
            return true;
        }
        return false;
    }

    if(subsequences_with_sumk(sequence,index+1,n,sum-sequence[index])){
        return true;
    };
    if(subsequences_with_sumk(sequence,index+1,n,sum)){
        return true;
    };
    return false;
}
int main(){

    vector<int> a;
    a={3,1,2};
    // a.push_back(3);
    // a.push_back(1);
    // a.push_back(2); 
    
    int k=2;

    
    cout<<subsequences_with_sumk(a,0,a.size(),k); //time complexity is O(2^N) and space complexity is O(N+N)=O(2N)=O(N)
    cout<<endl;

    return 0;
}