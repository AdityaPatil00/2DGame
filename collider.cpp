#include <iostream>
#include "collider.h"
Collider::Collider() : strategy(new MidPointCollisionStrategy){}
Collider::~Collider(){
  delete strategy;
}
bool Collider::collidedWith(const Bullet c,const Drawable* d) const  {
  return strategy->execute(c, *d);
}
bool Collider::collidedWithPlayer(const Player* c,const Drawable* d) const  {
  return strategy->execute(*c, *d);
}
Collider& Collider::getInstance(){
  static Collider collider;
  return collider;
}
