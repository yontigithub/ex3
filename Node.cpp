//
// Created by Yonatan Rappoport on 31/05/2023.
//

#include "Node.h"

// Constructors
template <class T>
Node<T>::Node(T value) :
    m_next(0),
    m_value(value)
{

}

template <class T>
Node<T>::Node() :
    m_next(0),
    m_prev(0),
    m_value(0)
{

}

// Setters
template <class T>
void Node<T>::SetNext(const Node<T>& next) {
    m_next(&next);
}

template <class T>
void Node<T>::SetPrev(const Node<T>& prev) {
    m_prev(prev);
}

template <class T>
void Node<T>::SetValue(const T& value) {
    m_value(value);
}

// Getters
template <class T>
Node<T>& Node<T>::GetNext() const {
    return *m_next;
}

template <class T>
Node<T>& Node<T>::GetPrev() const {
    return m_prev;
}

template <class T>
T Node<T>::GetValue() const {
    return m_value;
}