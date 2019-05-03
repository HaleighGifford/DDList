//****************************************************************************************************
//
//		File:					Node.h
//		
//		Student:				Haleigh Cates
//
//		Assignment:	 			Program  #11
//
//		Course Name:			Data Structures I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					December 4, 2018
//
//
//		This program enahances the linked list program #6 to use a 
//		doubly linked list.
//
//		Other files required:	
//								DLList.h
//								student.h
//								studentList.cpp
//								studentFile.txt
//		
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE> * next;
	Node<TYPE> * prev;

	Node();
	Node(const TYPE & d, Node<TYPE> * n = nullptr, Node<TYPE> * p = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> ::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> ::Node(const TYPE & d, Node<TYPE> * n, Node<TYPE> * p)
{
	data = d;
	next = n;
	prev = p;
}

//****************************************************************************************************

#endif

