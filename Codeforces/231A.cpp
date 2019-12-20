#include <iostream>
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main() {
    lli n;
    cin>>n;
    // vector<int> mat[n];
    lli ans = 0;
    for(int i=0;i<n;i++)
    {
        int num = 0;
        for(int j=0;j<3;j++)
        {
            int temp;
            cin>>temp;
            if(temp)
                num++;
        }
        if(num>=2)
            ++ans;
    }
    cout<<ans<<endl;
}