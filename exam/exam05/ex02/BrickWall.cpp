#include "BrickWall.hpp"

BrickWall::BrickWall() { setType("Inconspicuous Red-brick Wall"); }
BrickWall::~BrickWall() {}
ATarget	*BrickWall::clone() const { return (new BrickWall(*this)); }
