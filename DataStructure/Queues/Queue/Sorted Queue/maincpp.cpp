//Sorted increase queue
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

//Method 1:easy implement

/*
B1:we can simply move all items in queue to array,then sorted array
B2: Move array elements back to queue
*/


//Method 2:
//tim vi tri co gia tri  min
int MinIndex(queue<int>p, int chiso) {
	
	int min = p.front();//khoi tao gia tri Min ban dau
	int min_index = -1;//khoi tao vi tri cua gia tri Min ban dau
	int n = p.size();

	for (int i = 0; i < n; i++) {
		int k = p.front();
		p.pop();
		if (k <= min && i <= chiso) {//đk tim Min, i<=chiso vi
			/* Ban dau thi ta tim dc Min cua queue, sau do Move gia tri nay xuong rear
			 sau do chi so bi giam di 1(o day la cach bo qua cac gia tri co i>chiso cua queue de tim 
			 1 gia tri Min moi so voi cac gia tri phia truoc chi so)
			*/
			min = k;
			min_index = i;
		}
		p.push(k);
	}
	return min_index;
}

//chuyen gia tri tai vi tri co chi so=MinIndex xuong rear

void MoveMinToRear(queue<int>&p, int MinIndex) {//can truyen tham chieu den p muc dich de thay
	                                            //doi thu tu trong Queue
	int min;
	int n = p.size();
	for (int i = 0; i < n; i++) {
		int k = p.front();
		p.pop();
		if (i != MinIndex)
			p.push(k);
		else//neu i=MinIndex ko push no vao queue nham muc dich de sau khi thuc hien xong 
			//vong lap thi push no vao sau gia tri Min
			//vd: 31 11 15 4
			// MinIndex=1
			//thuc hien dong lenh.....
			//result: 31 15 4 11
			min = k;
	}
	p.push(min);
}

void SortQueue(queue<int>&p,int n){
	for (int i = 1; i <= n; i++) {
		int k = MinIndex(p, n - i);
		MoveMinToRear(p, k);
	}
}
int main() {
	queue<int>p;
	p.push(10);
	p.push(2);
	p.push(8);
	p.push(25);
	
	int n = p.size();
	SortQueue(p, n);

	while (!p.empty()){
		
		cout << p.front() << " ";
		p.pop();
	}

	system("pause");
	return 0;
}

 