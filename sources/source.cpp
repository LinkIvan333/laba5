//Copyright 2019 <LinkIvan333>

#include <stack1.hpp>
#include <stack2.hpp>
int main(){
    stack1<int> t;
    stack2<int> y;
    stack1<int> e;
    for (int i = 0; i < 10; i++){
        t.push(i);
    }
    stack1<int> z(std::move(t));
    for (int i = 0; i < 10; i++) {
        std::cout << z.head() << "\t";
        z.pop();
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++){
        z.push(i);
    }
    e = std::move(z);
    for (int i = 0; i < 10; i++){
        std::cout << e.head() << "\t";
        e.pop();
    }
    std::cout << std::endl;
    y.push_emplace(0, 1, 2);
    for (int i = 0; i < 3; i++){
        std::cout << y.head() << "\t";
       y.pop();
    }

    return 0;
}
