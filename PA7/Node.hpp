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

/// <summary>
/// default constructor for ListNode template
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <param name="data">data to be stored in node</param>
template<class T>
ListNode<T>::ListNode(const T &data)
{
	this->mData = data;
	this->mpNext = nullptr;
}

/// <summary>
/// Copy constructor for ListNode
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <param name="copy">ListNode to be copies</param>
template<class T>
ListNode<T>::ListNode(const ListNode<T>& copy)
{
	this->mData = copy.mData;
	this->mpNext = copy.mpNext;
}

/// <summary>
/// Destructor for ListNode - empty
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
ListNode<T>::~ListNode()
{
}

/// <summary>
/// getter for mData
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <returns>returns data of type T stored in node</returns>
template<class T>
T ListNode<T>::getData() const
{
	return this->mData;
}

/// <summary>
/// getter for pNext
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <returns>pointer to next node</returns>
template<class T>
ListNode<T>* ListNode<T>::getpNext() const
{
	return this->mpNext;
}

/// <summary>
/// setter for data
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <param name="newData">new data entry of type T</param>
template<class T>
void ListNode<T>::setData(const T& newData)
{
	this->mData = newData;
}

/// <summary>
/// setter for pNext
/// </summary>
/// <typeparam name="T"><data entry of variable type T/typeparam>
/// <param name="newpNext">pointer to the next node</param>
template<class T>
void ListNode<T>::setpNext(ListNode<T>* newpNext)
{
	this->mpNext = newpNext;
}

/// <summary>
/// overloaded assignment operator for list node
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <param name="rhs">ListNode on rhs of operator</param>
/// <returns>dereferenced this pointer</returns>
template<class T>
ListNode<T> ListNode<T>::operator=(ListNode<T> rhs)
{
	this->setData(rhs.getData());
	this->setpNext(rhs.getpNext());
	return *this;
}

/// <summary>
/// member function that prints the data stored in the node
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
template<class T>
void ListNode<T>::printNode()
{
	std::cout << mData << std::endl;
}

/// <summary>
/// overloaded stream insertion operator
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <param name="lhs">ostream to be inserted into</param>
/// <param name="rhs">ListNode to be inserted</param>
/// <returns>original ostream</returns>
template<class T>
std::ostream& operator<< (std::ostream& lhs, ListNode<T>& rhs)
{
	T temp = rhs.getData();
	lhs << temp;
	return lhs;
}

/// <summary>
/// overloaded stream extraction operator
/// </summary>
/// <typeparam name="T">data entry of variable type T</typeparam>
/// <param name="lhs">istream to be extracted from</param>
/// <param name="rhs">ListNode to be extraced to</param>
/// <returns>original istream</returns>
template<class T>
std::istream& operator>> (std::istream& lhs, ListNode<T>& rhs)
{
	T buffer;
	lhs >> buffer;
	rhs.setData(buffer);
	return lhs;
}