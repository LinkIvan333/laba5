//Copyright 2020 <LinkIvan333>

#ifndef INCLUDE_STACK2_HPP_
#define INCLUDE_STACK2_HPP_
#include <memory>
#include <iostream>
#include <utility>
template <typename T>
struct test2{
    T value;
    test2<T> *prev;
    test2(T value1, test2<T> *prev1) : value(value1), prev(prev1) {}
};
template <typename T>
class stack
{
private:
    test2<T> *abc;
public:
    stack();
    ~stack();
    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(T&& value);
    void push(const T& value);
    const T& head() const;
    void pop();
    stack(stack &&stack2);
    stack<T>& operator=(stack<T>&& stack);
};

template<typename T>
stack<T>::stack() {
    abc=nullptr;
}

template <typename T>
stack<T>::stack(stack&& st) {
    std::swap(*abc, *st.abc);
}

template <typename T>
stack<T>& stack<T>::operator=(stack<T>&& st) {
    std::swap(*abc, *st.abc);

    return *this;
}

template<typename T>
stack<T>::~stack(){
    delete abc;
}
template<typename T>
template <typename ... Args>
void stack<T>::push_emplace(Args&&... value){
    auto item = abc;
    abc = new test2<T>{{std::forward<Args>(value)...}, item};
}

template <typename T>
void stack<T>::pop() {
    if (!abc)
        throw std::logic_error("no stack");
    else {
        abc = abc->prev;
    }
}

template <typename T>
const T& stack<T>::head() const{
    if (!abc)
        throw std::logic_error("no stack");
    else
        return abc->value;
}

template <typename T>
void stack<T>::push(const T& value) {
    auto item = abc;
    abc = new test2<T>{std::forward<T>(value), item};
}

template <typename T>
void stack<T>::push(T&& value) {
    auto item = abc;
    abc = new test2<T>{std::forward<T>(value), item};
}


#endif // INCLUDE_STACK2_HPP_
