//
// Created by mj on 2/8/20.
//

#ifndef CPP11TEST_TESTCLASSES_H
#define CPP11TEST_TESTCLASSES_H

#include <string>

class TestClass {
    public:
        std::string mVal;
    public:
        TestClass();
        TestClass(std::string iVal);
        ~TestClass();
};


#endif //CPP11TEST_TESTCLASSES_H
