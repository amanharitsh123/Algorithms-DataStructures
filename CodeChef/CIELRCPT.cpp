#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>
#include<math.h>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
        lli num,count;
        count=0;
        cin>>num;
        vector<int> arr;
        for(int i=0;i<12;i++)
            arr.push_back(pow(2,i));
        
        while(num)
        {
            for(auto it=arr.rbegin();it!=arr.rend();it++)
            {
                if(*it <= num)
                {
                    num -= *it;
                    ++count;
                    break;
                }
            }
        }
        cout<<count<<endl;
	}
}
