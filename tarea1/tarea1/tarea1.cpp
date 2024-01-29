// tarea1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

/*
Matthias Sibrian Illescas
Cómputo en la nube
A01794249
*/

//

// Creación y configuración del proyecto

#include <iostream>
#include <omp.h>

#define N 8000
#define chunk 500
#define mostrar 8

// Código correcto y funcional	

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando arreglos en paralelo\n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++)
    {
        //Generación o petición de la información para llenar los arreglos

        /*
        * Para llenar los arreglos, se hizo uso de un cálculo a partir de un número random generado a través de una semilla. 
        * Se están creando dos arreglos (a y b) donde los valores de cada elemento están influenciados tanto por el índice 
        del elemento como por un número random. La semilla basada en el tiempo hace que sea random, y luego se logra crear 
        el número con la función rand.
        */

        srand((unsigned)time(NULL));
        int random = rand();
        a[i] = i * random;
        b[i] = i - random;
    }
    int pedazos = chunk;

    //Uso correcto del for paralelo

    #pragma omp parallel for \
    shared(a,b,c,pedazos) private(i) \
    schedule(static, pedazos)
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

// Impresión de los elementos de cada arreglo	

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
