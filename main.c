//创建无向图\有向图邻接矩阵
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

typedef struct Arc
{
    //邻接矩阵结构体
    int vexnum,arcnum;//顶点和边的数量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    char vexs[MAX_VERTEX_NUM];//顶点向量

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
    //创建无向图邻接矩阵
    char v1,v2;
    int i,j,a,b,TD,sum;
    printf("输入邻接矩阵的顶点数：\n");
    scanf("%d",&G.vexnum);
    printf("输入邻接矩阵的边数\n");
    scanf("%d",&G.arcnum);
    for(i=0; i<G.vexnum; i++) //初始化邻接矩阵
    {
        for(j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j]=0;
        }
    }
    printf("输入邻接矩阵的顶点:\n");
    for(i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        scanf("%c",&G.vexs[i]);
    }
    printf("输入邻接矩阵的边：\n");
    for(j=0; j<G.arcnum;j++) //构造邻接矩阵
    {
        fflush(stdin);
        scanf("%c%c",&v1,&v2);
        a=LocateVex(G,v1);
        b=LocateVex(G,v2);
        G.arcs[a][b]=1;
        G.arcs[b][a]=1;
    }
    for(i=0;i<G.vexnum;i++)  //打印邻接矩阵
    {
        for(j=0;j<G.vexnum;j++)
        {
            printf("%d\t",G.arcs[i][j]);

        }
        printf("\n");
    }
    for(i=0;i<G.vexnum;i++)  //计算各个顶点的度
    {
        sum=0;
        for(j=0;j<G.vexnum;j++)
        {
           sum+=G.arcs[i][j];

        }
        printf("TD(%c)=%d\n",G.vexs[i],sum);
    }
    printf("请输入你要计算度的顶点：\n");
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
    //创建有向图邻接矩阵
    char v1,v2;
    int i,j,a,b,ID,OD;
    printf("输入邻接矩阵的顶点数：\n");
    scanf("%d",&G.vexnum);
    printf("输入邻接矩阵的边数\n");
    scanf("%d",&G.arcnum);
    for(i=0; i<G.vexnum; i++) //初始化邻接矩阵
    {
        for(j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j]=0;
        }
    }
    printf("输入邻接矩阵的顶点:\n");
    for(i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        scanf("%c",&G.vexs[i]);
    }
    printf("输入邻接矩阵的边：\n");
    for(j=0; j<G.arcnum;j++) //构造邻接矩阵
    {
        fflush(stdin);
        scanf("%c%c",&v1,&v2);
        a=LocateVex(G,v1);
        b=LocateVex(G,v2);
        G.arcs[a][b]=1;
    }
    for(i=0;i<G.vexnum;i++)  //打印邻接矩阵
    {
        for(j=0;j<G.vexnum;j++)
        {
            printf("%d\t",G.arcs[i][j]);

        }
        printf("\n");
    }
    for(i=0;i<G.vexnum;i++)  //计算各个顶点的度
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
    /*printf("请输入你要计算度的顶点：\n");
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
    //测试函数

    MGraph G;
    printf("无向图");
    Create_Linkarray(G);

}
