#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[30];
    char sexo;
    int edad;
}stPersona;

int cargaArreglo(int arreglo[], int dim);
void mostrarArreglo(int arreglo[], int validos);

int comprobarCantidadSexo(stPersona persona[], int validos, char sexo);
int cargarPersonas(stPersona persona[], int dim);
void copiarPersonas(stPersona persona1[], stPersona persona2[], int validos, char sexo);
void mostrarPersonas(stPersona persona[] , int validos);
stPersona cargarPersona();

int main()
{
    int dim = 4;
    int validos = 0;
    int validos2 = 0;
    char sexo;
    stPersona personita[dim];

    validos = cargarPersonas(personita, dim);
    mostrarPersonas(personita, dim);

    printf("\n ELIJA EL SEXO: ");
    fflush(stdin);
    scanf("%c", &sexo);
    validos2 = comprobarCantidadSexo(personita, validos, sexo);

    /**          USO DE MALLOC                              **/

    stPersona* personita2 = malloc(sizeof(stPersona)*validos2);
    copiarPersonas(personita,personita2,validos,sexo);
    mostrarPersonas(personita2, validos2);
}

int cargaArreglo(int arreglo[], int dim)
{
    char op = 's';
    int i= 0;
    while(i<dim && op == 's')
    {
        printf("\nINGRESE NUMERO: ");
        scanf("%i", &arreglo[i]);
        i++;

        printf("\INGRESE S PARA CONTINUAR CARGANDO: ");
        fflush(stdin);
        scanf("%c", &op);
    }
    return i;
}

void mostrarArreglo(int arreglo[], int validos){
    int i;
    printf("\n|");
    for(i=0;i<validos;i++){
        printf(" %d |", arreglo[i]);
    }
    printf("\n");
}

stPersona cargarPersona(){

    stPersona persona;
    printf("\n INGRESE EL NOMBRE: ");
    fflush(stdin);
    gets(persona.nombre);
    printf("\n INGRESE EL SEXO: ");
    fflush(stdin);
    scanf("%c", &persona.sexo);
    printf("\n INGRESE LA EDAD: ");
    fflush(stdin);
    scanf("%d", &persona.edad);

    return persona;
}

int cargarPersonas(stPersona persona[], int dim){
    int i;
    for(i = 0; i < dim; i++){
        persona[i] = cargarPersona();
    }
    return i;
}

void mostrarPersonas(stPersona persona[] , int validos){
    int i;
    for(i = 0; i<validos; i++){
        printf("\n PERSONA %i\n", i+1);
        printf("\n NOMBRE: %s", persona[i].nombre);
        printf("\n SEXO: %c", persona[i].sexo);
        printf("\n EDAD: %i", persona[i].edad);
        printf("\n");
    }
}

int comprobarCantidadSexo(stPersona persona[], int validos, char sexo){
    int contador = 0;
    int i;
    for(i = 0;i<validos;i++){
        if(persona[i].sexo == sexo){
            contador++;
        }
    }
    printf("CONTADOR: %d", contador);
    return contador;
}

void copiarPersonas(stPersona persona1[], stPersona persona2[], int validos, char sexo){

    int i = 0;
    int j = 0;
    do{
        if(persona1[i].sexo == sexo){
            persona2[j] = persona1[i];
            j++;
            i++;
        }
        else{
            i++;
        }
    }while(i<validos);
}
