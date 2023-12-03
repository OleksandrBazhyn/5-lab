// Бажин Олександр К-24		варіант 20		Лабораторна робота №5
// 
// No.20
// Усі обчислення : A1, A2, A3, A4, B1, B2, C
// “Повільні” обчислення : A1, A3
// Залежності : B1(A1, A2), C(B1, B2)
// 
// Транзитивно залежність C можна представити як C(A1, A2, B2)

#include <iostream>
#include <future>
#include <syncstream>

void slow(const std::string& name)
{

}

void quick(const std::string& name)
{

}

void work()
{
	std::osyncstream synced_out(std::cout);

	synced_out << "\nWork done!\n";
}

int main()
{
	work();

	return 0;
}