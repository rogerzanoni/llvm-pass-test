#include <stdio.h>

class Hello {
public:
    Hello() {}

    void hello() {
        printf("hello world from hello class\n");
    }
};

void hello() {
    printf("hello world from hello function\n");
}

int main() {
    printf("hello world\n");

    Hello helloobj;
    helloobj.hello();

    hello();

    return 0;
}
