#include<stdio.h>
#define MAXK 55
int a[MAXK],b[MAXK],c[MAXK];
int main()
{
    int i,j;
    int n,k,p,pos,ans=0;
    scanf("%d%d%d",&n,&k,&p);
    for(i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(y<=p)
            pos=i;
        if(pos>=a[x])
            c[x]=b[x]; //c[x]��posǰ��ͬɫ�Ƶ����������ʱ����
        a[x]=i;//��ǰ��ɫ�����ֵ�λ��
        ans=ans+c[x];
        b[x]++;//�ѻ�ȡ��ͬɫ�ľƵ�����
    }
    printf("%d\n",ans);
    return 0;
}
