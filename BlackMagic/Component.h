#pragma once

#include "ComponentCounter.h"

class Component {
public:
	virtual unsigned getType() = 0;
	static unsigned count() { return _ComponentCounter::getCounter(); }
};

#include "BlackMagic.h"