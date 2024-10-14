#include <iostream>

using namespace std;

#include "Dept.h"

Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	scores = new int[size];
	for (int i = 0; i < size; i++) {
		scores[i] = dept.scores[i];
	}
}

void Dept::read() {
	cout << "10개 점수 입력 >>";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {
	return scores[index] >= 60;
}

Dept::~Dept() {
  delete[]scores;
}
