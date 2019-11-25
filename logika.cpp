#include "logika.h"
#include <bitset>
#include <assert.h>
/* void logika::read(std::istream& is, logika& obj) {
	 is >> obj.field1 >> obj.field2;
 }
 void logika::write(std::ostream& os) {
	 os << field1 << " " << field2 << "\n";
 }*/

logika logika:: operator&(const logika& obj2)const
{
	logika result;
	result.field1 = field1 & obj2.field1;
	result.field2 = field2 & obj2.field2;
	return(result);
};
logika logika::operator|(const logika& obj2)const
{
	logika result;
	result.field1 = this->field1 | obj2.field1;
	result.field2 = this->field2 | obj2.field2;
	return(result);
};
logika logika::operator^(const logika& obj2)const
{
	logika result;
	result.field1 = this->field1 ^ obj2.field1;
	result.field2 = this->field2 ^ obj2.field2;
	return(result);
};
logika logika::operator~()const
{
	logika result;
	result.field1 = ~field1;
	result.field2 = ~field2;
	return(result);
};
logika logika::operator<<(int k)
{
	logika result;
	uint64_t a = field1, b = field2;
	unsigned long long pow63 = 1;
	for (int i = 0; i < 63; i++) {
		pow63 *= 2;
	}

	for (int i = 0; i < k; i++) {
		a = a << 1;
		if (b >= pow63) {
			a += 1;
		}
		b = b << 1;

	}
	result.field1 = a;
	result.field2 = b;
	return (result);
};
logika logika::operator>>(int k)
{
	logika result;
	uint64_t a = field1, b = field2;

	unsigned long long pow63 = 1;
	for (int i = 0; i < 63; i++) {
		pow63 *= 2;
	}
	for (int i = 0; i < k; i++) {
		b = b >> 1;
		if (a % 2 == 1) {
			b += pow63;
		}
		a = a >> 1;
	}

	result.field1 = a;
	result.field2 = b;
	return (result);
};
int logika::_count1()const
{
	uint64_t a = field1;
	uint64_t b = field2;
	int t = 0;
	int sum = 0;
	while (a != 0) {
		t += 1; a &= a - 1;
	}
	sum = sum + t;

	t = 0;
	while (b != 0) {
		t += 1; b &= b - 1;
	}
	sum = sum + t;

	return(sum);

};

bool logika::operator>(const logika obj2)const
{
	if (this->_count1() > obj2._count1())
	{
		
		return(1);
	}
	else
		return(0);
};

bool logika::operator<(const logika obj2)const
{
	if (this->_count1() < obj2._count1())
	{
		
		return(1);
	}
	else
		return(0);
};

bool logika::operator==(const logika& obj2)const
{
	if (this->_count1() == obj2._count1())
	{
		
		return(1);
	}
	else
		return(0);
};

void logika::_sravnenie( logika& obj2)
{

	if (*this>(obj2))
	{
		std::cout<< "Количество единиц в первой строке больше" << std::endl;
	}
	else if (*this<(obj2))
	{
		std::cout << "Количество единиц во второй строке больше"<< std::endl;
	}
	else 
	{
		std::cout<< "Количество единиц в строках равно" << std::endl;
	}
}; 

bool logika::_vkluch(const logika& obj2)const {
	
	if ((obj2.field1 == this->operator&(obj2).field1) && (obj2.field2 == this->operator&(obj2).field2))
		return (1);
	else
		return 0;
};

void operator ""_out(const char* str, size_t size) {   
	std::cout << str << std::endl;
}

unsigned long long operator ""_l(const char* str)
{
	unsigned long long result = 0;
	size_t size = strlen(str);

	for (size_t i = 0; i < size; ++i)
	{
		assert(str[i] == '1' || str[i] == '0');
		result |= (str[i] - '0') << (size - i - 1);
	}

	return result;
}

std::istream& operator>> (std::istream& in, logika& obj) {
	in >> obj.field1 >> obj.field2;
	return in;
}

std::ostream& operator<< (std::ostream& out, const logika& obj) {
	out << obj.field1 << " " << obj.field2 << "\n";
	return out;
}
