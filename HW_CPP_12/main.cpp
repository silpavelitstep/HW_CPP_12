#include <iostream>
#include "List.h"
#include "tree.h"
#include "Passport.h"
#include "Student.h"
#include "Round.h"
using namespace std;
int main() {
	RoundInscribeSquare rib;
	rib.setXYSideSquare(2, 4, 10);
	rib.show();
	
	system("pause");
	return 0;
}