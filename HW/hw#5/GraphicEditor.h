#include <iostream>
using namespace std;

class Shape {
public:
    virtual void get() = 0;
    virtual ~Shape() {}
};

class Line : public Shape {
public:
    void get() {
        cout << "Line";
    }
};

class Rect : public Shape {
public:
    void get() { 
        cout << "Rectangle";
    }
};

class Circle : public Shape {
public:
    void get() {
        cout << "Circle";
    }
};

class GraphicEditor {
    int size;
    Shape* p[100];
public:
    GraphicEditor() {
        size = 0;
        for (int i = 0; i < 100; i++) {
            p[i] = NULL;
        }
    }

    ~GraphicEditor() {
        for (int i = 0; i < size; i++) {
            delete p[i];
        }
    }

    void insert(int shapeIndex) {
        Shape* newShape = NULL;

        if (shapeIndex == 1) newShape = new Line();
        else if (shapeIndex == 2) newShape = new Rect();
        else if (shapeIndex == 3) newShape = new Circle();

        if (newShape != NULL) {
            p[size++] = newShape; // 배열에 추가
        }
    }

    void remove(int index) {
        delete p[index];

        for (int i = index; i < size - 1; ++i) {
            p[i] = p[i + 1];
        }

        p[size - 1] = NULL; // 마지막 자리를 초기화
        --size;
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            p[i]->get();
            cout << endl;
        }
    }
};

