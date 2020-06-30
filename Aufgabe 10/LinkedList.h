#pragma once

#include <iostream>
#include <memory>


template<class dataType>
class LinkedList
{
public:
	LinkedList();
	~LinkedList() = default;


	class Element {
	public:
		Element();
		~Element();
		dataType getData();
		void setData(dataType data);
		std::weak_ptr<Element> next;
		dataType m_data;
	};

	dataType getLastElement();
	void append(dataType data);


private:
	std::shared_ptr<Element> tail;
	std::shared_ptr<Element> head;

};


template<class dataType>
inline void LinkedList<dataType>::Element::setData(dataType data)
{
	m_data = data;
}


template<class dataType>
inline dataType LinkedList<dataType>::Element::getData()
{
	return m_data;
}

template<class dataType>
inline LinkedList<dataType>::Element::Element()
{
	//std::cout << "Create: " << typeid(this).name() << std::endl;
}

template<class dataType>
inline LinkedList<dataType>::Element::~Element()
{
	//std::cout << "Delete: " << typeid(this).name() << std::endl;
}


template<class dataType>
inline LinkedList<dataType>::LinkedList()
{
	tail = nullptr;
	head = nullptr;
}

template<class dataType>
inline dataType LinkedList<dataType>::getLastElement()
{
	return head->getData();
}

template<class dataType>
inline void LinkedList<dataType>::append(dataType data)
{
	tail = std::make_shared<Element>(Element());
	head = std::make_shared<Element>(Element());
	std::shared_ptr<Element> prevElement = head;
	head->setData(data);

	if (tail != nullptr) {
		prevElement->next = head;
	}
	else {
		tail = head;
	}
}
