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
        reverse(x.begin(),x.end());
        auto it=x.begin();
        for(;it != x.end()-1;it++)
        {
            if(*it!='0')
                break;
        }
        string ans(it,x.end());
        cout<<ans<<endl;
	}
}
