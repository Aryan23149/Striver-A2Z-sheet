#include <iostream>
using namespace std;
void string_subseq(string input,int index,int n,string subseq){
    if(n==index){
        cout<<subseq<<" ";
        return;
    }
    string_subseq(input,index+1,n,subseq);
    string_subseq(input,index+1,n,subseq+input[index]);
}
int main(){
    string input;
    cin>>input;
    string_subseq(input,0,input.size(),"");
    cout<<endl;
    return 0;
}