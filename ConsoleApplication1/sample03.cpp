/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11271972586
キーボードから複数の実数が入力されます。
これらのうち、-10.0以上10.0以下の実数のみを
入力された順に５個だけ読み込み、
それらの平均値を表示するプログラムを作成しましょう。
*/
#include <iostream>
#include <array>
#include <stdexcept>
#include <numeric>
auto input()
{
	std::array<double, 5> a;
	for (size_t i = 0;;) {
		if (std::cin >> a[i]) {
			if (++i == a.size())
				return a;
			else
				continue;
		}
		else
			throw std::runtime_error("入力異常が発生しました。");
	}
}
int main()
{
	const auto a = input();
	const auto sum = std::accumulate(a.begin(), a.end(), 0.);
	static_assert(a.size() > 0, "size cannot be zero");
	std::cout << "平均値: " << sum / a.size() << '\n';
}