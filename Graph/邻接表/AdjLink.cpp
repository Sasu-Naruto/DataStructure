#pragma warning(disable:4996)
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#define MAXVEX 100         //最大顶点数
#define INFINIT 65535

int main(){
	Mgraph G;
	CreateMgraph(G);
	DFSTraverse(G);
	printf("\n");
	BFSTraverse(G);
	return 0;
}
