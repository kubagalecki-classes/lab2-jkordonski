#pragma once

#include "Resource.hpp"

class ResourceManager
{
Resource *p;
ResourceManager(Resource *p){p=ptr;}



~ResourceManager(){delete (p)}

double get(){return p.get;};

};
