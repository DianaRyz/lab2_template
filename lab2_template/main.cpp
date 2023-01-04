#include "Set_T.h"
std::ostream& operator<<(std::ostream& out, const std::pair<int, double>& p)
{
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}
int main() {
	try {
		Set<int> set1, set11;
		set1 += 6;
		set1 += 7;
		set1 += 8;
		set1 += 3;
		set1 += 4; 
		/*set11 += 2;
		set11 += 3;
		set11 += 7;
		set11 += 8;*/
		set11 = set1 + 5;
		set11 = set1 - 6;
		set11 -= 7;
		std::cout << "set 1: " << set1 << std::endl;
		std::cout << "set 11: " << set11 << std::endl;
		std::cout << "+: " << set1 + set11 << std::endl;
		std::cout << "-: " << set1 - set11 << std::endl;
		std::cout << "intersection: " << set1.intersection(set11) << std::endl;
		std::cout << "task: " << set1.check_count(set11) << std::endl;
		std::cout << "equality: " << (set1 == set11) << std::endl;
		std::cout << "not equality: " << (set1 != set11) << std::endl;
		std::cout << "index: " << set1[1] << std::endl;
		std::cout << std::endl;

		Set<float> set2, set22;
		set2 += 6.4;
		set2 += 7.5;
		set2 += 8.9;
		set2 += 1.1;
		set2 += 4.9;
		/*set22 += 3.3;
		set22 += 6.4;
		set22 += 7.7;*/
		set22 = set2 + 4.4;
		set22 = set2 - 6.4;
		set22 -= 7.5;
		std::cout << "set 2: " << set2 << std::endl;
		std::cout << "set 22: " << set22 << std::endl;
		std::cout << "+: " << set2 + set22 << std::endl;
		std::cout << "-: " << set2 - set22 << std::endl;
		std::cout << "intersection: " << set2.intersection(set22) << std::endl;
		std::cout << "task: " << set22.check_count(set2) << std::endl;
		std::cout << "equality: " << (set2 == set22) << std::endl;
		std::cout << "not equality: " << (set2 != set22) << std::endl;
		std::cout << "index: " << set2[1] << std::endl;
		std::cout << std::endl;

		Set<std::string> set3, set33;
		set3 += "mom";
		set3 += "nik";
		set3 += "kot";
		set3 += "nen";
		set3 += "pol";
		/*set33 += "m";
		set33 += "rt";
		set33 += "w";*/
		set33 = set3 + "ret";
		set33 = set3 - "mom";
		set33 -= "nik";
		set33 += "you";
		std::cout << "set 3: " << set3 << std::endl;
		std::cout << "set 33: " << set33 << std::endl;
		std::cout << "+: " << set3 + set33 << std::endl;
		std::cout << "-: " << set3 - set33 << std::endl;
		std::cout << "intersection: " << set3.intersection(set33) << std::endl;
		std::cout << "task: " << set3.check_count(set33) << std::endl;
		std::cout << "equality: " << (set3 == set33) << std::endl;
		std::cout << "not equality: " << (set3 != set33) << std::endl;
		std::cout << "index: " << set3[1] << std::endl;
		std::cout << std::endl;

		Set<std::pair<int, double>> set4, set44;
		set4 += {1, 3.2};
		set4 += {2, 5.7};
		set4 += {3, 4.4};
		set4 += {8, 9.0};
		set4 += {10, 3.5};
		/*set44 += {1, 3.3};
		set44 += {1, 3.2};
		set44 += {2, 5.6};*/
		set44 = set4 + std::pair<int, double>(1, 4.4);
		set44 = set4 - std::pair<int, double>(1, 3.2);
		set44 -= {2, 5.7};
		std::cout << "set 4: " << set4 << std::endl;
		std::cout << "set 44: " << set44 << std::endl;
		std::cout << "+: " << set4 + set44 << std::endl;
		std::cout << "-: " << set4 - set44 << std::endl;
		std::cout << "intersection: " << set4.intersection(set44) << std::endl;
		std::cout << "task: " << set44.check_count(set4) << std::endl;
		std::cout << "equality: " << (set4 == set44) << std::endl;
		std::cout << "not equality: " << (set4 != set44) << std::endl;
		std::cout << "index: " << set4[1] << std::endl;
		std::cout << std::endl;

		//пример с равенством
		Set<std::pair<int, double>> p, pp;
		p += {1, 3.2};
		p += {2, 5.7};
		p += {3, 4.4};
		pp = p + std::pair<int, double>(1, 4.4);
		p += {1, 4.4};
		std::cout << "p: " << p << std::endl;
		std::cout << "pp: " << pp << std::endl;
		std::cout << "equality: " << (p == pp) << std::endl;
		std::cout << "not equality: " << (p != pp) << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

}