
#include "ChaseAlg.h"
#include <set>
#include <vector>
#include "LogicContainer.h"

int main(int argc, char** argv){
	ChaseAlg c;
	std::string fitxer = "../Chase/examples/";
	fitxer += argv[1];
	c.readFile(fitxer);
	int it = c.chase(10);
	c.print();
	//cout << "hola sóc aquí";
	if (it == -1) {
		std::cout << "Fail" << std::endl;
	}
	else {
		std::cout << "Iterations: " << it << std::endl;
	}
}