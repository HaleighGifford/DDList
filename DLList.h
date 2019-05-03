//****************************************************************************************************

#ifndef DLLIST_H
#define DLLIST_H
#include "Node.h"

//****************************************************************************************************

template <typename TYPE>
class DLList
{
	private:
			Node<TYPE> * front;
			Node<TYPE> * rear;
	public:
			DLList();		
			~DLList();		

			bool insert(const TYPE & dataIn);		
			bool remove(TYPE & dataOut);			
			bool retrieve(TYPE & dataOut) const;

			bool viewFront(TYPE & dataOut) const;	
			bool viewRear(TYPE & dataOut) const;	

			bool display() const;						
			bool displayReverse() const;
			int getNumValues() const;				

			bool isEmpty() const;					
			bool isFull() const;					
};

//****************************************************************************************************

template <typename TYPE>
DLList<TYPE> ::DLList()
{
	front = nullptr;
	rear = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
DLList<TYPE> ::~DLList()
{
	Node<TYPE> * pDel = front;

	while (front)
	{
		pDel = front->next;
		delete front;
		front = pDel;
	}

	rear = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::insert(const TYPE & dataIn)
{
	bool success = false;
	Node<TYPE> * pAfter = front;
	Node<TYPE> * pBefore = nullptr;
	Node<TYPE> * pNew;

	while ((pAfter) && (pAfter->data < dataIn))
	{
		pBefore = pAfter;
		pAfter = pAfter->next;
	}

	pNew = new(nothrow) Node<TYPE>(dataIn, pAfter, pBefore);

	if (pNew)
	{
		if (pBefore)
			pBefore->next = pNew;
		else
			front = pNew;

		if (pAfter)
			pAfter->prev = pNew;
		else
			rear = pNew;

		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::remove(TYPE & dataOut)
{
	bool success = false;
	Node<TYPE> * pDel = front;

	while ((pDel) && (pDel->data < dataOut))
	{
		pDel = pDel->next;
	}

	if ((pDel) && (pDel->data == dataOut))
	{
		dataOut = pDel->data;

		if (pDel->prev)
			pDel->prev->next = pDel->next;
		else
			front = pDel->next;

		if (pDel->next)
			pDel->next->prev = pDel->prev;
		else
			rear = pDel->prev;

		delete pDel;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::retrieve(TYPE & dataOut) const
{
	bool success = false;
	Node<TYPE> * pTemp = front;

	while ((pTemp) && (pTemp->data < dataOut))
	{
		pTemp = pTemp->next;
	}

	if ((pTemp) && (pTemp->data == dataOut))
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::viewFront(TYPE & dataOut) const
{
	bool success = false;

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::viewRear(TYPE & dataOut) const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::display() const
{
	bool success = false;
	Node<TYPE> * pTemp = front;

	while (pTemp)
	{
		cout << pTemp->data;
		pTemp = pTemp->next;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::displayReverse() const
{
	bool success = false;
	Node<TYPE> * pTemp = rear;

	while (pTemp)
	{
		cout << pTemp->data;
		pTemp = pTemp->prev;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
int DLList<TYPE> ::getNumValues() const
{
	int numValues = 0;
	Node<TYPE> * pTemp = front;

	while (pTemp)
	{
		numValues++;
		pTemp = pTemp->next;
	}

	return numValues;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::isEmpty() const
{
	return (front == nullptr);
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> ::isFull() const
{
	bool full = true;
	Node<TYPE> * pNew;

	pNew = new(nothrow) Node<TYPE>();

	if (pNew)
	{
		full = false;
		delete pNew;
	}

	return full;
}

//****************************************************************************************************

#endif
