#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Node{
public:
	int val;
	//almacena un vector de punteros a los nodos hijos
	vector<Node*> children;

	Node() {}
	Node(int _val){
		val=_val;
	}
	Node(int _val, vector<Node*> _children){
		val=_val;
		children=_children;
	}
};

class SolutionSixteen{
public:
	int maxDepth(Node* root){
		if(root==NULL) return 0;
		int n=root->children.size();
		if(n==0) return 1;
		vector<int> arr(n);
		for(int i=0; i<n; ++i){
			arr[i]=maxDepth(root->children[i]);
		}
		int depth=1+*max_element(arr.begin(), arr.end());
		return depth;
	}
};

TreeNode* vectorToTree(vector<int> numbers, int i, int n){
	if(i>=n) return nullptr;
	TreeNode* root=new TreeNode(numbers[i]);
	root->left=vectorToTree(numbers, 2*i+1, n);
	root->right=vectorToTree(numbers, 2*i+2, n);
	return root;
}

int main(){

	//crear nodos en el formato extraño
	//root={1,null,3,2,4,null,5,6}
	Node* node5=new Node(5);
	Node* node6=new Node(6);
	Node* node3=new Node(3,{node5,node6});
	Node* node2=new Node(2);
	Node* node4=new Node(4);

	Node* root=new Node(1,{node3,node2,node4});
	
	SolutionSixteen sol;
	int depth=sol.maxDepth(root);
	cout<<"la profundidad maxima es: "<<depth<<endl;