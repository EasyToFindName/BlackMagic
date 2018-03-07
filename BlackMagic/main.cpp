#include "Reactor.h"
#include "Collider.h"

#include <iostream>

struct S {
	int a;
};

COMPONENT_DERIVED_FROM_CLASS(T1, S)
public:

private:

END_COMPONENT

COMPONENT_DERIVED_FROM_COMPONENT(INT, T1)

public:

private:

END_COMPONENT


template<typename TComponent>
void testStatic() {
	if(TComponent::getId() == ComponentType::Collider) {
		std::cout << "I'm collider\n";
	}

	else if(TComponent::getId() == ComponentType::Reactor) {
		std::cout << "I'm reactor\n";
	}

	else if(TComponent::getId() == ComponentType::T1) {
		std::cout << "I'm T1\n";
	}

	else if(TComponent::getId()== ComponentType::INT) {
		std::cout <<"I'm INT\n";
	}
}

int main() {
	Collider c;
	Reactor r;
	T1 t;
	INT i;
	Component* a[] = { &c, &r, &c, &t, &i};

	for(int i = 0; i < sizeof(a) / sizeof(size_t); ++i) {
		if(a[i]->getType() == ComponentType::Collider) {
			std::cout << "I'm collider\n";
		}
		else if(a[i]->getType() == ComponentType::Reactor) {
			std::cout << "I'm reactor\n";
		}

		else if(a[i]->getType() == ComponentType::T1) {
			std::cout << "I'm T1\n";
		}

		else if(a[i]->getType() == ComponentType::INT) {
			std::cout <<"I'm INT\n";
		}

	}
	std::cout << "Total amount of component types: " << ComponentType::count() << "\n";


	testStatic<INT>();
	testStatic<T1>();
	testStatic<Collider>();
	testStatic<Reactor>();

	// inheritance tests

	T1 baseComponent;
	baseComponent.a = 0;

	INT derivedComponent;
	derivedComponent.a = 1;

	std::cout << baseComponent.a << " " << derivedComponent.a << "\n";
	
	std::cin.get();
	return 0;
}