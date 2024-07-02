#include <stdio.h>
#include <string.h>

#define MAX_EMPLEADOS 5

struct Empleado {
    char nombre[40];
    int edad;
    float salario;
};


void ingresar_datos(struct Empleado empleados[], int *numEmpleados);
void procesar_datos(struct Empleado empleados[], int numEmpleados);
void mostrar_datos(struct Empleado empleados[], int numEmpleados);

int main() {
    struct Empleado empleados[MAX_EMPLEADOS];
    int numEmpleados = 0;
    int opcion;

    do {
        printf("--Menú--\n");
        printf("1. Ingresar datos de un empleado\n");
        printf("2. Procesar y mostrar información relevante de los empleados\n");
        printf("3. Salir del programa\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresar_datos(empleados, &numEmpleados);
                break;
            case 2:
                procesar_datos(empleados, numEmpleados);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    } while(opcion != 3);

    return 0;
}

void ingresar_datos(struct Empleado empleados[], int *numEmpleados) {
    if (*numEmpleados < MAX_EMPLEADOS) {
        printf("Ingrese el nombre del empleado: ");
        scanf("%s", empleados[*numEmpleados].nombre);
        printf("Ingrese la edad del empleado: ");
        scanf("%d", &empleados[*numEmpleados].edad);
        printf("Ingrese el salario del empleado: ");
        scanf("%f", &empleados[*numEmpleados].salario);
        (*numEmpleados)++;
        printf("Empleado ingresado correctamente.\n");
    } else {
        printf("No se pueden ingresar más empleados. Límite alcanzado.\n");
    }
}

void procesar_datos(struct Empleado empleados[], int num_empleados) {
    if (num_empleados == 0) {
        printf("No hay empleados ingresados.\n");
        return;
    }

    float promedio_salarios = 0;
    float salario_maximo = empleados[0].salario;
    char nombre_maximo[50];
    for (int i = 0; i < num_empleados; i++) {
        promedio_salarios += empleados[i].salario;
        if (empleados[i].salario > salario_maximo) {
            salario_maximo = empleados[i].salario;
            strcpy(nombre_maximo, empleados[i].nombre);
        }
    }
    promedio_salarios /= num_empleados;

    printf("Promedio de salarios: %.2f\n", promedio_salarios);
    printf("Empleado con el salario más alto: %s\n", nombre_maximo);
}

void mostrarDatos(struct Empleado empleados[], int num_empleados) {
    if (num_empleados == 0) {
        printf("No hay empleados ingresados.\n");
        return;
    }

    printf("Información de los empleados:\n");
    for (int i = 0; i < num_empleados; i++) {
        printf("Empleado %d:\n", i+1);
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Edad: %d\n", empleados[i].edad);
        printf("Salario: %.2f\n", empleados[i].salario);
        printf("\n");
    }
}

