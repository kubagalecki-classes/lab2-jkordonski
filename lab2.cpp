#pragma once

#include "Resource.hpp"
#include <iostream>
using namespace std;

class ResourceManager
{
    Resource* p;

public:
    ResourceManager(Resource* ptr = NULL)
    {
        cout << "Resource acquired!" << endl;
        p = ptr;
    }

    ~ResourceManager()
    {
        cout << "Resource deleted!" << endl;
        delete (p);
    }
};
