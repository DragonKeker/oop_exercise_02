#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "logika.h"

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	int k;
	logika obj1;
	logika obj2;
	"Vvedite dannie"_out;
	obj1.read(std::cin, obj1);
	obj2.read(std::cin, obj2);
	(obj1&obj2).write(std::cout);
	(obj1|obj2).write(std::cout);
	(obj1^obj2).write(std::cout);
	(~obj1).write(std::cout);
	"Vvedite : k "_out;
	scanf_s("%d", &k);
	(obj1<<k).write(std::cout);
	"Vvedite : k "_out;
	scanf_s("%d", &k);
	(obj1>>k).write(std::cout);
	"Vsego ed v 1 str:"_out;
	std::cout  << (obj1._count1()) << "\n";
	obj1._sravnenie(obj2);
	if (obj1._vkluch(obj2))
		 "Vkl"_out;
	else
		"Ne vkl"_out;
}
