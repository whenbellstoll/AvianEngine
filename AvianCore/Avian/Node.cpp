#include "Node.h"

node::node()
{
    next = nullptr;
    previous = nullptr;
    local = this;
}

node::~node()
{
    //previous->next = next;
    //next->previous = previous;
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
    node copyNode = node();
    copyNode.previous = previous;
    copyNode.next = next;

    return &copyNode;
}