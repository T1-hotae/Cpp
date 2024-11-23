#include<iostream>
#include<vector>

using namespace std;

#include"Shape.h"
#include"Line.h"
#include"Circle.h"
#include"Rect.h"

int main() {
	cout << "그래픽 에디터입니다." << endl;

	int option;
	int shapeIndex;

	vector<Shape*> v;

	while (1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>  ";
		cin >> option;

		if (option == 1) {
			
			cout << "선:1, 원:2, 사각형:3 >> ";
			cin >> shapeIndex;

			if (shapeIndex == 1)
				v.push_back(new Line());
			else if (shapeIndex == 2)
				v.push_back(new Circle());
			else if (shapeIndex == 3)
				v.push_back(new Rect());
				
			
		}
		else if (option == 2) {
			int index;
			cout << "삭제하고자 하는 도형의 인덱스: ";
			cin >> index;
			delete v[index];
			v.erase(v.begin() + index); // 벡터에서 제거
		}
		else if (option == 3) {
			for (int i = 0; i < v.size(); i++) {
				cout << i << ": ";
				v[i]->paint();
			}
		}
		else if (option == 4) {
			break;
		}
	}
	return 0;
}
