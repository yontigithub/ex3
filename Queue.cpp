//
// Created by Yonatan Rappoport on 31/05/2023.
//

#include "Queue.h"

template <class T>
Queue<T>::Queue() :
    m_head(nullptr),
    m_tail(nullptr),
    m_size(0)
{

}

template <class T>
Queue<T>::Queue(const Queue<T>& queue) :
    m_head(nullptr),
    m_tail(nullptr),
    m_size(queue.m_size)
{
    for(T element : queue) {
        this->pushBack(element);
    }
}

template <class T>
Queue<T>::~Queue() {
    while(this->size()) {
        this->popFront();
    }
} // C'tor & d'tor

template <class T>
void Queue<T>::pushBack(T value) {
    Node node(value);

    if(this->size() == 0) {
        m_head = &node;
        m_tail = &node;
    } else {
        node.m_next = m_tail;
        m_tail->m_prev = &node;
        m_tail = &node;
    }

    ++m_size;
}

template <class T>
T& Queue<T>::front() const {
    if(m_head == nullptr) {
        return NULL;
    }

    return m_head->m_value;
}

template <class T>
void Queue<T>::popFront() {
    if(m_head == nullptr) {
        return;
    }

    m_head->m_prev->m_next = nullptr;
    Node* newHead = m_head->m_prev;
    m_head->~Node();
    m_head = newHead;
    m_size--;
}

template <class T>
int Queue<T>::size() const {
    return m_size;
}

template <class T>
Queue<T>& filter(Queue<T> &queue, bool (*FilterFunction)(T)) {
    Queue<T> result;

    for(T element : queue) {
        if(FilterFunction(element)) {
            result.push_back(element);
        }
    }

    return result;
}

template <class T>
void transform(Queue<T> &queue, void (*TransformationFunction)(T&))  {
    for(T& element : queue) {
        TransformationFunction(element);
    }
} // Methods

template <class T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(m_head);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(nullptr);
}

template <class T>
Queue<T>::Iterator::Iterator(Node* node) :
    m_node(node)
{

}

template <class T>
T& Queue<T>::Iterator::operator*() const {
    if(m_node == nullptr) {
        return NULL;
    }

    return m_node->m_value;
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {

    if(m_node == nullptr) {
        throw Queue<T>::Iterator::InvalidOperation();
    }

    m_node = m_node->m_prev;

    return *this;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {
    Iterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool Queue<T>::Iterator::operator==(const Iterator& iterator) const {

    if(m_node == nullptr || iterator.m_node == nullptr) {
        return (m_node == nullptr && iterator.m_node == nullptr);
    }

    return (m_node->m_prev == iterator.m_node->m_prev &&
            m_node->m_next == iterator.m_node->m_next &&
            m_node->m_value == iterator.m_node->m_value);
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator& iterator) const {
    return !(*this == iterator);
} // Iterator



template <class T>
Queue<T>::ConstIterator::ConstIterator(Node* node) :
        m_node(node)
{

}

template <class T>
const T& Queue<T>::ConstIterator::operator*() const {
    if(m_node == nullptr) {
        return NULL;
    }

    return m_node->m_value;
}

template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() {

    if(m_node == nullptr) {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }

    m_node = m_node->m_prev;

    return *this;
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int) {
    ConstIterator result = *this;
    ++*this;
    return result;
}

template <class T>
Queue<T>::ConstIterator::ConstIterator(const Iterator& constIterator) :
    m_node(constIterator.m_node)
{

}

template <class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator& constIterator) const {

    if(m_node == nullptr || constIterator.m_node == nullptr) {
        return (m_node == nullptr && constIterator.m_node == nullptr);
    }

    return (m_node->m_prev == constIterator.m_node->m_prev &&
            m_node->m_next == constIterator.m_node->m_next &&
            m_node->m_value == constIterator.m_node->m_value);
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& constIterator) const {
    return !(*this == constIterator);
} // ConstIterator

template <class T>
Queue<T>::Node::Node(T value) :
        m_next(nullptr),
        m_prev(nullptr),
        m_value(value)
{

}

template <class T>
Queue<T>::Node::Node() :
        m_next(nullptr),
        m_prev(nullptr),
        m_value(NULL)
{

} // Node
