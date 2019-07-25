#pragma warning(disable:4996)
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#define MAXVEX 100         //最大顶点数
#define INFINIT 65535
typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;
typedef struct{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numberVex, numberEdge;
}Mgraph;
void CreateMgraph(Mgraph &G){
	int num_vex, num_edge;
	int i, j, k, w = 0;
	char vex;
	printf("请输入图的顶点数与边数\n");
	//scanf("%d,%d", &G.numberVex, &G.numberEdge); //输入图的顶点数和边数
	std::cin >> num_vex >> num_edge;
	G.numberVex = num_vex;
	G.numberEdge = num_edge;
	for (i = 0; i < G.numberVex; i++){
		printf("请输入顶点\n");
		std::cin >> vex;
		G.vexs[i] = vex;
		for (j = 0; j < G.numberVex; j++)
			G.arc[i][j] = INFINIT;            //邻接矩阵初始化
	}
	for (k = 0; k < G.numberEdge; k++){
		printf("请输入边(vi,vj)的下标i和下标j，及其权值w\n");
		//scanf("%d,%d,%d",&i,&j,&w);
		std::cin >> i >> j >> w;
		G.arc[i][j] = w;
		G.arc[j][i] = G.arc[i][j];         // 无向图为对称矩阵
	}
}
//邻接表的深度优先遍历
Boolean visited[MAXVEX];            //访问标志
void DFS(Mgraph &G, int i){
	int j;
	visited[i] = true;             //第i个顶点已被访问
	printf("%c", G.vexs[i]);       //打印出该顶点
	for (j = 0; j < G.numberVex; j++){
		if (G.arc[i][j] != INFINIT && !visited[j])         //若第j个顶点和第i个顶点存在边，则遍历该顶点
			DFS(G, j);
	}
}
void DFSTraverse(Mgraph &G){
	int i;
	for (i = 0; i < G.numberVex; i++)
		visited[i] = false;           //初始化访问标志
	for (i = 0; i < G.numberVex; i++){
		if (!visited[i])
			DFS(G,i);
	}
}
//邻接表的广度优先遍历
void BFSTraverse(Mgraph &G){
	int i, j; 
	int n = MAXVEX;  //size of queue
	LinkQueue Q;
	Init_LinkQueue(Q,n);
	for (i = 0; i < G.numberVex; i++)
		visited[i] = false;
	for (i = 0; i < G.numberVex; i++){
		if (!visited[i]){
			visited[i] = true;
			printf("%c", G.vexs[i]);
			EnQueue(Q, G.vexs[i]);
		}
		while (!IsEmpty(Q)){
			DeQueue(Q, i);
			for (j = 0; j < G.numberVex; j++){
				if (G.arc[i][j] != INFINIT && !visited[j]){
					visited[j] = true;
					printf("%c", G.vexs[j]);
					EnQueue(Q, j);
				}
			}
		}
	}
}
int main(){
	Mgraph G;
	CreateMgraph(G);
	DFSTraverse(G);
	printf("\n");
	BFSTraverse(G);
	return 0;
}
