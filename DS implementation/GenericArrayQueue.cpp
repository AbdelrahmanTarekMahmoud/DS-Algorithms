#include <iostream>
template<typename T>
class Queue
{
	static const int kCapacity = 5;
	static const int kPositions = kCapacity + 1;

public:
	Queue() :insert_(0), pop_(0) {}
	void Enqueue(T value);
    T Dequeue();
	bool Empty();
	void Display();
private:
	int insert_;
	int pop_;
	T data_[kPositions];
};

template<typename T>
void Queue<T>::Enqueue(T value)
{
	data_[insert_] = value;
	insert_++;
}

template<typename T>
T Queue<T>::Dequeue()
{
	if (Empty())
	{
		std::cerr << "Empty Queue (:" << std::endl;
		exit(EXIT_FAILURE);
	}
	T value = data_[pop_];
	data_[pop_] = 0;
	pop_++;
	
	return value;
}
template<typename T>
bool Queue<T>::Empty()
{
	return pop_ == insert_;
}

template<typename T>
void Queue<T>::Display()
{
	while (pop_ < insert_)
	{
		std::cout << data_[pop_] << "   ";
		pop_++;
	}
}


int main()
{
	Queue<int> Q;
	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);
	Q.Enqueue(4);
	Q.Dequeue();
	Q.Display();
	return 0;
}
