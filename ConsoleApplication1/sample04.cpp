/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11271972586
�L�[�{�[�h���畡���̎��������͂���܂��B
�����̂����A-10.0�ȏ�10.0�ȉ��̎����݂̂�
���͂��ꂽ���ɂT�����ǂݍ��݁A
�����̕��ϒl��\������v���O�������쐬���܂��傤�B
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>
auto input()
{
	constexpr size_t n = 5;
	std::vector<double> a;
	a.reserve(n);//�̈��\�ߊm��
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
			throw std::runtime_error("���ُ͈킪�������܂����B");
	}
}
#include <assert.h>
int main()
{
	const auto a = input();
	const auto sum = std::accumulate(a.begin(), a.end(), 0.);
	//assert �͎��s���̌��� (Debug�łɌ���)
	//assert�����̏�ʂœK���Ă���Ƃ������̂ł͂Ȃ��i�Ă������A�K���Ă��Ȃ��j
	assert(a.size() > 0);
	std::cout << "���ϒl: " << sum / a.size() << '\n';
}
