#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::swap;
using std::uniform_int_distribution;
using std::vector;

//Class which represents the Node
template <class T>
struct Node
{
	Node<T>* next_;
	T data_;
};
template <class T>
class LinkedList
{
public:
	//constructor
	LinkedList();
	//destructor
	~LinkedList();
	//Return The number of elements in the LinkedList
	int Size();
	// Add a new node to the linked list with the given value
	void AddFront(T value);
	//Check if the linked list is empty or not
	bool IsEmpty();
	//Return the value at the given index
	T ValueAt(int index);
	//Display the linked list data
	void PrintTheListInfo();
	//Remove the first Node
	T RemoveFront();
	//Add item at the end of the linked list
	void AddBack(T value);
	//Remove the last item in the linked list
	T RemoveBack();
	// return the value of the front item
	T Front();
	//returns the value of the last item
	T Back();
	//insert item at the given index with the given value
	void Insert(int index, T value);
	//erase the item at the give index
	void Erase(int index);
	//reverse the linked list
	void Reverse();
private:
	Node<T>* head_;
};
template <class T>
LinkedList<T>::LinkedList()
{
	head_ = NULL;
}
template <class T>
LinkedList<T>::	~LinkedList()
{
	while (IsEmpty())
	{
		RemoveFront();
    }
}

template <class T>
int LinkedList<T>::Size()
{
	int size = 0;
	auto current = head_;
	while (current)
	{
		current = current->next_;
		size++;
	}
	return size;
}

template <class T>
void LinkedList<T>::AddFront( T value)
{
	Node<T>* L = new Node<T>;
	L->next_ = head_;
	L->data_ = value;
	head_ = L;
	
}

template <class T>
bool LinkedList<T>::IsEmpty()
{
	return head_ == nullptr;
}

template <class T>
T LinkedList<T>::ValueAt(int index)
{
	Node<T>* current = head_;
	
	for (int i = 0;i < index&&current!=nullptr;i++)
	{
		current = current->next;
	}
	if (current == nullptr) {
		std::cerr << "Index out of bounds." << std::endl;
		exit(EXIT_FAILURE);
	}
	return current->data_;
}

template <class T>
void LinkedList<T>::PrintTheListInfo()
{

		Node<T>* current = head_;
		cout << " {";
		while (current)
		{
			cout << current->data_ << "---->";
			current = current->next_;
		}
		cout << "---> NULL  " << "}";
	
}

template <class T>
T LinkedList<T>::RemoveFront()
{
	if (IsEmpty())
	{
		std::cerr << "List is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	Node<T>* old = head_;
	head_ = old->next_;
	T value = old->data_;
	delete old;
	return value;
}

template <class T>
void LinkedList<T>::AddBack(T value)
{
	
	Node<T>* current = head_;
	Node<T>* L = new Node<T>;
	if (IsEmpty())
	{
		head_ = L;
		return;
	}
	while (current)
	{
		current = current->next_;
	}
	current->next_ = L;
	L->data_ = value;
}

template <class T>
T LinkedList<T>::RemoveBack()
{
	if (head_ == nullptr) {
		std::cerr << "List is empty" << std::endl;
		exit(EXIT_FAILURE);
	}

	Node<T>* current = head_;
	Node<T>* prev = nullptr;

		while (current)
		{
			prev = current;
			current = current->next_;
	    }
	prev->next_ = nullptr;
	auto value = current->data_;
	delete current;
	return value;
}

template <class T>
T LinkedList<T>::Front()
{
	if (head_ == nullptr) {
		std::cerr << "List is empty" << std::endl;
		exit(EXIT_FAILURE);
	}

	return head_->data_;
}
template <class T>
T LinkedList<T>::Back()
{
	if (head_ == nullptr) {
		std::cerr << "List is empty" << std::endl;
		exit(EXIT_FAILURE);
	}

	Node<T>* current = head_;
	while (current)
	{
		current = current->next_;
	}
	return current->data_;
}
template <class T>
void LinkedList<T>::Insert(int index, T value)
{
	Node<T>* L = new Node<T>;
	Node<T>* current = head_;
	Node<T>* prev = nullptr;
	if (IsEmpty())
	{
		head_ = L;
		return;
	}
	int i;
	for ( i = 0;i < index && current;i++)
	{
		prev = current;
		current = current->next_;
	}
	if (i != index) 
	{
		std::cerr << "Index out of bounds." << std::endl;
		exit(EXIT_FAILURE);
	}
	prev->next_ = L;
	L->next_ = current;
	L->data_ = value;

}
template <class T>
void LinkedList<T>::Erase(int index)
{
	Node<T>* current = head_;
	Node<T>* prev = nullptr;
	if (IsEmpty())
	{
		std::cerr << "List is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	int i;
	for ( i = 0;i < index && current;i++)
	{
		prev = current;
		current = current->next_;
	}
	if (i != index)
	{
		std::cerr << "Index out of bounds." << std::endl;
		exit(EXIT_FAILURE);
	}
	prev->next_ = current->next_;
	delete current;
}

template <class T>
void LinkedList<T>::Reverse()
{
	Node<T>* current = head_;
	Node<T>* prev = nullptr;
	Node<T>* Next = new Node<T>;
	while (current)
	{
		Next = current->next_;
		current->next_ = prev;
		prev = current;
		current = Next;
	}
	head_ = prev;
}


int main()
{
	LinkedList<int> list;
	list.AddFront(1);
	list.AddFront(2);
	list.AddFront(3);
	list.Insert(2, 4);
	list.PrintTheListInfo();
	list.IsEmpty();

	return 0;
}
