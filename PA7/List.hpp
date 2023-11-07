#pragma once

#include "Node.hpp"

template <class T>
class List
{
public:
	List();

	void insertFront(const T& data);
	bool isEmpty();
	void printList();

private:
	ListNode<T>* createNode(const T &data);


	ListNode<T>* mpHead;
};

template<class T>
List<T>::List()
{
	mpHead = nullptr;
}

template<class T>
void List<T>::insertFront(const T& data)
{
	ListNode<T>* pMem = createNode(data);
	if (pMem != nullptr)
	{
		if (isEmpty())
		{
			this->mpHead = pMem;
		}
		else
		{
			pMem->setpNext(mpHead);
			mpHead = pMem;
		}
	}
	else
	{
		std::cout << "Error, memory failed to allocate!\n";
	}
	
}

template<class T>
bool List<T>::isEmpty()
{
	bool success = false;
	if (this->mpHead == nullptr)
	{
		success = true;
	}
	return success;
}

template<class T>
void List<T>::printList()
{
	if (!isEmpty())
	{
		ListNode<T>* pCur = this->mpHead;
		while (pCur != nullptr)
		{
			std::cout << *pCur << " : ";
			pCur = pCur->getpNext();
		}
	}
	else
	{
		std::cout << "List Empty!\n";
	}
}

template<class T>
ListNode<T>* List<T>::createNode(const T& data)
{
	ListNode<T>* pMem = new ListNode<T>(data);
	return pMem;
}
