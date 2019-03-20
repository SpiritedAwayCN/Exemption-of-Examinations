#include <stdio.h>
#include <stdlib.h>
#include <string.h>
constexpr auto MAX_LEN = 15;
int min_area[1 << MAX_LEN];
int occupion/**���������λ������¼��ĸ��������1��ʾδ�����ǣ�0��ʾ�ѱ�����**/;
int point[15][2]/**ÿ�������Ϣ**/, num/**��ĸ���**/;
int area(int i, int j)//����ĺ����������������ͬһֱ���ϵ����㣬���ص�����Ǿ��������ڼ�����С���ʱ���Զ���ȥ�ظ�ռ�õķ���
{
	if (point[i][0] == point[j][0]) return abs(point[i][1] - point[j][1]);
	if (point[i][1] == point[j][1]) return abs(point[i][0] - point[j][0]);
	return abs(point[i][1] - point[j][1])*abs(point[i][0] - point[j][0]);
}
int search(int n)/**��������������ֵΪ���ڴ����ռ�����,���ֵΪ��Ӧռ������������С���**/
{
	int i, j, k;
	if (min_area[n] >= 0)//�������״̬��Ӧ�������Ѿ����
		return min_area[n];
	if (n == 0)
		return min_area[n] = 0;
	min_area[n] = 40000000;
	for (i = 0; i < num; i++)
	{
		if (n&(1 << i))//�����i+1������δ��ռ��
		{
			for (j = 0; j < num; j++)
			{
				if (i != j)
				{
					int tmp, s;
					tmp = n & (~((1 << i) | (1 << j)));
					for (k = 0; k < num; k++)
						if ((point[i][0] == point[k][0] && point[j][1] == point[k][1]) || (point[i][1] == point[k][1] && point[j][0] == point[k][0]))
							tmp &= (~(1 << k));
					s = area(i, j) + search(tmp);
					if (s < min_area[n])
						min_area[n] = s;
				}
			}
		}
	}
	return min_area[n];
}
int main()
{
	int i;
	scanf("%d", &num);
	while (num)
	{
		for (i = 0; i < num; i++)
			scanf("%d%d", &point[i][0], &point[i][1]);
		memset(min_area, -1, sizeof(min_area));
		occupion = (1 << num) - 1;//����״̬��ʼ�������еĵ��Ӧ��λ����1
		printf("%d\n", search(occupion));
		scanf("%d", &num);
	}
	return 0;
}