#include<iostream>
#include"GraphicEditor.h"
using namespace std;

int main() {
	cout << "그래픽 에디터입니다." << endl;
	
	GraphicEditor gb;

	int option;
	while (1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>  ";
		cin >> option;

		if (option == 1) {
			int shapeIndex;
			cout << "선:1, 원:2, 사각형:3 >> ";
			cin >> shapeIndex;
			gb.insert(shapeIndex);
		}
		else if (option == 2) {
			int index;
			cout << "삭제하고자 하는 도형의 인덱스: ";
			cin >> index;
			gb.remove(index);
		}
		else if (option == 3) {
			gb.show();
		}
		else if (option == 4) {
			break;
		}
	}
	return 0;
}
