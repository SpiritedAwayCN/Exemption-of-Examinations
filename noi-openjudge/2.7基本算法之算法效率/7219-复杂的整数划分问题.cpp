#include<cstdio>
#include<cstring>
#define MAXN 55

int dp[MAXN][MAXN];
int n,k;
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(dp,0,sizeof(dp));
        //dp[i][j] ����i k�� ��1ʱ������Ϊdp[i-1][j-1]
        //����1ʱ��k����ȫ��-1 ����Ϊdp[i-j][j]
        for(int i=1;i<=n;i++)
            dp[i][1]=1;
        for(int i=1;i<=n;i++)
            for(int j=2;j<=k;j++){
                dp[i][j] = dp[i-1][j-1];
                if(i>j) dp[i][j]+=dp[i-j][j];
            }
        printf("%d\n",dp[n][k]);
        memset(dp,0,sizeof(dp));
        //dp[i][j] ����i����С��>=j������
        for(int i=1;i<=n;i++)
            dp[i][i]=1;
        for(int i=1;i<=n;i++)
            for(int j=i-1;j>=1;j--){
                dp[i][j] = dp[i][j+1]+dp[i-j][j+1];
            }
        printf("%d\n",dp[n][1]);

        memset(dp,0,sizeof(dp));
        //dp[i][j] ����i����С��>=j������
        for(int i=1;i<=n;i++)
            dp[i][i]=i&1;//ż��ʱ�޽�
        for(int i=1;i<=n;i++)
            for(int j=i-1;j>=1;j--){
                if(j&1)
                    dp[i][j] = dp[i][j+1]+dp[i-j][j];
                else
                    dp[i][j] = dp[i][j+1];
            }
        printf("%d\n",dp[n][1]);
    }
    return 0;
}
