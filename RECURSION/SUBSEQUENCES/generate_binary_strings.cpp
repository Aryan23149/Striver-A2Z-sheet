#include <iostream>
#include <vector>
using namespace std;
void generate_binary_strings(int n,int i,string& bs){
    if(n==i){
        cout<<bs<<" ";
        return;
    }
    
    if(bs.empty() || bs[i-1]=='0'){
        bs.push_back('1');
        generate_binary_strings(n,i+1,bs);
        bs.pop_back();
    }
    bs.push_back('0');
    generate_binary_strings(n,i+1,bs);
    bs.pop_back();
}

int main(){
    int n;
    cin>>n;
    string empty="";
    generate_binary_strings(n,0,empty);
    return 0;
}
//time complexity: O(N*2^N) //space complexity: O(N+N)=O(2N)=O(N)