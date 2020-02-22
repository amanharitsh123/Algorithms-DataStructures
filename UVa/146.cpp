#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
int main() {
	string input;
	cin>>input;
	while(input!="#") {
        if(next_permutation(input.begin(),input.end()))
            cout<<input<<endl;
        else
            cout<<"No Successor"<<endl;
        cin>>input;
	}
}
