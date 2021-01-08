#include<iostream>
#include<stack>
using namespace std;
/*             1
             /   \
            2     9
          /   \    \
         4     5    10

*/
struct Node {
	int data;
	struct Node*pLeft;
	struct Node*pRight;
	Node(int x) {
		this->data = x;
		this->pLeft = this->pRight = NULL;
	}
};
// left ->root ->right

void Inoder(struct Node *root) {
	stack<Node*> s;
	struct Node*current = root;

	while (current != NULL || !s.empty()) {
		//the cac phan tu nhanh trai vao Stack 1 2 4
		while (current != NULL) {
			s.push(current);
			current = current->pLeft;
		}
		
		/*mistake 1:

		cout << s.top() << " ";
		s.pop();

		ko dung dc vi hien tai current dang o NULL(line 30)

		*/

		//in phan tu top;
		current = s.top();
		s.pop();
		cout << current->data << " ";
		
		//chung ta da truy cap vao cay con ben trai, now truy cap vao cay con ben pha
		current = current->pRight;
	}//end when current ==NULL
	// then continue loof because s.empty()==false
}

int main() {
	struct Node*root = new Node(1);
	root->pLeft = new Node(2);
	root->pLeft->pLeft= new Node(4);
	root->pLeft->pRight= new Node(5);
	root->pRight= new Node(9);
	root->pRight->pLeft= new Node(10);

	Inoder(root);
	system("pause");
	return 0;
}
