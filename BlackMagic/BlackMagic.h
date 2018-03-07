#pragma once

#include "ComponentCounter.h"

namespace ComponentType {
	unsigned count() { return _ComponentCounter::getCounter(); }
};

#define _IMPL_CONCAT(x, y) x##y
#define _MACRO_CONCAT(x, y) _IMPL_CONCAT(x, y)
#define _INC_COMPONENT_COUNTER(unique_id) namespace {_ComponentCounter _MACRO_CONCAT(counter, unique_id);}
#define _ADD_COMPONENT_NAME(id, value) namespace ComponentType { const unsigned int id = value;}
#define _GET_COMPONENT_NAME(id) ComponentType::id;
#define COMPONENT_COUNT _ComponentCounter::getCounter();
#define COMPONENT(x) _INC_COMPONENT_COUNTER(x) \
			 _ADD_COMPONENT_NAME(x, COMPONENT_COUNT) \
			 class x : public Component {\
	         public: \
				 virtual unsigned getType() override { return _GET_COMPONENT_NAME(x); } \
				 static unsigned getId() { return _GET_COMPONENT_NAME(x); }
				
#define END_COMPONENT };
