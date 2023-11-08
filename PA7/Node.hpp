#pragma once
#include <iostream>

template <class T>
class ListNode
{
public:
	ListNode(const T &data);
	ListNode(const ListNode<T>& copy);
	~ListNode();

	T getData() const;
	ListNode<T>* getpNext()const;

	void setData(const T& newData1);
	void setpNext(ListNode<T>* newpNext);
	
	ListNode<T> operator= (ListNode<T> rhs);

	void printNode();

private:
	
	T mData;
	ListNode<T>* mpNext;
};

template<class T>
ListNode<T>::ListNode(const T &data)
{
	this->mData = data;
	this->mpNext = nullptr;
}

template<class T>
ListNode<T>::ListNode(const ListNode<T>& copy)
{
	this->mData = copy.mData;
	this->mpNext = copy.mpNext;
}

template<class T>
ListNode<T>::~ListNode()
{
}

template<class T>
T ListNode<T>::getData() const
{
	return this->mData;
}


template<class T>
ListNode<T>* ListNode<T>::getpNext() const
{
	return this->mpNext;
}

template<class T>
void ListNode<T>::setData(const T& newData)
{
	this->mData = newData;
}


template<class T>
void ListNode<T>::setpNext(ListNode<T>* newpNext)
{
	this->mpNext = newpNext;
}

template<class T>
ListNode<T> ListNode<T>::operator=(ListNode<T> rhs)
{
	this->setData(rhs.getData());
	this->setpNext(rhs.getpNext());
}

template<class T>
void ListNode<T>::printNode()
{
	std::cout << mData << std::endl;
}

template<class T>
std::ostream& operator<< (std::ostream& lhs, ListNode<T>& rhs)
{
	T temp = rhs.getData();
	lhs << temp;
	return lhs;
}
template<class T>
std::istream& operator>> (std::istream& lhs, ListNode<T>& rhs)
{
	T buffer;
	lhs >> buffer;
	rhs.setData(buffer);
	return lhs;
}