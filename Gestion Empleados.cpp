#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Definición de una estructura para un Empleado
struct Empleado {
    string id;  // Cambiado a string para permitir letras y números
    string nombre;
    float salario;
};

// Definir el tamaño máximo para la lista de empleados
const int MAX_EMPLEADOS = 50;
Empleado empleados[MAX_EMPLEADOS];
int totalEmpleados = 0;

// Función para ingresar una cadena con validación
string ingresarCadena(const string& mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

// Función para ingresar un número decimal dentro de un rango
float ingresarNumeroDecimal(const string& mensaje, float min, float max) {
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor < min || valor > max) {
            cout << "Error: Ingrese un número decimal válido entre " << min << " y " << max << ": ";
            cin.clear();  // Limpiar estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada no válida
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpiar el buffer
            return valor;
        }
    }
}

// Función para agregar un empleado
void agregarEmpleado() {
    if (totalEmpleados < MAX_EMPLEADOS) {
        Empleado nuevoEmpleado;

        // Ingresar el ID del empleado
        nuevoEmpleado.id = ingresarCadena("Ingrese el ID del empleado: ");

        // Leer el nombre del empleado
        nuevoEmpleado.nombre = ingresarCadena("Ingrese el nombre del empleado: ");

        // Ingresar el salario del empleado
        nuevoEmpleado.salario = ingresarNumeroDecimal("Ingrese el salario del empleado: ", 0.0f, numeric_limits<float>::max());

        empleados[totalEmpleados] = nuevoEmpleado;
        totalEmpleados++;
        cout << "Empleado agregado exitosamente.\n";
    } else {
        cout << "No se puede agregar más empleados.\n";
    }
}

// Función para mostrar todos los empleados
void mostrarEmpleados() {
    if (totalEmpleados == 0) {
        cout << "No hay empleados registrados.\n";
    } else {
        cout << "Lista de empleados:\n";
        for (int i = 0; i < totalEmpleados; i++) {
            cout << "ID: " << empleados[i].id
                 << " | Nombre: " << empleados[i].nombre
                 << " | Salario: " << empleados[i].salario << endl;
        }
    }
}

// Función para actualizar el salario de un empleado
void actualizarSalario() {
    string id = ingresarCadena("Ingrese el ID del empleado: ");

    for (int i = 0; i < totalEmpleados; i++) {
        if (empleados[i].id == id) {
            empleados[i].salario = ingresarNumeroDecimal("Ingrese el nuevo salario: ", 0.0f, numeric_limits<float>::max());
            cout << "Salario actualizado exitosamente.\n";
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

// Función para eliminar un empleado
void eliminarEmpleado() {
    string id = ingresarCadena("Ingrese el ID del empleado a eliminar: ");

    for (int i = 0; i < totalEmpleados; i++) {
        if (empleados[i].id == id) {
            for (int j = i; j < totalEmpleados - 1; j++) {
                empleados[j] = empleados[j + 1];
            }
            totalEmpleados--;
            cout << "Empleado eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

// Función principal con menú
int main() {
    int opcion;
    do {
        cout << "\n--- Sistema de Gestión de Empleados ---\n";
        cout << "1. Agregar empleado\n";
        cout << "2. Mostrar empleados\n";
        cout << "3. Actualizar salario de empleado\n";
        cout << "4. Eliminar empleado\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";

        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {  // Validación de número para opción del menú
            cout << "Error: Ingrese una de las opciones dadas.\n";
            cin.clear();  // Limpiar estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada no válida
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpiar el buffer

        switch (opcion) {
            case 1:
                agregarEmpleado();
                break;
            case 2:
                mostrarEmpleados();
                break;
            case 3:
                actualizarSalario();
                break;
            case 4:
                eliminarEmpleado();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
        }
    } while (opcion != 5);

    return 0;
	} 