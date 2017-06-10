namespace Antinus {
template<class T>
list<T>::list()
{
	Header = new list<T>::Node;
	Header->Next = Header;
	Header->Pre = Header;
	len = 0;
	//Array function
	updated = false;
	hide_array_ptr = nullptr;
	//fast_operation

}

template<class T>
list<T>::~list()
{
	list<T>::Node* tmp;
	list<T>::Node* left;
	left = Header->Pre;
	tmp = Header->Next;
	until(tmp == Header) {
		delete tmp->Pre;
		tmp = tmp->Next;
	}
	delete left;
	delete [] hide_array_ptr;
}



template<class T>
void list<T>::Insert(T element, unsigned long position)
{
	if (position > len) {
		throw "FATAL ERROR: INVALID INDEX";
	}
	list<T>::Node* tmp;
	list<T>::Node* New;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}
	New = new list<T>::Node;
	New->element = element;
	New->Next = tmp;
	New->Pre = tmp->Pre;
	tmp->Pre->Next = New;
	tmp->Pre = New;
	len++;
	updated = true;
}

template<class T>
void list<T>::Insert(T* element, unsigned long begin_position, unsigned long num_of_element)
{
	if (begin_position > len) {
		throw "FATAL ERROR: INVALID INDEX";
	}
	list<T>::Node* tmp;
	list<T>::Node* New;
	tmp = Header->Next;
	loop(begin_position) {
		tmp = tmp->Next;
	}

	loop(num_of_element) {
		New = new list<T>::Node;
		New->element = element[i];
		New->Next = tmp;
		New->Pre = tmp->Pre;
		tmp->Pre->Next = New;
		tmp->Pre = New;
	}
	len += num_of_element;
	updated = true;
}

template<class T>
void list<T>::Append(T element)
{
	list<T>::Node* New = new list<T>::Node;
	New->element = element;
	New->Pre = Header->Pre;
	New->Next = Header;
	Header->Pre->Next = New;
	Header->Pre = New;
	len ++;
	updated = true;
}

template<class T>
void list<T>::Append(T* element, unsigned long num_of_element)
{
	list<T>::Node* New;
	loop(num_of_element) {
		New = new list<T>::Node;
		New->element = element[i];
		New->Pre = Header->Pre;
		New->Next = Header;
		Header->Pre->Next = New;
		Header->Pre = New;
	}
	len += num_of_element;
	updated = true;
}

template<class T>
void list<T>::Push(T element)
{
	list<T>::Node* New = new list<T>::Node;
	New->element = element;
	New->Pre = Header;
	New->Next = Header->Next;
	Header->Next->Pre = New;
	Header->Next = New;
	len ++;
	updated = true;
}

template<class T>
void list<T>::Push(T* element, unsigned long num_of_element)
{
	list<T>::Node* New;
	loop(num_of_element) {
		New = new list<T>::Node;
		New->element = element[i];
		New->Pre = Header;
		New->Next = Header->Next;
		Header->Next->Pre = New;
		Header->Next = New;
	}
	len += num_of_element;
	updated = true;
}

template<class T>
T list<T>::Query(unsigned long position)
{
	if (position > len - 1 || len == 0) {
		throw "FATAL ERROR: INVALID INDEX";
	}
	else {
		list<T>::Node* tmp;
		tmp = Header->Next;
		loop(position) {
			tmp = tmp->Next;
		}
		return tmp->element;
	}
}

template<class T>
void list<T>::Delete(unsigned long position)
{
	if (position > len - 1 || len == 0) {
		throw "FATAL ERROR: INVALID INDEX";
	}

	list<T>::Node* tmp;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}

	tmp->Next->Pre = tmp->Pre;
	tmp->Pre->Next = tmp->Next;

	delete tmp;

	len--;
	updated = true;
}

template<class T>
void list<T>::Rewrite(T element, unsigned long position)
{
	if (position > len - 1 || len == 0) {
		throw "FATAL ERROR: INVALID INDEX";
	}
	list<T>::Node* tmp;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}
	tmp->element = element;
	updated = true;
}

template<class T>
unsigned long list<T>::length()
{
	return this->len;
}

template<class T>
unsigned long  list<T>::Alloc(unsigned long num_of_element)
{
	list<T>::Node* New;
	unsigned ret = len;
	loop(num_of_element) {
		New = new list<T>::Node;
		New->Pre = Header->Pre;
		New->Next = Header;
		Header->Pre->Next = New;
		Header->Pre = New;
	}
	len += num_of_element;
	updated = true;
	return ret;
}

template<class T>
void list<T>::Clear()
{
	list<T>::Node* tmp = Header->Next;
	list<T>::Node* f;
	until(tmp == Header) {
		f = tmp->Next;
		delete tmp;
		tmp = f;
	}
	Header->Next = Header->Pre = Header;
	updated = true;
}

template<class T>
T* list<T>::Array()
{
	if (updated) {
		updated = false;
		delete [] hide_array_ptr;
		hide_array_ptr = new T[len];
		list<T>::Node* tmp = Header->Next;
		loop(len) {
			hide_array_ptr[i] = tmp->element;
			tmp = tmp->Next;
		}
	}
	return hide_array_ptr;
}

template<class T>
void list<T>::load(T* base, unsigned long num_of_element)
{
	Clear();
	Append(base, num_of_element);
	updated = true;
}

template<class T>
T& list<T>::operator [] (unsigned long position)
{
	if (position > len - 1 || len == 0) {
		throw "FATAL ERROR: INVALID INDEX";
	}
	else {
		list<T>::Node* tmp;
		tmp = Header->Next;
		loop(position) {
			tmp = tmp->Next;
		}
		updated = true;
		return tmp->element;
	}
}
}