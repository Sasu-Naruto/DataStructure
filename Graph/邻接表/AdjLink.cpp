#pragma warning(disable:4996)
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#define MAXVEX 100
typedef char VexType;
typedef int EdgeType;
typedef int Boolean;
typedef struct EdgeNode{  //边结点
	int adjvex;           //邻域顶点,即存储某顶点的邻接点下标
	EdgeNode *next;       //指向对应顶点下一个结点的指针
}EdgeNode,*Enode;
typedef struct {   //顶点表
	VexType vex; //存储顶点信息
	Enode firstege;//指向边结点
}VextexNode,AdjList[MAXVEX];
typedef struct{
	AdjList adjlist;
	int numvex, numedge;
}GraphList;
void creatGraph(GraphList &G){
	int i, j, k;
	int num_vex = 0, num_edge = 0;
	char vex;
	//建立顶点表
	printf("请输入图的顶点数及边数\n");
	std::cin >> num_vex >> num_edge;
	G.numedge = num_edge; G.numvex = num_vex;
	for (i = 0; i < G.numvex; i++){
		printf("请输入顶点\n");
		std::cin >> vex;
		G.adjlist[i].vex = vex;
		G.adjlist[i].firstege = NULL;  //先将边表置为空
	}
	//建立边表
	for (k = 0; k < G.numedge; k++){
		printf("请输入(vi,vj)的下标i与j\n");
		std::cin >> i >> j;
		Enode e = (Enode)malloc(sizeof(EdgeNode));
	    //firstege结点直接指向邻接顶点，采用头结点创建链表法
		e->adjvex = j;
		e->next = G.adjlist[i].firstege;
		G.adjlist[i].firstege = e;
		//无向图对称
		e = (Enode)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G.adjlist[j].firstege;
		G.adjlist[j].firstege = e;
	}
}
//深度优先遍历
Boolean visited[MAXVEX];
void DFS(GraphList &G,int i){
	Enode p = G.adjlist[i].firstege;
	visited[i] = true;
	printf("%c", G.adjlist[i].vex);
	while (p){
		if (!visited[p->adjvex])   //筛选出没有被遍历过的
		    DFS(G, p->adjvex);
		p = p->next;
	}
}
void DFSTraverse(GraphList &G){
	for (int i = 0; i < G.numvex; i++)
		visited[i] = false;        //初始化标记矩阵
	for (int i = 0; i < G.numvex; i++){
		if (!visited[i])
		DFS(G,i);
	}
}
//广度优先遍历
void BFSTraverse(GraphList &G){
	int i = 0,n = MAXVEX; LinkQueue Q;
	Init_LinkQueue(Q,n);
	for (i; i < G.numvex; i++)
		visited[i] = false;
	for (i = 0; i < G.numvex; i++){
		if (!visited[i]){
			visited[i] = true;
			printf("%c", G.adjlist[i].vex);
			EnQueue(Q, i);
			while (IsEmpty(Q)){
				DeQueue(Q, i);
				Enode p = G.adjlist[i].firstege;
				if (!visited[p->adjvex] && !p){
					visited[p->adjvex] = true;
					printf("%c", p->adjvex);
					EnQueue(Q, p->adjvex);
					p = p->next;
				}
			}
		}
	}
}
int main(){
	GraphList G;
	creatGraph(G);
	DFSTraverse(G);
	printf("\n");
	BFSTraverse(G);
	return 0;
}
