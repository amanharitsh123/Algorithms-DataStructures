#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
        lli num,lo,hi,mid;
        cin>>num;
        lo=0;
        hi=num;
        while(lo<hi) {
            mid=(lo+hi)/2;
            if(mid*mid>num)
                hi=mid-1;
            else
                lo=mid+1;
        }
        if(lo*lo>num)
            cout<<(lo-1)<<endl;
        else 
            cout<<lo<<endl;
	}
}
