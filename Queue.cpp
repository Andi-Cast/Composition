//Queue.cpp
//Andi Castillo-Mauricio

//
//Queue
//
template <typename T>
Queue <T>::Queue(void)
:array_(Array<T>(10)),
 array_size_(10),
 queue_size_(0),
 front_(0),
 back_(-1)
{
}

//
//Queue
//
template <typename T>
Queue <T>::Queue(const Queue & q)
:array_(Array<T>(q.array_size_)),
 array_size_(q.array_size_),
 queue_size_(q.queue_size_),
 front_(q.front_),
 back_(q.back_)
{
}

//
//~Queue
//
template <typename T>
Queue <T>::~Queue(void)
{
}

//
//operator =
//
template <typename T>
const Queue<T> & Queue<T>::operator = (const Queue & rhs)
{
	if(this == &rhs) {
		return *this;
	}
	else {
		array_ = rhs.array_;
		array_size_ = rhs.array_size_;
		queue_size_ = rhs.queue_size_;
		front_ = rhs.front_;
		back_ = rhs.back_;
	}
	return *this;
}

//
//enqueue
//
template <typename T>
void Queue<T>::enqueue(T element)
{
	//check to see if there is space
	if(array_size_ == queue_size_) {
		//make new array with more space since all it is used
		Array<T> newArray_ = Array<T>(array_size_*2);

		//Stored temp queue_size_ since I used dequeue() to 
		//retrieve values in order and dequeue() interacts with 
		//the queue_size_ variable.
		int tempQueue_Size_ = queue_size_;
		
		//copy over data from old array to new array
		for(int i = 0; i < array_size_; i++) {
			newArray_.set(i,this->dequeue());
		}

		//reset values
		front_ = 0;
		back_ = array_size_ - 1;
		array_size_ = array_size_*2;
		queue_size_ = tempQueue_Size_;


		//assign new array to this queue
		array_ = newArray_;
	}
	
	back_++;

	//using a circular arrya design so if there is space available 
	//and next space is outside the index range it is set to 0
	if(back_ == array_size_ && queue_size_ < array_size_) {
		back_ = 0;
		array_.set(back_, element);
		queue_size_++;
	}
	else {
		array_.set(back_, element);
		queue_size_++;
	}
}

//
//dequeue
//
template <typename T>
T Queue<T>::dequeue(void) 
{
	if(queue_size_ == 0) {
		//reset values to start at the beginning
		front_ = 0;
		back_ = -1;
		
		//throw empty exception if queue is empty
		throw empty_exception("Queue is empty.");
	}
	else {
		//get value at front to return 
		T value = array_.get(front_);
		
		front_++;

		//checks to see if at end of array to return to beginning if needed
		if(front_ == array_size_ && queue_size_ < array_size_) {
			front_ = 0;
		}

		queue_size_--;
		return value;
	}
}

//
//is_empty
//
template <typename T>
bool Queue<T>::is_empty(void) const
{
	return queue_size_ == 0;
}

//
//size
//
template <typename T>
size_t Queue<T>::size(void) const
{
	return queue_size_;
}

//
//clear
//
template <typename T>
void Queue<T>::clear(void) 
{
	front_ = 0;
	back_ = -1;
	queue_size_ = 0;
}