/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11271972586
キーボードから複数の実数が入力されます。
これらのうち、-10.0以上10.0以下の実数のみを
入力された順に５個だけ読み込み、
それらの平均値を表示するプログラムを作成しましょう。
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>
auto input()
{
	constexpr size_t n = 5;
	std::vector<double> a;
	a.reserve(n);//領域を予め確保
	for (;;) {
		double value;
		if (std::cin >> value) {
			a.push_back(value);
			if (a.size() == n)
				return a;
			else
				continue;
		}
		else
			throw std::runtime_error("入力異常が発生しました。");
	}
}
#include <assert.h>
int main()
{
	const auto a = input();
	const auto sum = std::accumulate(a.begin(), a.end(), 0.);
	//assert は実行時の検証 (Debug版に限る)
	//assertがこの場面で適しているというものではない（ていうか、適していない）
	assert(a.size() > 0);
	std::cout << "平均値: " << sum / a.size() << '\n';
}
