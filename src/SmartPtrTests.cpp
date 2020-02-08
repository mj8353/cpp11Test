#include <iostream>
#include <memory>
#include "TestClasses.h"

using namespace std;

unique_ptr<TestClass> GetUPtr(){
    std::cout << "###GetUPtr() in" << std::endl;

    unique_ptr<TestClass> rtnUPtr = unique_ptr<TestClass>(new TestClass("A"));

    std::cout << "###GetUPtr() out" << std::endl;

    return rtnUPtr; // 1
    // return move(rtnUPtr); // 2
    // return rtnUPtr; // 3
}

void FunctionReturnTest(){
    std::cout << "##FunctionReturnTest() in" << std::endl;

    unique_ptr<TestClass> uPtr = GetUPtr(); // 1
    // unique_ptr<TestClass> uPtr = GetUPtr(); // 2
    // unique_ptr<TestClass> uPtr = move(GetUPtr()); // 3

    std::cout << "##FunctionReturnTest() out" << std::endl;
}

void SetUPtr(unique_ptr<TestClass> iUptr){
    std::cout << "###SetUPtr() in" << std::endl;

    std::cout << "###SetUPtr() out" << std::endl;
}

void FunctionInputTest(){
    std::cout << "##FunctionInputTest() in" << std::endl;

    unique_ptr<TestClass> uPtr = unique_ptr<TestClass>(new TestClass(""));

    SetUPtr(move(uPtr));

    cout << "UHUHU" << endl;

    std::cout << "##FunctionInputTest() out" << std::endl;
}

void CommonTest(){

    // Release Test
    unique_ptr<TestClass> uPtr = unique_ptr<TestClass>(new TestClass("C"));
    TestClass* classPtr = nullptr;

    /* Correct */
    classPtr = uPtr.release();
    delete classPtr;

    /* Wrong: Memory Leak*/
    //uPtr.release();

}

int main() {
    std::cout << "#main() in" << std::endl;

    FunctionReturnTest();

    cout << endl;

    FunctionInputTest();

    cout << endl;

    CommonTest();


    std::cout << "#main() out" << std::endl;
    return 0;
}
