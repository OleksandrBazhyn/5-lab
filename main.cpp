// ����� ��������� �-24		������ 20		����������� ������ �5
// 
// No.20
// �� ���������� : A1, A2, A3, A4, B1, B2, C
// ������� ���������� : A1, A3
// ��������� : B1(A1, A2), C(B1, B2)
// 
// ����������� ��������� C ����� ����������� �� C(A1, A2, B2)

#include <iostream>
#include <future>
#include <syncstream>

std::osyncstream synced_out(std::cout);

void slow(const std::string& name)
{
	synced_out << "Slow computation " << name << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(7));
}

void quick(const std::string& name)
{
	synced_out << "Quick computation " << name << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void work()
{
	std::future<void> futureA1 = std::async(std::launch::async, slow, "A1");
	std::future<void> futureA2 = std::async(std::launch::async, quick, "A2");
	std::future<void> futureA3 = std::async(std::launch::async, slow, "A3");
	std::future<void> futureA4 = std::async(std::launch::async, quick, "A4");

	futureA1.wait();
	futureA2.wait();
	std::future<void> futureB1 = std::async(std::launch::deferred, quick, "B1");
	std::future<void> futureB2 = std::async(std::launch::deferred, quick, "B2");

	futureB1.wait();
	futureB2.wait();
	std::future<void> futureC = std::async(std::launch::deferred, quick, "C");

	futureC.get();

	synced_out << "\nWork done!\n";
}

int main()
{
	auto start = std::chrono::steady_clock::now();
	work();
	auto end = std::chrono::steady_clock::now();

	synced_out << "Total time: " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " seconds" << '\n';


	return 0;
}