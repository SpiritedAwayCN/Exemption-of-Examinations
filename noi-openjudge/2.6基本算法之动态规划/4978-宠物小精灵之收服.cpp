#include<iostream>

constexpr int MAXN = 1005;
constexpr int MAXM = 505;
constexpr int MAXK = 105;
using namespace std;

short dp[MAXN][MAXM];
//��ά�������� ǰi����Ʒ��j����k�������ܲ����ĸ�������ά��
//������������������С����ֵ
int n, m, K, ball[MAXK], hp[MAXK];
int main() {
	cin >> n >> m >>K;
	for (int i = 1; i <= K; i++)
		cin >> ball[i] >> hp[i];
	for (int i = 1; i <= K; i++)
		for (int j = n; j >= ball[i]; j--)
			for (int k = m; k > hp[i]; k--) {
				if(dp[j - ball[i]][k - hp[i]] + 1>dp[j][k])
					dp[j][k] = dp[j - ball[i]][k - hp[i]] + 1;
			}
	int ans = dp[n][m], k = m - 1;
	while (dp[n][k] == ans && k > 0)k--;
	//ע��������Զ���
	cout << ans << ' ' << m - k << endl;
	return 0;
}
