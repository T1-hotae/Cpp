#pragma once
class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	//Dept(const Dept& dept);
	~Dept();
	int getsize() { return size; }
	void read();
	bool isOver60(int index);
	int countPass();
};
