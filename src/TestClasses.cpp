//
// Created by mj on 2/8/20.
//

#include "TestClasses.h"
#include <iostream>

using namespace std;


TestClass::TestClass():mVal("default") {
    cout<< "TestClass("<< mVal <<") is created!" << endl;

}

TestClass::TestClass(std::string iVal):mVal(iVal){
    cout<< "TestClass("<< mVal <<") is created!" << endl;
}

TestClass::~TestClass(){
    cout<< "TestClass("<< mVal <<") is destroyed!" << endl;
}