#include "Vector.h"

int main() {
	try {
		std::cout << "---------------------------" << std::endl;
		std::cout << "    Integer Vector" << std::endl;
		std::cout << std::endl;
		Vector<int> int_V(5, 1, 10);
		std::cout << "Random Vector: " << int_V << std::endl;
		std::cout << "Size: " << int_V.sizeV() << std::endl;
		std::cout << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "     Float Vector" << std::endl;
		std::cout << std::endl;
		Vector<float> float_V(5, 0.0, 10.0);
		std::cout << "Random Vector: " << float_V << std::endl;
		std::cout << "Size: " << float_V.sizeV() << std::endl;
		std::cout << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "  Complex Integer Vector" << std::endl;
		std::cout << std::endl;
		using ComplexInt = std::complex<int>;
		Vector<ComplexInt> complex_int_V(3, ComplexInt(3, 3));
		std::cout << "Complex Vector: " << complex_int_V << std::endl;
		std::cout << "Size: " << complex_int_V.sizeV() << std::endl;
		std::cout << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "        OPERATIONS" << std::endl;
		std::cout << std::endl;
		Vector<float> first_V(3, 1, 10);
		Vector<float> second_V(3, 1, 10);
		std::cout << "First Vector: " << first_V << std::endl;
		std::cout << "Second Vector: " << second_V << std::endl;
		std::cout << std::endl;
		std::cout << "sum: " << first_V + second_V << std::endl;
		std::cout << "Difference: " << first_V - second_V << std::endl;
		std::cout << "Composition: " << first_V * second_V << std::endl;
		std::cout << std::endl;
		std::cout << "First Vector * 5: " << first_V * 5 << std::endl;
		std::cout << "Second Vector / 5: " << second_V / 5 << std::endl;
		std::cout << std::endl;
		std::cout << "First Vector length: " << first_V.length() << std::endl;
		std::cout << "First Vector (unit): " << first_V.unit_V() << std::endl;
		std::cout << std::endl;
		std::cout << "Second Vector length: " << second_V.length() << std::endl;
		std::cout << "Second Vector (unit): " << second_V.unit_V() << std::endl;
		std::cout << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "         TASK - 4" << std::endl;
		std::cout << std::endl;
		std::cout << "2D" << std::endl;
		Vector<float> Vec1(2, 1, 10);
		std::cout << "Vector: " << Vec1 << std::endl;
		std::cout << "Unit Perpendicular Vector: " << Vec1.perpendicular_V().unit_V() << std::endl;
		std::cout << std::endl;
		std::cout << "3D" << std::endl;
		Vector<float> Vec2(3, 1, 10);
		std::cout << "Vector: " << Vec2 << std::endl;
		std::cout << "Unit Perpendicular Vector: " << Vec2.perpendicular_V().unit_V() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}