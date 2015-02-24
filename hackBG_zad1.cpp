#include <iostream>

double fill_tetrahedron (int num)//num - edge length
{
	double num_d = double (num);

	double v = (pow (num_d, 3)) / ((6*sqrt(2))) ;
	
	// /1000 zaradi prevryshtaneto ot sm v litri
	double vLitri = v/1000;
	return vLitri;
}


int main()
{
	std::cout << "Enter edge length : " ;
	int edgeLength = 0;
	std::cin >>edgeLength;
	std::cout<<fill_tetrahedron (edgeLength)<<std::endl;
	//std::cout<< fill_tetrahedron(100)<<std::endl;
}