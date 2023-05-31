#include "Dummy.hpp"

Dummy::Dummy() { setType("Target Practice Dummy" ); }
Dummy::~Dummy() {}
ATarget	*Dummy::clone() const { return (new Dummy(*this)); }
