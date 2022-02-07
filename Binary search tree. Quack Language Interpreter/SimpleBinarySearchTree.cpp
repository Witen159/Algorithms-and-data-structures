#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct element {
	int key;
	element* left;
	element* right;
};

vector <element> tree(100);

bool exists(element* x, int k) {
	if (x == NULL) {
		return false;
	}

	if (k == x->key) {
		return true;
	}

	if(k < x->key) {
		return exists(x->left, k);
	}
	else {
		return exists(x->right, k);
	}
}

element* insert(element *&x, int a) {
	if (x == NULL) {
		x = new element;
		x->key = a;
		x->left = x->right = NULL;
	}
	else if (x->key > a)
		insert(x->left, a);
	else if (x->key < a)
		insert(x->right, a);

	return x;
}

element* next(element *&root, int x) {
	element* current = root;
	element* successor = NULL;

	while (current != NULL) {
		if (current->key > x) {
			successor = current;
			current = current->left;
		}
		else
			current = current->right;
	}

	return successor;
}

element* prev(element *&root, int x) {
	element* current = root;
	element* successor = NULL;

	while (current != NULL) {
		if (current->key < x) {
			successor = current;
			current = current->right;
		}
		else
			current = current->left;
	}

	return successor;
}

element* minimum(element *&x) {
	if (x->left == NULL) {
		return x;
	}

	return minimum(x->left);
}

element* remove (element *&root, int a) {
	if (root == NULL)
		return root;

	if (a < root->key)
		root->left = remove(root->left, a);
	else if (a > root->key)
		root->right = remove(root->right, a);
	else if (root->left != NULL && root->right != NULL) {
		root->key = minimum(root->right)->key;
		root->right = remove(root->right, root->key);
	}
	else {
		if (root->left != NULL)
			root = root->left;
		else
			root = root->right;
	}

	return root;
}


int main() {
	
	ifstream fin("bstsimple.in");
	ofstream fout("bstsimple.out");
	
	element* tree = NULL;
	string command;

	while (fin >> command){
		int value;
		fin >> value;

		if (command == "insert") {
			insert(tree, value);
		}

		if (command == "exists") {
			if (exists(tree, value))
				fout << "true\n";
			else
				fout << "false\n";
		}

		if (command == "next") {
			element* temp = next(tree, value);
			if (temp == NULL)
				fout << "none\n";
			else
				fout << temp->key << "\n";
		}

		if (command == "prev") {
			element* temp = prev(tree, value);
			if (temp == NULL)
				fout << "none\n";
			else
				fout << temp->key << "\n";
		}

		if (command == "delete")
			remove(tree, value);
	}

	fin.close();
	fout.close();

	return 0;
}