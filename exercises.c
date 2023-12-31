#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
  int mayor = arr[0];
  
  for (int i = 1; i < size; i++)
  {
    
    if (arr[i] > mayor)
    {
      mayor = arr[i];
    }
    
  }
  return mayor;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  for (int i = 0 ; i < size / 2; i++)
  {
      int aux = arr[i];
      arr[i] = arr[size - i - 1];
      arr[size - i - 1] = aux;
  }
  
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) {
  int contador_pares = 0;
  for (int i = 0 ; i < size ; i++)
    {
      if (arr[i] % 2 == 0)
      {
        contador_pares++;
      }
    }

  int *arr_pares = (int *)malloc(contador_pares * sizeof(int));
  
  if (arr_pares == NULL) {
    *newSize = 0;
    return NULL; 
  }

  int j = 0;
  for(int i = 0 ; i < size ; i++)
    {
      if (arr[i] % 2 == 0)
      {
        arr_pares[j] = arr[i];
        j++;
      }
    }

  *newSize = contador_pares;
  return arr_pares;
}

//malloc -> se conoce el size, copia los elementos tal cual
//realloc -> aumenta o disminuye el size
//calloc -> inicializa todos los elementos en 0

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]){
  int i, j, k;
  for (i = 0, j = 0, k = 0 ; i < size1 || j < size2; k++)
  {
    if (i < size1 && (j >= size2 || arr1[i] < arr2[j]))
    {
      result[k] = arr1[i];
      i++;
    }
      
    else
    {
      result[k] = arr2[j];
      j++;
    }
  }   
  
}

//arr1[i], arr2[j, resutl[k]
/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int ascendente = 0;
  int descendente = 0;
  for(int i = 0 ; i < size - 1 ; i++)
    {
      if (arr[i] <= arr[i+1])
      {
        ascendente++;
      }

      if (arr[i] >= arr[i+1])
      {
        descendente++;
      }
      
    }

  if (ascendente == size - 1)
  {
    return 1;
  }
  
  if (descendente == size - 1)
  {
    return -1;
  }
  
  return 0;
  
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. 
En la biblioteca, hay libros, y cada libro tiene un autor. 
Queremos organizar esta información utilizando estructuras anidadas en C. Escribe la función para inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;  //asociado al struct anterior
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) {

  strcpy(libro-> titulo, titulo);
  strcpy(libro-> autor.nombre, nombreAutor);

  libro-> anioPublicacion = anioPublicacion;
  libro-> autor.anioNacimiento = anioNacimiento;
  
  
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista debe contener un número del arreglo, y los nodos deben estar enlazados en el mismo orden que los números aparecen en el arreglo. El último nodo de la lista debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
*/

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
  //CASO CORTE: lista vacía
  if (size == 0)
  {
    return NULL;
  }

  Nodo *primero = NULL;
  Nodo **punteroActual = &primero;
  
  for (int i = 0 ; i < size ; i++)
  {
    *punteroActual = (Nodo *) malloc(sizeof(Nodo));

    //verificar que se asigne memoria correctamente
    if (*punteroActual == NULL)
    {
      return NULL;
    }

    
    (*punteroActual)->numero = arr[i];
    (*punteroActual)->siguiente = NULL;

    //actualizar punteroActual
    punteroActual = &((*punteroActual)->siguiente);
    
  }
  
  return primero;
}
