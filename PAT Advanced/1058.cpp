#include <cstdio>

struct form{
    int Galleon, Sickle, Knut;
};

int main(void){
    form A, B, C;
    
    scanf("%d.%d.%d %d.%d.%d", &A.Galleon, &A.Sickle, &A.Knut, 
                                &B.Galleon, &B.Sickle, &B.Knut);
    
    C.Knut = A.Knut + B.Knut;
    C.Sickle = A.Sickle + B.Sickle + C.Knut/29;
    C.Knut = C.Knut % 29;
    C.Galleon = A.Galleon + B.Galleon + C.Sickle/17;
    C.Sickle = C.Sickle % 17;
    
    printf("%d.%d.%d", C.Galleon, C.Sickle, C.Knut);
    
    return 0;
}
