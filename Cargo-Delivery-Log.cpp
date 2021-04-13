#include <iostream>
#include <string>

using namespace std;

struct BtsNode {
	int data;
	BtsNode* left;
	BtsNode* right;
};

BtsNode* GetnewNode (int data)
{
	BtsNode* newNode = new BtsNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BtsNode* insert(BtsNode* root, int data)
{
	if(root == NULL)
	{
		root = GetnewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

void display (BtsNode* root)
{
	if(root !=NULL)
	{
		display(root->left);
		cout << root->data << " ";
		display(root->right);
	}
//	else
//		cout << "empty!" << endl;
}

bool serach(BtsNode* root, int data)
{
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(data <= root->data) return serach(root->left,data);
	else return serach(root->right,data);
}

int main()
{	
	BtsNode* root = NULL;
	
	while(true)
	{
		string oparation;
		cin >> oparation;
		
		if(oparation == "I")
		{
//			cout << "Hello I" <<endl;
			int newKey;
			cin >> newKey;
			
			root = insert(root,newKey);
		}
		else if (oparation == "F")
		{
//			cout << "Hello F" << endl;
			int key;
			cin >> key;
			
			if(serach(root,key) == true) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else if(oparation == "D")
		{
//			cout << "Hello D" <<endl;
			display(root);
			cout << endl;
		}
		else if(oparation == "X")
		{
//			cout << "Hello X" <<endl;
			return 0;
		}
		else{
			cout << "unkhnow" << endl;
		}
	}
	
	return 0;
}
