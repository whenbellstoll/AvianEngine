#include "List.h"

List::List()
{
	head = nullptr;
	sentinel = head;
	count = 0;
}

List::List(const List& l)
{
	head = l.head;
	sentinel = l.sentinel;
	count = l.count;
}

List& List::operator=(const List& l)
{
	head = l.head;
	sentinel = l.sentinel;
	count = l.count;
	return *this;
}

List::~List()
{
	node* current = head;
	node* next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}

	// delete head 
	delete head;
}

node* List::Clone()
{
	return new List(*this);
}

node* List::Head()
{
	return head;
}

node* List::Sentinel()
{
	return sentinel;
}

bool List::EOList()
{
	return false;
}

void List::add(node* n)
{
}

void List::add(node* i, node* n)
{
}

void List::del()
{
}

void List::del(node* n)
{
}

void List::remove(node* n )
{
}

unsigned int List::Count()
{
	return 0;
}

void List::Save(File&)
{
}

void List::Load(File&)
{
}
