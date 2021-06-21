#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define MVNum 100

typedef char VerTexType;
typedef int ArcType;
typedef int OtherInfo;

typedef struct ArcNode {
	ArcType adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;

typedef struct VNode {
	VerTexType data;
	ArcNode* firstarc;
}VNode;

typedef struct {
	VNode vertex[MVNum];
	int vertex_num, arc_num;
}ALGraph;

Status CreateUDG(ALGraph* G);
int LocateVertex(ALGraph G, VerTexType v);
void PrintGraph(ALGraph G);

void main() {
	ALGraph G;
	CreateUDG(&G);
	PrintGraph(G);
}

Status CreateUDG(ALGraph* G) {
	int i, j, k;
	VerTexType v1, v2;
	printf("请输入顶点数：");
	scanf("%d", &(G->vertex_num));
	printf("请输入边数：");
	scanf("%d", &(G->arc_num));
	for (i = 0; i < G->vertex_num; i++)
	{
		printf("请输入第%d顶点内容：", i + 1);
		getchar();
		scanf("%c", &(G->vertex[i].data));
		G->vertex[i].firstarc = NULL;
	}
	for (k = 0; k < G->arc_num; k++)
	{
		printf("请输入要连接的两个顶点的信息：");
		getchar();
		scanf("%c %c", &v1, &v2);
		i = LocateVertex(*G, v1);
		j = LocateVertex(*G, v2);
		ArcNode* arcnode_p = (ArcNode*)malloc(sizeof(ArcNode));
		arcnode_p->adjvex = j;
		arcnode_p->nextarc = G->vertex[i].firstarc;
		G->vertex[i].firstarc = arcnode_p;
		ArcNode* arcnode_q = (ArcNode*)malloc(sizeof(ArcNode));
		arcnode_q->adjvex = i;
		arcnode_q->nextarc = G->vertex[j].firstarc;
		G->vertex[j].firstarc = arcnode_q;
	}
	return OK;
}

int LocateVertex(ALGraph G, VerTexType v) {
	int i;
	for (i = 0; i < G.vertex_num; i++)
	{
		if (v == G.vertex[i].data)
		{
			return i;
		}
	}
	return -1;
}

void PrintGraph(ALGraph G) {
	int i;
	ArcNode* p;
	printf("位置  顶点  邻接顶点位置\n");
	for (i = 0; i < G.vertex_num; i++)
	{
		p = G.vertex[i].firstarc;
		printf("%-4d  %-4c  ", i, G.vertex[i].data);
		while (p != NULL)
		{
			printf("%-3d ", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}