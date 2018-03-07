#include "Reactor.h"
#include "Collider.h"

#include <iostream>

COMPONENT(T1)
public:

private:
END_COMPONENT

COMPONENT(T2)
public:
private:
END_COMPONENT

int main() {
	Collider c;
	Reactor r;
	T1 t;
	Component* a[] = { &c, &r, &c, &t};

	for(int i = 0; i < sizeof(a) / sizeof(size_t); ++i) {
		if(a[i]->getType() == COMPONENT_Collider) {
			std::cout << "I'm collider\n";
		}
		else if(a[i]->getType() == COMPONENT_Reactor) {
			std::cout << "I'm reactor\n";
		}

		else if(a[i]->getType() == COMPONENT_T1) {
			std::cout << "I'm T1\n";
		}

	}

	std::cout << "Total amount of component types: " << COMPONENT_COUNT;

	std::cin.get();
	return 0;
}