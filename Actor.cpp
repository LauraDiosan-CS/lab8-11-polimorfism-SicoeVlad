#include "Actor.h"

Actor::Actor()
{
	this->numeActor = " ";
}

Actor::Actor(string n)
{
	this->numeActor = n;
}

Actor::Actor(const Actor& a)
{
	this->numeActor = a.numeActor;
}

string Actor::getNume()
{
	return this->numeActor;
}

void Actor::setNume(string n)
{
	this->numeActor = n;
}

Actor& Actor::operator=(const Actor& a)
{
	if (this != &a)
	{
		this->setNume(a.numeActor);
	}
	return *this;
}

int Actor::operator==(const Actor& a)
{
	return (this->numeActor == a.numeActor);
}



Actor::~Actor()
{

}

