#include "ECS/loadECS.h"

void Entity::addgroup(group mgroup)
{
	groupbitset[mgroup] = true;
	manager.AddtoGroup(this, mgroup);
}