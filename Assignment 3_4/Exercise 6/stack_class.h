#ifndef _STACK_H_
#define _STACK_H_

#include "double_list.h"

template <typename Object>
class Stack {
  private:
	List<Object> *list;

  public:
	Stack() {
		list = new List<Object>();
	}

	~Stack() { delete list; }

	 // Add a size member function
	int size() const { return list->size(); } 

    	// Mark empty as const
	bool empty() const { return (list->size() == 0); }

	Object top() { return list->find_kth(0); }
	Object pop() { return list->pop_front(); }

	void push(const Object x) {
		list->push_front(x);
	}
};

#endif
