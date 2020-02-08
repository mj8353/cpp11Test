#include <iostream>
#include <memory>
#include "TestClasses.h"

using namespace std;

/*
 * Unique pointer: Function return
 *
 * */
unique_ptr<TestClass> GetUPtr(){
    std::cout << "###GetUPtr() in" << std::endl;

    unique_ptr<TestClass> rtnUPtr = unique_ptr<TestClass>(new TestClass("A"));

    std::cout << "###GetUPtr() out" << std::endl;

    return rtnUPtr; // 1
    // return move(rtnUPtr); // 2
    // return rtnUPtr; // 3
}

void UptrFunctionReturnTest(){
    std::cout << "##UptrFunctionReturnTest() in" << std::endl;

    unique_ptr<TestClass> uPtr = GetUPtr(); // 1
    // unique_ptr<TestClass> uPtr = GetUPtr(); // 2
    // unique_ptr<TestClass> uPtr = move(GetUPtr()); // 3

    std::cout << "##UptrFunctionReturnTest() out" << std::endl;
}


/*
 * Unique pointer: Function input
 *
 * */

void SetUPtr(unique_ptr<TestClass> iUptr){
    std::cout << "###SetUPtr() in" << std::endl;

    std::cout << "###SetUPtr() out" << std::endl;
}

void UptrFunctionInputTest(){
    std::cout << "##UptrFunctionInputTest() in" << std::endl;

    unique_ptr<TestClass> uPtr = unique_ptr<TestClass>(new TestClass(""));

    SetUPtr(move(uPtr));

    cout << "UHUHU" << endl;

    std::cout << "##UptrFunctionInputTest() out" << std::endl;
}

/*
 * Unique pointer: Common test
 *
 * */

void UptrCommonTest(){
    std::cout << "##UptrCommonTest() in" << std::endl;

    // Release Test
    unique_ptr<TestClass> uPtr = unique_ptr<TestClass>(new TestClass("C"));
    TestClass* classPtr = nullptr;

    /* Correct */
    classPtr = uPtr.release();
    delete classPtr;

    /* Wrong: Memory Leak*/
    //uPtr.release();

    // Reset Test
    unique_ptr<TestClass> uPtr2 = unique_ptr<TestClass>(new TestClass("D"));

    uPtr2.reset();

    uPtr2 = unique_ptr<TestClass>(new TestClass("E"));

    std::cout << "##UptrCommonTest() out" << std::endl;

}

int main() {
    std::cout << "#main() in" << std::endl;

    UptrFunctionReturnTest();

    cout << endl;

    UptrFunctionInputTest();

    cout << endl;

    UptrCommonTest();


    std::cout << "#main() out" << std::endl;
    return 0;
}
