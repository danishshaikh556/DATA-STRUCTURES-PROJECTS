#include<iostream>
#include<stdlib.h>
#include<string>
#include "rbtree.h"
using namespace std;

Node::Node()
{
	left=NULL;
	right=NULL;
	parent=NULL;
	data.first="";
	data.second=1;
	//data.second=NULL;
	color=0;
	cnt=1;		
	
}

int Node::getColor()
{
	return color; 
}
void Node::setLeft(Node* ptrLeft)
{
	left=ptrLeft;
}
void Node::setRight(Node* ptrRight){
	right=ptrRight;
}
void Node::setParent(Node* ptrParent){
	parent=ptrParent;
}
void Node::setColor(int chchar){
	color=chchar;		
}
void Node::setData(pair<string,int> value)
{
	
	data.first=value.first;
	data.second=value.second;
	
}

void Node::setData(pair<string,int> &value,int &i)
{
	data.first=value.first;
	data.second=i;
}
Node* Node::getLeft()
{
	return left;
}
Node* Node::getRight()
{return right;}
Node* Node::getParent()
{return parent;}	

Node* Tree::getRoot()
{
	return root;
}
Tree :: Tree()
{
	//root=new Node();
	Nil=new Node();
	root=Nil;
}


void Tree::insert(pair<string,int> value)
{
	Tree* t;	
	Node* z;
	Node* y;
	Node* x;
	Node* n;
	
		z=new Node();
		z->setData(value);
		z->setColor(1);
		
		y=Nil;
		//cout<<"Y color:"<<y->getColor()<<endl;
		x=root;
		while(x!=Nil)
		{
			y=x;
			
	
		if(z->data.first == x->data.first)	
			{
				
				x->data.second++;
				return;
			}
		 if(z->data.first < x->data.first)
			{
				x=x->getLeft();	
			}
			else 
			 x=x->getRight();
			
			
		}		
		
		z->setParent(y);
		//cout<<"Y ----color:"<<y->getColor()<<endl;
		if(y==Nil)
		{
			root=z;
		}
			
			else if(z->data.first<y->data.first)
			{
				y->setLeft(z);
				 
			}
		else y->setRight(z);
	
	z->setLeft(Nil);
	z->setRight(Nil);
	z->setColor(1);
	fixup(z);
	
	
	
}	

void Tree::leftRotate(Node* x)
{
	Node *y;
	y=x->right;
	x->right=y->left;
	//	x->setRight(y->getLeft());
	if(y->left!=Nil)
	{
		y->left->parent=x;
	}
	//y->etParent()=x->getParent();
	y->parent=x->parent; 
	if(x->parent==Nil)
	{
		root=y;		
	}
	
	else if(x==x->parent->left)
		{
		x->parent->left=y;
			//x->setParent(y->getLeft());
		}

		else x->parent->right=y;
		//x->setParent(y->getRight());

		y->left=x;
		x->parent=y;
}

void Tree::rightRotate(Node* x)
{
	Node *y;
	y=x->left;
	x->left=y->right;
	if(y->right!=Nil)
	{
		y->right->parent=x;
	}
	y->parent=x->parent;
	if(x->getParent()==Nil)
	{
		root=y;		
	}
	else if(x==x->parent->right)
	{
		x->parent->right=y;
	}
	else x->parent->left=y;
	y->right=x;
	x->parent=y;
}
	



void Tree::fixup(Node* z)
{
	Node *y;
	
	while ( z->parent->color == 1 )
	    {
		   if ( z->parent == z->parent->parent->left )
        	    {
            		y = z->parent->parent->right;
		
            		if ( y->color == 1 )
            		{
                		z->parent->color=0;
                		y->color=0;
                		z->parent->parent->color=1;
                		z = z->parent->parent;
            		}

            		else 
			{
				if ( z == z->parent->right )
                		{
                    		z = z->parent;
                    		leftRotate( z );
                		}
                
                	z->parent->color=0;
                	z->parent->parent->color=1;
			rightRotate( z->parent->parent);
			}
		   }
		else

		        {
           	 		y = z->parent->parent->left;
            
           		 if ( y->color == 1 )
           		 {
           		     z->parent->color=0;
           		     y->color=0;
           		     z->parent->parent->color=1;
           		     z = z->parent->parent;
           		 }
            		else
            		{
                		if ( z == z->parent->left )
                		{
                    			z = z->parent;
                    			rightRotate( z );
                		}
                		z->parent->color=0;
                		z->parent->parent->color=1;
                		leftRotate( z->parent->parent);
            		}
        		
			}
    }
    
    root->setColor(0);
    
    //y = NULL;
//cout << z->data.first<<" " <<z->data.second<<endl;
//cout<<"cvbnm"<<endl;
    
}
void Tree::inorder(Node* currentNode)
{
	if(currentNode!=Nil)
	 {
	       inorder(currentNode->getLeft());
	       cout << currentNode->data.first<<" " <<currentNode->data.second<<endl;
	      inorder(currentNode->getRight());
	 }

	
}

int Tree:: height(Node* currentNode)
{
	int h_cnt=0;
	while(currentNode!=Nil)
		{
			if(currentNode->color==0)
			h_cnt++;
			currentNode=currentNode->left;	
		}
	currentNode=root;	
	cout<<"left height: "<<h_cnt<<endl;
	h_cnt=0;		
	while(currentNode!=Nil)
	{
			if(currentNode->color==0)
			h_cnt++;
			currentNode=currentNode->right;	
	}
	cout<<"right height: "<<h_cnt<<endl;	
	
}


