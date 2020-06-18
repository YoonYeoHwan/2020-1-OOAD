#include "Mask.h"

using namespace std;

int Mask::getMask() {
    FILE *file = fopen("mask.txt", "r");
    while(1) {
        fscanf(file, "%d", &numOfMask);
        if(feof(file)) break;
    }
    fclose(file);
    return numOfMask;
}

void Mask::setMask() {
    FILE *file = fopen("mask.txt", "r");
    fscanf(file, "%d", &numOfMask);
    numOfMask += 10;
    fclose(file);

    file = fopen("mask.txt", "w");
    string strtmp = to_string(numOfMask);
    const char* ch = strtmp.c_str();
    fputs(ch, file);
    fclose(file);
    
}