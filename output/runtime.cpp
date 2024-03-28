#include <iostream>

extern void print(int a) asm("print");
extern void choco_main() asm("choco_main");

// ffi to the chococ compiler
void print(int a) {
    std::cout<<a<<std::endl;
}

// this file will link against the llvm code that is generated by the chococ compiler
int main() {

    // call the choco_main function
    choco_main();   
}