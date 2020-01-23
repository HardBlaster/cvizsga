//
// Created by hidie on 2020. 01. 23..
//

#ifndef VIZSGA_POLYGON_H
#define VIZSGA_POLYGON_H

#include <iostream>
using namespace std;

class CPolygon {
protected:

    int width, height;

public:

    CPolygon() = default;
    CPolygon(int w, int h): width(w), height(h) {}

    virtual ~CPolygon() = default;

    void setup (int first, int second) {

        width= first;
        height= second;

    }

    virtual double area() const = 0;

    void onscreen() {
        cout << this->area() << endl;
    }
};

class CRectangle: public CPolygon {

public:

    CRectangle() = default;
    CRectangle(int w, int h): CPolygon(w, h) {}
    CRectangle(CRectangle const &rectangle): CPolygon(rectangle.width, rectangle.height) {}

    CRectangle(CRectangle &&rectangle): CPolygon(rectangle.width, rectangle.height) {
        rectangle.width = 0;
        rectangle.height = 0;
    }

    CRectangle& operator=(CRectangle const &rectangle) {
        width = rectangle.width;
        height = rectangle.height;

        return *this;
    }

    double area() const override {
        return (width * height);
    }

    bool compare(CRectangle const& rectangle) {
        return this->area() > rectangle.area();
    }
};

class CTriangle: public CPolygon {

public:

    CTriangle() = default;
    CTriangle(int w, int h): CPolygon(w, h) {}
    CTriangle(CTriangle const &triangle): CPolygon(triangle.width, triangle.height) {}

    CTriangle(CTriangle &&triangle): CPolygon(triangle.width, triangle.height) {
        triangle.width = 0;
        triangle.height = 0;
    }

    CTriangle& operator=(CTriangle const &triangle) {
        width = triangle.width;
        height = triangle.height;

        return *this;
    }

    double area() const override {
        return (width * height / 2);
    }

    bool compare(CTriangle const& triangle) {
        return this->area() > triangle.area();
    }
};

#endif //VIZSGA_POLYGON_H
