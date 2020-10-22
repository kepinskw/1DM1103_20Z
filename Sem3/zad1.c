#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    printf("Wartość %s do kwadratu to %.2f", argv[1], atof(argv[1]) * atof(argv[1]));
}