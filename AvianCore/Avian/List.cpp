#include "List.h"

List::List()
{
	head = nullptr;
	head->next = nullptr;
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
	del();
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
	sentinel->next = n;
	sentinel = sentinel->next;
	count++;
}

void List::add(node* i, node* n)
{
	for (node* no = head; no != nullptr; no = no->next)
	{
		if (no == i)
		{
			no->next->previous = n;
			n->next = no->next;
			n->previous = no;
			no->next = n;
			count++;
			break;
		}
	}
}

void List::del()
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
	count = 0;
}

void List::del(node* n)
{
	for (node* no = head; no != nullptr; no = no->next)
	{
		if (no == n)
		{
			no->next->previous = no->previous;
			no->previous->next = no->next;
			delete n;
			count--;
			break;
		}
	}
}

void List::remove(node* n )
{
	for (node* no = head; no != nullptr; no = no->next)
	{
		if (no == n)
		{
			no->next->previous = no->previous;
			no->previous->next = no->next;
			count--;
			break;
		}
	}
}

unsigned int List::Count()
{
	return count;
}

void List::Save(File&)
{
}

void List::Load(File&)
{
}
