#pragma once

#include "Node.h"

class NodeHelper
{
public:
	NodeHelper();

	template<typename T>
	void AppendToBack(Node<T>& head, T element);

	template<typename T>
	int GetListSize(Node<T> head);

	~NodeHelper();
};

NodeHelper::NodeHelper()
{
}


NodeHelper::~NodeHelper()
{
}


template<typename T>
void NodeHelper::AppendToBack(Node<T>& head, T element)
{
	auto currNode = &head;
	auto back = new Node<T>(element);

	while (currNode->NextNode != NULL)
	{
		currNode = currNode->NextNode;
	}

	currNode->NextNode = back;
}

template<typename T>
int NodeHelper::GetListSize(Node<T> head)
{
	auto counter =  1;

	auto currNode = &head;

	while (currNode->NextNode != NULL)
	{
		currNode = currNode->NextNode;
		++counter;
	}

	return counter;
}