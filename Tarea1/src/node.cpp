// Class automatically generated by Dev-C++ New Class wizard

#include "node.h" // class's header file

// class constructor
node::node(kangaroo k): _data(k),_next(NULL)
{
	// insert your code here
}

// class destructor
node::~node()
{
	
	// insert your code here
}

kangaroo node::getData()
{
	return this->_data;
}

node* node::getNext()
{
	return _next;
}


void node::setNext(node *n)
{
	_next=n;
}