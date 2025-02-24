#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

double hipotenusa(double a, double b){
    double hip;
    hip = sqrt(a * a + b * b);
    return hip;
}

int main(){
    double a,b,c,d;
    printf("Digite as constantes a, b, c \n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    d = hipotenusa(hipotenusa(a,b), c);
    printf("%f\n", d);
    return 0;
}
