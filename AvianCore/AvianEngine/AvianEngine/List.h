#ifndef _LIST_H_
#define _LIST_H_

class   List:public node
{
protected:

	node *head;
	node *sentinel;
	unsigned int count;

public:

	List();
	List(const List &);
	List & operator=(const List &);
	~List();
	node* Clone();
	node* Head();
	node* Sentinel();
	bool EOList();
	void add(node *);
	void add(node *, node *);
	void del();
	void del(node *);
	void remove(node *);
	unsigned int Count();
	void Save(File &);
	void Load(File &);

};
		

#endif

