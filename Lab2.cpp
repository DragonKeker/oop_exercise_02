#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "logika.h"

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	int k;
	logika obj1;
	logika obj2;
	logika obj3;
	"Введите данные"_out;
	std::cin >> obj1;
	std::cin >> obj2;
	std::cout << (obj1&obj2);
	std::cout << (obj1|obj2);
	std::cout << (obj1^obj2);
	std::cout << (~obj1);
	"Введите : k "_out;
	scanf_s("%d", &k);
	std::cout << (obj1<<k);
	"Введите : k "_out;
	scanf_s("%d", &k);
	std::cout << (obj1>>k);
	"Всего едениц в первой строке:"_out;
	std::cout  << (obj1._count1()) << "\n";
	obj1._sravnenie(obj2);
	if (obj1._vkluch(obj2))
		 "Включает"_out;
	else
		"Не включает"_out;

	obj3.field1 = 101010110_l;
	obj3.field2 = 101010111_l;
	std::cout << obj3 << std::endl;
}
