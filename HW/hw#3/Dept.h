#pragma once
class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept); //복사 생성자
	~Dept();
	int getsize() { return size; }
	void read();
	bool isOver60(int index);
};
