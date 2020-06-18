#pragma once

#include <iostream>
#include <memory>


template<class dataType>
class LinkedList
{
public:
	LinkedList();
	~LinkedList() = default;

	/*struct node {
		node* next; 
		dataType item;
	};*/


	class Element {
	public:
		Element();
		~Element();
		dataType getData();
		dataType setData(dataType data);
		std::shared_ptr<Element> next = std::make_shared<Element>(Element());

	private:
		dataType m_data;
	};

	void setElement(dataType data);
	dataType getElement();
	
	void previous();
	void next();
	void last();
	int getSize();
	void append(dataType data);


private:
	std::shared_ptr<Element> iterator;
	std::shared_ptr<Element> tail;
	std::shared_ptr<Element> head;
};

template<class dataType>
inline LinkedList<dataType>::Element::Element()
{
	std::cout << "Create: " << typeid(this).name() << std::endl;
}

template<class dataType>
inline LinkedList<dataType>::Element::~Element()
{
	std::cout << "Delete: " << typeid(this).name() << std::endl;
}

template<class dataType>
inline dataType LinkedList<dataType>::Element::getData()
{
	return m_data;
}


template<class dataType>
inline dataType LinkedList<dataType>::Element::setData(dataType data)
{
	m_data = data;
}

template<class dataType>
inline LinkedList<dataType>::LinkedList()
{
	head = nullptr;
}

template<class dataType>
inline dataType LinkedList<dataType>::getElement()
{
	return iterator->getData();
}

template<class dataType>
inline void LinkedList<dataType>::append(dataType data)
{
	head = std::make_shared<Element>(Element());
	tail = std::make_shared<Element>(Element());
	std::shared_ptr<Element> previousElement = std::make_shared<Element>(Element());
	previousElement = head;

	head = data;
	tail = head; 	 
}
