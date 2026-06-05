#include <iostream>
#include <vector>
using namespace std;
void generate_parenthesis(int num,int index,int balance,string & paren){
    if(index==2*num){
        if(balance==0){
            cout<<paren<<" ";
        }
        return;
    }
    if(balance>=0){
        paren.push_back('(');
        generate_parenthesis(num,index+1,balance+1,paren);
        paren.pop_back();
        paren.push_back(')');
        generate_parenthesis(num,index+1,balance-1,paren);
        paren.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    string empty="";
    generate_parenthesis(n,0,0,empty);
    cout<<endl;
}