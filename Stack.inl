//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return top_ + 1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if(top_ == -1) {
		try{
			throw empty_exception("Stack is empty.");
		}
		catch(const empty_exception& em){
			std::cout<<em.what()<<std::endl;
		}
		return T();
	}
	else {
		return array_.get(top_);
	}
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{	
	//program is designed to set top_ to -1 if stack is empty 
	//which explains why -1 is used to indicate if stack is empty
	if(top_ != -1) {
		return false;
	}
	return true;
}
