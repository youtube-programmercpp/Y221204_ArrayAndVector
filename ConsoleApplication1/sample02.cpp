#include <array>
#include <iostream>
#include <stdexcept> //��O
#include <stdlib.h> //C����̃w�b�_�t�@�C��
#include <numeric> //accumulate

auto input()
{
	std::array<int, 5> retval;
	for (size_t i = 0; ;) {
		int n;
		if (std::cin >> n) {
			//����
			retval[i] = n;
			if (++i == retval.size()) {
				//�I���
				return retval;
			}
			else
				continue;//for �����X�ɑ�����
		}
		else
			throw std::runtime_error("���ُ͈킪�������܂����B");
	}
}
int main()
{
	try {
		const auto x = input();
		std::cout << "���͂��ꂽ�f�[�^�͈ȉ��̒ʂ�ł��B\n";
		for (size_t i = 0; i < x.size(); ++i) {
			std::cout << x[i] << '\n';
		}
		std::cout << "���v: " << std::accumulate(x.begin(), x.end(), 0) << '\n';
		return EXIT_SUCCESS;
	}
	catch (const std::exception& e) {
		//�G���[���b�Z�[�W�̏o��
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
