#ifndef _LIST_H_
#define _LIST_H_

#include "../BASICBase/loop.h"

namespace Antinus {
template <class T>
class list {
public:
	class Node {
	public:
		T element;
		Node* Pre;
		Node* Next;
	};
private:
	//Fast_operation

private:
	list<T>::Node* Header;
	unsigned long len;
private:
	//Array function
	bool updated;
	T* hide_array_ptr;
public:
	list();
	~list();
public:
	void Insert(T element, unsigned long position); // Insert at position (example: l = {2,3} l.insert(-1,0) -> l = {-1,2,3} )
	void Insert(T* element, unsigned long begin_position, unsigned long num_of_element);
	void Append(T element);
	void Append(T* element, unsigned long num_of_element);
	void Push(T element);
	void Push(T* element,unsigned long num_of_element);
	T Query(unsigned long position);
	void Delete(unsigned long position);
	void Rewrite(T element, unsigned long position);
public:
	unsigned long length();
public:
	void Clear();
public:
	//Array function
	T* Array();
	void load(T* base, unsigned long num_of_element);
	unsigned long Alloc(unsigned long num_of_element);
public:
	T& operator [] (unsigned long position);
};

}

#include "list.inl"
#endif