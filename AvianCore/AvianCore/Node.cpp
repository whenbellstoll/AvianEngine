#include "Node.h"

node::node()
{
    local = &this;
}

node::~node()
{
    previous->next = next;
    next->previous = previous;
}

node* node::Next()
{
    return next;
}

node* node::Previous()
{
    return previous;
}

bool node::EOList()
{
    return(next == nullptr);
}

node* node::Clone()
{
    node copyNode = this;
    copyNode->previous = previous;
    copyNode->next = next;

    node * newNode = &copyNode;
}