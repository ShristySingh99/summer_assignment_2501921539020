#include <iostream>
using namespace std;

class Test {
public:
    virtual void square(int num) = 0;
    virtual ~Test() {}
};

class Arithmetic : public Test {
public:
    void square(int num) override {
        cout << "Square of " << num << " is: " << (num * num) << endl;
    }
};

class ToTestInt {
public:
    void testInterface() {
        Arithmetic obj;
        obj.square(5);
    }
};

class Outer {
public:
    void display() {
        cout << "Display function of Outer class." << endl;
    }

    class Inner {
    public:
        void display() {
            cout << "Display function of Inner class." << endl;
        }
    };
};

class Point {
private:
    int x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void printPoint() {
        cout << "Point coordinates: (" << x << ", " << y << ")" << endl;
    }
};

class Box {
protected:
    double length;
    double breadth;

public:
    Box(double l = 0, double b = 0) {
        length = l;
        breadth = b;
    }

    void setLengthBreadth(double l, double b) {
        length = l;
        breadth = b;
    }

    double findArea() {
        return length * breadth;
    }
};

class Box3d : public Box {
private:
    double height;

public:
    Box3d(double l = 0, double b = 0, double h = 0) : Box(l, b) {
        height = h;
    }

    void setDimensions(double l, double b, double h) {
        setLengthBreadth(l, b);
        height = h;
    }

    double findVolume() {
        return length * breadth * height;
    }
};

int main() {
    cout << "--- Problem 1: Interface Test ---" << endl;
    ToTestInt tester;
    tester.testInterface();
    cout << endl;

    cout << "--- Problem 2: Outer & Inner Class ---" << endl;
    Outer outerObj;
    outerObj.display();
    
    Outer::Inner innerObj;
    innerObj.display();
    cout << endl;

    cout << "--- Problem 3: Point Class ---" << endl;
    Point p1;
    p1.printPoint();
    
    Point p2(10, 20);
    p2
