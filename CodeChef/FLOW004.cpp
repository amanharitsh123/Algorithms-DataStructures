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
	lli testcases;
	cin>>testcases;
	while(testcases--) {
        string x;
        cin>>x;
        // cout<<*x.begin()-'0'<<endl;
        cout<<*x.begin() + *x.rbegin() -'0' -'0'<<endl;
	}
}
