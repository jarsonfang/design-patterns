#pragma once
#include <iostream>
#include "Singleton.h"

using namespace std;

class ApplicationImpl
{
    public:
        ApplicationImpl()
        {
            cout << "ApplicationImpl ..." << endl;
        }

        ~ApplicationImpl()
        {
            cout << "~ApplicationImpl ..." << endl;
        }

        void run()
        {
            cout << "run ..." << endl;
        }
};

typedef Singleton <ApplicationImpl> Application;
