#include <array>
#include <iostream>
#include <stdexcept> //例外
#include <stdlib.h> //C言語のヘッダファイル

std::array<int, 3>   input()
{
	std::array<int, 3> retval;
	for (int i = 0;    ;) {
		int n;
		if (std::cin >> n) {
			//成功
			retval[i] = n;
			if (++i == 3) {
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
		for (int i = 0; i < 3; ++i) {
			std::cout << x[i] << '\n';
		}
		return EXIT_SUCCESS;
	}
	catch (const std::exception& e) {
		//エラーメッセージの出力
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
