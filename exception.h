//
// Created by hidie on 2020. 01. 24..
//

#ifndef VIZSGA_EXCEPTION_H
#define VIZSGA_EXCEPTION_H

#include <exception>

using namespace std;

struct TestException : public exception {
    const char * what () const noexcept override {
        return "When do we have a beer?";
    }
};

#endif //VIZSGA_EXCEPTION_H
