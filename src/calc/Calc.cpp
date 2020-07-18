#include <iostream>
using namespace std;

#include "pg/Adder.h"
#include "pg/Terminal.h"

int main(int argc, char **argv) {
	pg::Terminal t1(1.0);
	pg::Terminal t2(2.0);
	pg::Terminal t3(3.0);
	pg::Adder a1(t1,t2);
	pg::Adder a2(a1,t3);
	cout << "Result: " << a2.execute() << endl;
	return 0;
}
