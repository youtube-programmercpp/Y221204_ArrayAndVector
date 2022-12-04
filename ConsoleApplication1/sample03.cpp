/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11271972586
�L�[�{�[�h���畡���̎��������͂���܂��B
�����̂����A-10.0�ȏ�10.0�ȉ��̎����݂̂�
���͂��ꂽ���ɂT�����ǂݍ��݁A
�����̕��ϒl��\������v���O�������쐬���܂��傤�B
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
			throw std::runtime_error("���ُ͈킪�������܂����B");
	}
}
int main()
{
	const auto a = input();
	const auto sum = std::accumulate(a.begin(), a.end(), 0.);
	static_assert(a.size() > 0, "size cannot be zero");
	std::cout << "���ϒl: " << sum / a.size() << '\n';
}