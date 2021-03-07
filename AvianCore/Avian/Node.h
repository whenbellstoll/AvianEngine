#ifndef _NODE_H_
#define _NODE_H_
#include "File.h"
class node
{
protected:

	node *next;
	node *previous;

public:
	node * local;
	node();
	virtual ~node();
	node* Next();
	node* Previous();
	bool EOList();
	virtual node * Clone();
	virtual void Load(File &){}
	virtual void Save(File &){}
	virtual const char * ClassName(){return "node";}
	friend class List;
	friend class StateMachine;
};


#endif