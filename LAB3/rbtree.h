#ifndef _MYHEADER2_H_
#define _MYHEADER2_H_
#include<iostream>
#include<string>

using namespace std;

class Node
{		
	public:
		Node();
		int color;
		Node* left;
		Node* right;
		Node* parent;
		
		Node* getLeft();
		Node* getRight();
		Node* getParent();
		void setLeft(Node*);
		void setRight(Node*);
		void setParent(Node*);
		void setColor(int);
		int getColor();
		void setData(pair<string,int>);
		void setData(pair<string,int>&,int&);	
		pair<string,int> data;
		int cnt;
};

class Tree
{
	private:
		Node* root;
		Node* Nil;
		
	public:
		Tree();
		void insert(pair<string,int>);
		void leftRotate(Node*);
		void rightRotate(Node*);
		void fixup(Node*);
		void inorder(Node*);
		Node* getRoot();
		int height(Node*);
		

};
#endif
