#include <stdio.h>
#include <string.h>
#include "Application.h"

void *routine(void *arg)
{
    Application::instance().run();
    return (void *)0;
}

int main(void)
{
    int ret;
    pthread_t tid;

    if ((ret = pthread_create(&tid, NULL, routine, NULL)) != 0)
    {
        fprintf(stderr, "pthread create: %s\n", strerror(ret));
        exit(EXIT_FAILURE);
    }

    Application::instance().run();
    pthread_join(tid, NULL);

    return 0;
}
