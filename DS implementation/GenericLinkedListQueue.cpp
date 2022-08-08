#include <iostream>
template <class T>
class LinkedNode
{
public:
	LinkedNode():next_(nullptr),data_(0){}
	LinkedNode<T>* next_;
	T data_;
};

template <class T>
class Queue
{
public:
	Queue() : head_(nullptr), tail_(nullptr) {}
	~Queue();
	void Enqueue(T value);
	T Dequeue();
	bool Empty();
	void Display();
private:
	LinkedNode<T>* head_;
	LinkedNode<T>* tail_;
};

template <class T>
Queue<T>::~Queue()
{
	while (!Empty())
	{
		LinkedNode<T>* old = head_;
		head_ = old->next_;
		delete old;
	}
}

template <class T>
void Queue<T>::Enqueue(T value)
{
	LinkedNode<T>* Node = new LinkedNode<T>;
	Node->data_ = value;
	Node->next_ = nullptr;

	if (Empty())
	{
		tail_ = head_ = Node;
	}
	else
	{
		tail_->next_ = Node;
		tail_ = Node;
	}
}

template <class T>
T Queue<T>::Dequeue()
{
	T value = head_->data_;
	auto old = head_;

	head_ = old->next_;
	delete old;
	return value;
}
template <class T>
bool Queue<T>::Empty()
{
	return head_ == nullptr;
}

template <class T>
void Queue<T>::Display()
{
	while (head_)
	{
		std::cout << head_->data_ << "-->";
		head_ = head_->next_;
	}
	std::cout << "Null";
}

int main()
{
	Queue<int> Q;
	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);
	Q.Enqueue(4);
	Q.Enqueue(5);
	Q.Dequeue();
	std::cout << Q.Empty() << std::endl;
	Q.Display();
	return 0;
}
