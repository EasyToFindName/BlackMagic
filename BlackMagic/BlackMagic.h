#pragma once

class ComponentCounter {
	static unsigned int m_count;
public:
	ComponentCounter() {
		++m_count;
	}

	static unsigned int getCounter() { return m_count; }

};

unsigned int ComponentCounter::m_count = 0;

#define _IMPL_CONCAT(x, y) x##y
#define _MACRO_CONCAT(x, y) _IMPL_CONCAT(x, y)
#define _INC_COMPONENT_COUNTER(unique_id) namespace {ComponentCounter _MACRO_CONCAT(counter, unique_id);}
#define _COMPONENT_NAME(x) _MACRO_CONCAT(COMPONENT_, x)
#define COMPONENT_COUNT ComponentCounter::getCounter();
#define COMPONENT(x) _INC_COMPONENT_COUNTER(_COMPONENT_NAME(x)) \
			 const unsigned int _COMPONENT_NAME(x) = COMPONENT_COUNT;\
	         class x : public Component {\
	         public: \
				 virtual unsigned getType() override { return _COMPONENT_NAME(x); }

#define END_COMPONENT };