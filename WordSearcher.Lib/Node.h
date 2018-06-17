#pragma once
template <typename T>
class Node
{
public:
	T Item;
	Node<T> *NextNode;
	Node<T>(T item);
	~Node();
};

template <typename T>
Node<T>::Node(T item) :
	Item(item)
{
	this->NextNode = nullptr;
};

template <typename T>
Node<T>::~Node()
{

};