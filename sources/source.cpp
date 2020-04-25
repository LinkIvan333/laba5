//Copyright 2020 <LinkIvan333>

#include <simple_stack.hpp>
#include <stack.hpp>
#include <any>

int main(){
        stack <std::any> stack;
        stack.push(1);
        stack.push(20);
        stack.push_emplace<std::any>(2, 3, 8, "abc", 4.2, 'a');
        std::cout << std::any_cast<char>(stack.head());
    return 0;
}
