#include <array>
#include <iostream>
#include <stdexcept> //例外
#include <stdlib.h> //C言語のヘッダファイル
#include <numeric> //accumulate

auto input()
{
	std::array<int, 5> retval;
	for (size_t i = 0; ;) {
		int n;
		if (std::cin >> n) {
			//成功
			retval[i] = n;
			if (++i == retval.size()) {
				//終わり
				return retval;
			}
			else
				continue;//for 文を更に続ける
		}
		else
			throw std::runtime_error("入力異常が発生しました。");
	}
}
int main()
{
	try {
		const auto x = input();
		std::cout << "入力されたデータは以下の通りです。\n";
		for (size_t i = 0; i < x.size(); ++i) {
			std::cout << x[i] << '\n';
		}
		std::cout << "合計: " << std::accumulate(x.begin(), x.end(), 0) << '\n';
		return EXIT_SUCCESS;
	}
	catch (const std::exception& e) {
		//エラーメッセージの出力
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
