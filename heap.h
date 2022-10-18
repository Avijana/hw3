#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> heap_;
	int m_;
	PComparator compare;
	void trickleUp(int loc);
	void heapify(int idx);
};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) /* Don't specify the default value here, only above */  
// Your code here
{
	m_ = m;
	compare = c;
	//T variable;
	//heap_.push_back(variable); //does this work?
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc)
{
	int parent = (loc-1)/m_; //for start at 0
	while(parent >= 0 && compare(heap_[loc], heap_[parent]))
	{ 
		std::swap(heap_[parent], heap_[loc]); 
		loc = parent;
		parent = (loc-1)/m_; 
	}
}



template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
  unsigned int lChild = (idx * m_) + 1;
	unsigned int rChild = (idx * m_) + 2; 

  if ((lChild >= heap_.size() || heap_.size() ==0) && rChild >= heap_.size()) //checks if leaf node
	{ //&& r >= heap_.size()) { 
    return; 
  }

	for (int i = 0; i < m_ && (rChild + i) < heap_.size(); i++) //implemented so it works for any m. checks all children
	{
		if (compare(heap_[rChild+i], heap_[lChild]))
		{
			lChild = rChild + i; 
		}
	}

  if (compare(heap_[lChild], heap_[idx])) {
			std::swap(heap_[idx], heap_[lChild]);
			heapify(lChild); 
  }
}




// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){

    // ================================
    // throw the appropriate exception
    // ================================
		 throw std::underflow_error("The Heap is Empty"); 

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	
	return heap_[0]; //RETURN 0 HERE
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		 throw std::underflow_error("The Heap is Empty"); 

  }
	heap_[0] = heap_.back(); 
	heap_.pop_back();
	heapify(0); 

	
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
	heap_.push_back(item);
	trickleUp(heap_.size()-1);


}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
	return (heap_.size() == 0);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return heap_.size();
}



#endif

