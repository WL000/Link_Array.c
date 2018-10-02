//��������ͼ\����ͼ�ڽӾ���
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

typedef struct Arc
{
    //�ڽӾ���ṹ��
    int vexnum,arcnum;//����ͱߵ�����
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //�ڽӾ���
    char vexs[MAX_VERTEX_NUM];//��������

} MGraph;

int LocateVex(MGraph G,char n)
{
    int i;
    for(i=0; i<G.vexs; i++)
    {
        if(G.vexs[i]==n)
            return i;
    }
}
void Create_UNLinkarray(MGraph G)
{
    //��������ͼ�ڽӾ���
    char v1,v2;
    int i,j,a,b,TD,sum;
    printf("�����ڽӾ���Ķ�������\n");
    scanf("%d",&G.vexnum);
    printf("�����ڽӾ���ı���\n");
    scanf("%d",&G.arcnum);
    for(i=0; i<G.vexnum; i++) //��ʼ���ڽӾ���
    {
        for(j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j]=0;
        }
    }
    printf("�����ڽӾ���Ķ���:\n");
    for(i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        scanf("%c",&G.vexs[i]);
    }
    printf("�����ڽӾ���ıߣ�\n");
    for(j=0; j<G.arcnum;j++) //�����ڽӾ���
    {
        fflush(stdin);
        scanf("%c%c",&v1,&v2);
        a=LocateVex(G,v1);
        b=LocateVex(G,v2);
        G.arcs[a][b]=1;
        G.arcs[b][a]=1;
    }
    for(i=0;i<G.vexnum;i++)  //��ӡ�ڽӾ���
    {
        for(j=0;j<G.vexnum;j++)
        {
            printf("%d\t",G.arcs[i][j]);

        }
        printf("\n");
    }
    for(i=0;i<G.vexnum;i++)  //�����������Ķ�
    {
        sum=0;
        for(j=0;j<G.vexnum;j++)
        {
           sum+=G.arcs[i][j];

        }
        printf("TD(%c)=%d\n",G.vexs[i],sum);
    }
    printf("��������Ҫ����ȵĶ��㣺\n");
    fflush(stdin);
    scanf("%c",&v1);
    a=LocateVex(G,v1);
    sum=0;
    for(i=0;i<G.vexnum;i++)
    {
        sum+=G.arcs[a][i];
    }
    printf("TD(%c)=%d\n",v1,sum);
}
void Create_Linkarray(MGraph G)
{
    //��������ͼ�ڽӾ���
    char v1,v2;
    int i,j,a,b,ID,OD;
    printf("�����ڽӾ���Ķ�������\n");
    scanf("%d",&G.vexnum);
    printf("�����ڽӾ���ı���\n");
    scanf("%d",&G.arcnum);
    for(i=0; i<G.vexnum; i++) //��ʼ���ڽӾ���
    {
        for(j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j]=0;
        }
    }
    printf("�����ڽӾ���Ķ���:\n");
    for(i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        scanf("%c",&G.vexs[i]);
    }
    printf("�����ڽӾ���ıߣ�\n");
    for(j=0; j<G.arcnum;j++) //�����ڽӾ���
    {
        fflush(stdin);
        scanf("%c%c",&v1,&v2);
        a=LocateVex(G,v1);
        b=LocateVex(G,v2);
        G.arcs[a][b]=1;
    }
    for(i=0;i<G.vexnum;i++)  //��ӡ�ڽӾ���
    {
        for(j=0;j<G.vexnum;j++)
        {
            printf("%d\t",G.arcs[i][j]);

        }
        printf("\n");
    }
    for(i=0;i<G.vexnum;i++)  //�����������Ķ�
    {
        OD=0;
        ID=0;
        for(j=0;j<G.vexnum;j++)
        {
           OD+=G.arcs[i][j];
           ID+=G.arcs[j][i];
        }
        printf("TD(%c)=%d\n",G.vexs[i],ID+OD);
    }
    /*printf("��������Ҫ����ȵĶ��㣺\n");
    fflush(stdin);
    scanf("%c",&v1);
    a=LocateVex(G,v1);
    sum=0;
    for(i=0;i<G.vexnum;i++)
    {
        sum+=G.arcs[a][i];
    }
    printf("TD(%c)=%d\n",v1,sum);*/
}
int main()
{
    //���Ժ���

    MGraph G;
    printf("����ͼ");
    Create_Linkarray(G);

}
