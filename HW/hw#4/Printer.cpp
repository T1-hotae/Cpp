#include<iostream>
#include<string>

using namespace std;

class Printer {
protected:
	string model, manufacturer;
	int printedCount, availableCount;
public:
	Printer(string m, string manuf, int acount) {
		this->model = m, this->manufacturer = manuf,
			 this->availableCount = acount, this->printedCount = 0;
	}

	virtual void print(int pages) {
		if (availableCount < pages) {
			cout << "종이가 부족합니다." << endl;
			return;
		}
		availableCount -= pages;
		printedCount += pages;
	};
	virtual void show() {
		cout << model << ", " << manufacturer << ", 남은 종이 " <<
			availableCount << "장 ";
	}
};


class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string m, string manuf, int acount, int ink)
		: Printer(m, manuf, acount) {
		availableInk = ink;
	}
	void printInkjet(int pages) {
		print(pages);
		if (availableInk < pages) {
			cout << "잉크가 부족합니다." << endl;
			return;
		}
		availableInk -= pages;
	}
	void showInk() {
		show();
		cout << ", 남은 잉크 " << availableInk << endl;
	}
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string m, string manuf, int acount, int toner)
		: Printer(m, manuf, acount) {
		availableToner = toner;
	}
	void printLaser(int pages) {
		print(pages);
		if (availableToner < pages) {
			cout << "토너가 부족합니다." << endl;
			return;
		}
		availableToner -= pages;
	}
	void showToner() {
		show();
		cout << ", 남은 토너 " << availableToner << endl;
	}
};

int main() {
	InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
	LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

	int printerType, pages;
	char cont;

	cout << "현재 작동 중인 2 대의 프린터는 아래와 같다." << endl;
	cout << "잉크젯 : ";
	inkjet.showInk();
	cout << "레이저 :";
	laser.showToner();
	cout << endl;

	do {
		cout << "프린터 (1: 잉크젯, 2: 레이저)와 매수 입력>> ";
		cin >> printerType >> pages;

		cout << "프린트 하였습니다."<<endl;

		if (printerType == 1) {
			inkjet.printInkjet(pages);
			inkjet.showInk();
			laser.showToner();
		}
		else if (printerType == 2) {
			laser.printLaser(pages);
			inkjet.showInk();
			laser.showToner();
		}

		cout << "계속 프린트 하시겠습니까?(y/n)>> ";
		cin >> cont;
		cout << endl;

	} while (cont == 'y');

	return 0;
}
