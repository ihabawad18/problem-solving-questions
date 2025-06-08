#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=1e6 +5;
int mem[105][1000];
int n,x;

// 4 5 1 3
ll memo[5005][5005][2];
vector<int> v(5005);
ll dp(int i,int j,int turn){
    if(j==i){
        if(turn==1){
            return (ll)v[i];
        }
        return 0;
    }
    ll &ret=memo[i][j][turn];
    if(ret!=-1){
        return ret;
    }
    if(turn==1){
        return ret=max(((ll)v[i])+dp(i+1,j,0),((ll)v[j])+dp(i,j-1,0));
    }
    else{
        ll choice1=((ll)v[i])+dp(i+1,j,0);
        ll choice2=((ll)v[j])+dp(i,j-1,0);
        if(choice1>=choice2){
            return ret=dp(i+1,j,1);
        }
        return ret=dp(i,j-1,1);
    }
 
}
int main() {
    memset(memo,-1,sizeof(memo));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<dp(0,n-1,1);
  return 0;
}
