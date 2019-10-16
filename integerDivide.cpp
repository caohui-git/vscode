#include<iostream>
#include<cstring>
using namespace std;

const int maxn=100;
int n,k;
int dp[maxn][maxn];
int x[maxn];

int nums(){
    //
    for(int i=0;i<=k;++i){
        dp[1][i]=1;
    }
    for(int j=1;j<=n;++j){
        dp[j][1]=1;
    }
    //
    for(int i=2;i<=n;++i){
        for(int j=2;j<=k;++j){
            if(j>i)
                dp[i][j]=dp[i][i];
            else if(j==i)
                dp[i][j]=dp[i][j-1]+1;
            else if(j<i)
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
        }
    }
    return dp[n][k];

}

void dfs(int sum,int len){
    if(sum==n){
        cout<<x[1];
        for(int i=2;i<len;++i){
            cout<<"+"<<x[i];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=k;++i){
        //i shouldn't small than which before it
        if(i>=x[len-1]&&sum+i<=n){
            x[len]=i;
            dfs(sum+i,len+1);
            x[len]=0;
        }
    }
    return;
}

int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(dp,0,sizeof(0));
        //cout<<(1>x[0]);
        cout<<nums()<<endl;
        dfs(0,1);
    }
}