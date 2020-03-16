//Copyright 2020 <LinkIvan333>

#include <simple_stack.hpp>
#include <stack.hpp>
#include <any>

int main(){
    const int a = 7;
    const double b = 15;
    const std::string c="ds";
        simple_stack <std::any> stack;
        stack.push(a);
        stack.push(b);
        stack.push(c);
        std::cout << std::any_cast<std::string>(stack.head());

    return 0;
}
