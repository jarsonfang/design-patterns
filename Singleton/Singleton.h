#pragma once
#include <stdlib.h>
#include <pthread.h>

template <typename T> class Singleton
{
public:
    static T &instance()
    {
        init();
        return *_instance;
    }

private:
    static void init()
    {
        if (_instance == 0)
        {
            pthread_mutex_lock(&_mutex);

            if (_instance == 0)
            {
                _instance = new T;
                atexit(destroy);    //程序结束时调用注册的函数
            }

            pthread_mutex_unlock(&_mutex);
        }
    }

    static void destroy()
    {
        delete _instance;
    }

    Singleton();
    ~Singleton();

    Singleton(const Singleton &other);
    Singleton &operator=(const Singleton &other);

    static T * volatile _instance;
    static pthread_mutex_t _mutex;
};

template <typename T>
T * volatile Singleton <T>::_instance = 0;

template <typename T>
pthread_mutex_t Singleton<T>::_mutex = PTHREAD_MUTEX_INITIALIZER;
