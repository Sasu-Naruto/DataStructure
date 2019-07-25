#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ERROR 0
#define OK 1
typedef int Status;
typedef int elemtype;
typedef struct QueueNode{      //定义结点结构
	elemtype data;
	struct QueueNode* next;
}QueueNode, *Qnode;
typedef struct{
	Qnode front, rear;
}LinkQueue;
Status Init_LinkQueue(LinkQueue &L, int n){
	L.front = (Qnode)malloc(sizeof(QueueNode));  //创建头结点为front
	L.front->data = n;
	L.front->next = NULL;
	L.rear = L.front;
	return OK;
}
Status EnQueue(LinkQueue &L, elemtype e){
	Qnode p = (Qnode)malloc(sizeof(QueueNode));
	if (!p)
		return ERROR;
	p->data = e;
	p->next = NULL;
	L.rear->next = p;
	L.rear = p;
	return OK;
}
Status DeQueue(LinkQueue &L, elemtype &e){
	e = L.front->data;
	if (L.front == L.rear)
		return ERROR;
	Qnode p = L.front->next;
	L.front->next = p->next;
	if (p == L.rear)
		L.rear = L.front;  //若队尾被删除，则rear指针指向头结点
	free(p);
	return OK;
}
bool IsEmpty(LinkQueue &Q){
	if (Q.front == Q.rear)
		return true;
	return false;
}

#endif
