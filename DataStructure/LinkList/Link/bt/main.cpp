#include<iostream>
#include<fstream>

using namespace std;

struct node {
	int data; //data
	struct node *pNext; //khai bao con tro tro den vi tri ke tiep(tro sang ben phai)
};
typedef struct node Node;

struct list {
	Node *pHead;
};