#ifndef D_LOGIKA_H_
#define D_LOGIKA_H_ 1
#include <iostream>

struct logika {

	logika operator&(const logika &obj2)const;
	logika operator|(const logika &obj2)const;
	logika operator^(const logika &obj2)const;
	logika operator~()const;
	logika operator<<(const int k);
	logika operator>>(const int k);
	friend std::ostream& operator<< (std::ostream& out, const logika& obj);
	friend std::istream& operator>> (std::istream& in, logika& obj);
	int _count1()const;
	void _sravnenie( logika& obj2);
	bool operator>(const logika obj2)const;
	bool operator<(const logika obj2)const;
	bool operator==(const logika& obj2)const;
	bool _vkluch(const logika& obj2)const;

public:
	uint64_t field1;
	uint64_t field2;
	/*static void read(std::istream&, logika&);
	void  write(std::ostream&);*/
};
	void operator ""_out(const char* str, size_t size);
	logika operator "" _l(const char* str);

#endif // D_LOGIKA_H_#pragma once
