//

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <functional>

#include <time.h>

using namespace std;

int main()
{
	// Fibonacci number
	// 1. using std::function, #include <functional>
	std::function<int(int)> Fiba = [&Fiba](int n) { return n < 2 ? n : Fiba(n - 1) + Fiba(n - 2); };

	cout << Fiba(10) << endl;

	// 2. Pure lamda
	auto Fibn = [](int n)
	{
		auto Fibm = [](int m, auto& Fibm_ref)
		{
			if (m < 2) return m;
			return Fibm_ref(m - 1, Fibm_ref) + Fibm_ref(m - 2, Fibm_ref);
		};

		return Fibm(n, Fibm);
	};

	cout << Fibn(10) << endl;

	return 0;
}
