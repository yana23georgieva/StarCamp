#include <stdio.h>
#include <math.h>

// build-in compare operator
int floatCompare1(float a, float b){
    return a == b;
}

// fixed epsilon
int floatCompare2(float a, float b){
    return fabs(a - b) < 1.0e-5f;
}

// adaptive epsilon
int floatCompare3(float a, float b){
    return fabs(a - b) < 1.0e-5f * fmax(fabs(a), fabs(b));
}

int main(void){
    float a = 1000.0f * 0.1f;
    float b = 0.0f;

    double num1 = 1000.0 * 0.1;
    double num2 = 0.0;

    for (int i = 0; i < 1000; i++, b += 0.1f);

    for (int i = 0; i < 1000; i++, num2 += 0.1);

    if (floatCompare1(a, b)){
        printf("== Equals\n");
    } else {
        printf("== Not equals\n");
    }
    if (floatCompare2(a, b)){
        printf("fixed E: Equals\n");
    } else {
        printf("fixed E: Not equals\n");
    }
    if (floatCompare3(a, b)){
        printf("Adaptive E: Equals\n");
    } else {
        printf("Adaptive E: Not equals\n");
    }

    printf("Double:\n");
    if (floatCompare1(num1, num2)){
        printf("== Equals\n");
    } else {
        printf("== Not equals\n");
    }
    if (floatCompare2(num1, num2)){
        printf("fixed E: Equals\n");
    } else {
        printf("fixed E: Not equals\n");
    }
    if (floatCompare3(num1, num2)){
        printf("Adaptive E: Equals\n");
    } else {
        printf("Adaptive E: Not equals\n");
    }

    return 0;
}