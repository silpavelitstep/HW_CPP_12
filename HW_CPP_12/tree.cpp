#include "tree.h"
#include <iostream>
#pragma warning(disable:4996)
#pragma warning(disable:4703)
using namespace std;
Tree::Tree() {
	root = 0;
}
Tree::~Tree() {
	del();
}
void Tree::print(Elem* node) {
	if (node) {
		print(node->left);
		cout << node->name;
		cout << node->match;
		cout << node->opponent;
		cout << endl;
		print(node->right);
	}
}
Tree::Elem* Tree::search(Elem* node, char* k) {
	while (node && strcmp(k, node->name)) {
		if (strcmp(k, node->name) < 0)
			node = node->left;
		else
			node = node->right;
	}
	return node;//=0 if elem don't found

}
Tree::Elem* Tree::min(Elem* node) {
	if (node)
		while (node->left)
			node = node->left;
	return node;
}
Tree::Elem* Tree::max(Elem* node) {
	if (node)
		while (node->right)
			node = node->right;
	return node;
}
Tree::Elem* Tree::next(Elem* node) {
	Elem* y = 0;
	if (node) {
		if (node->right)
			return min(node->right);
		y = node->parent;
		while (y && node == y->right) {//end if up from left
			node = y;
			y = y->parent;//y==0 if next elem is ebsent
		}
	}
	return y;
}
Tree::Elem* Tree::prev(Elem* node) {
	Elem* y = 0;
	if (node) {
		if (node->left)
			return max(node->left);
		y = node->parent;
		while (y && node == y->left) {
			node = y;
			y = y->parent;
		}
	}
	return y;
}
Tree::Elem* Tree::getRoot() {
	return root;
}
void Tree::insert(Elem* z) {
	z->left = 0;
	z->right = 0;
	Elem* y = 0;
	Elem* node = root;
	while (node) {//find free space
		y = node;
		if (strcmp(z->name, node->name) < 0)
			node = node->left;
		else
			node = node->right;
	}
	z->parent = y;
	if (y == 0)//empty tree
		root = z;
	else if (strcmp(z->name, y->name) < 0)
		y->left = z;
	else
		y->right = z;
}
void Tree::del(Elem* z) {
	Elem* node, * y;
	if (z) {
		if (z->left == 0 || z->right == 0)
			y = z;//only one child
		else
			y = next(z);//two children, max children instead z 
	}
	if (y->left)
		node = y->left;
	else
		node = y->right;
	if (node)
		node->parent = y->parent;
	if (y->parent == 0)
		root = node;
	else if (y == y->parent->left)//if went from left down
		y->parent->left = node;
	if (y != z) {
		strcpy(z->name, y->name);
		strcpy(z->opponent, y->opponent);
		strcpy(z->match, y->match);
		z->oppPoints = y->oppPoints;
		z->ownerPoints = y->ownerPoints;
		delete y;
	}
	else {
		while (root)
			del(root);
	}


}




