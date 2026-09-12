#include <stdio.h>
#include <math.h>

int main()
{
    int _in, _inf1, _inf2,_inf3, _2a, _2b, _2f, _f2, _1a, _1b, _1f, rez;
    printf("Tchislo: ");
    scanf("%d", &_in);
    _inf1 = _in/1000;
    _inf2 = _in%100;
    _inf3 = _in/100%10;
    _2a = _inf2/10;
    _2b = _inf2%10;
    _2f = _2b * 10 + _2a;
    _1a = _inf1/10;
    _1b = _inf1%10;
    _1f = _1b * 10 + _1a;
    _f2 = _2f*1000 + _inf3*100 + _1f;
    rez = _in == _f2;
    printf("Resultat: %d\n", rez);

    int _int1, _int2;
    printf("Tchislo 1: ");
    scanf("%d", &_int1);
    printf("Tchislo 2: ");
    scanf("%d", &_int2);
    printf("Umnozenie: %d\n", _int1*_int2);
    printf("Delenie: %d\n", _int1/_int2);
    printf("Slozhenie: %d\n", _int1+_int2);
    printf("Otnimanie: %d\n", _int1-_int2);
    printf("Ostatok: %d\n", _int1%_int2);

    int _int4, a, b, c, d;
    float rezult;
    printf("Tchislo: ");
    scanf("%d", &_int4);
    a = _int4/1000;
    b = _int4/100%10;
    c = _int4/10%10;
    d = _int4%10;
    rezult = cbrt(a*b*c*d);
    printf("Rezultat: %.3f\n", rezult);

    int s1, s2, s3, pr, sq, p2;
    printf("Storona 1: ");
    scanf("%d", &s1);
    printf("Storona 2: ");
    scanf("%d", &s2);
    printf("Storona 3: ");
    scanf("%d", &s3);
    pr = s1+s2+s3;
    p2 = pr/2;
    sq = sqrt(p2*(p2-s1)*(p2-s2)*(p2-s3));
    printf("Perimetr: \n");
    printf("Ploshad: %d", sq);

    return 0;
}
