#pragma once

#include "Node.hpp"

template <class T>
class List
{
public:
	List();
	~List();

	void insertFront(const T& data);
	bool isEmpty();
	void printList();
	void destroyList();

	ListNode<T>* getpHead();

private:
	ListNode<T>* createNode(const T &data);
	ListNode<T>* mpHead;
};

/// <summary>
/// default constructor for List
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
template<class T>
List<T>::List()
{
	mpHead = nullptr;
}

/// <summary>
/// destructor for List, calls memberfunction destroyList
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
template<class T>
List<T>::~List()
{
	destroyList();
}

/// <summary>
/// Insert at front function for List
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <param name="data">data entry to be inserted</param>
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

/// <summary>
/// Member function that checks if the list is empty
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <returns>true if list is empty</returns>
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

/// <summary>
/// Prints the data of every node in the list, each data entry is placed on its own line.
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
template<class T>
void List<T>::printList()
{
	if (!isEmpty())
	{
		ListNode<T>* pCur = this->mpHead;
		while (pCur != nullptr)
		{
			std::cout << *pCur << std::endl;
			pCur = pCur->getpNext();
		}
	}
	else
	{
		std::cout << "List Empty!\n";
	}
}

/// <summary>
/// deallocates every node in the list
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
template<class T>
void List<T>::destroyList()
{
	if (mpHead != nullptr)
	{
		ListNode<T>* pCur = mpHead; 
		ListNode<T>* pPrev = nullptr;
		while (pCur != nullptr)
		{
			pPrev = pCur;
			pCur = pCur->getpNext();
			delete pPrev;
		}
	}
	else
	{
		std::cout << "List Does Not exist.\n";
	}

}

/// <summary>
/// getter for pHead
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <returns>pointer to the head of the list</returns>
template<class T>
ListNode<T>* List<T>::getpHead()
{
	return mpHead;
}

/// <summary>
/// Allocates memory for a List Node
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <param name="data">data to be stored in node</param>
/// <returns>pointer to the newly allocated node</returns>
template<class T>
ListNode<T>* List<T>::createNode(const T& data)
{
	ListNode<T>* pMem = new ListNode<T>(data);
	return pMem;
}

