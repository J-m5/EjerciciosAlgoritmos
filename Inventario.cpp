#include <iostream>
#include <string>
#include <locale> // Incluye <locale> para la configuración de localización
#include <limits> // Para std::numeric_limits

using namespace std;

// Definición de una estructura para un Producto
struct Producto {
    string codigo;  // Cambiado a string para permitir letras y números
    string nombre;
    float cantidad; // Cambiado a float para permitir decimales
};

// Definir un tamaño máximo para el inventario
const int MAX_PRODUCTOS = 100;
Producto inventario[MAX_PRODUCTOS];
int totalProductos = 0;

// Función para validar la entrada de un número decimal
float leerDecimal(const string& mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) { // Si la entrada no es un número decimal
            cin.clear(); // Limpiar el estado de error del flujo de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
            cout << "Entrada inválida. Por favor, ingrese un número decimal: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
            return valor;
        }
    }
}

// Función para validar la entrada de una cadena de texto
string leerCadena(const string& mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

// Función para agregar un producto al inventario
void agregarProducto() {
    if (totalProductos < MAX_PRODUCTOS) {
        Producto nuevoProducto;
        
        // Leer el código del producto
        nuevoProducto.codigo = leerCadena("Ingrese el código del producto: ");
        
        // Verificación para evitar códigos duplicados
        for (int i = 0; i < totalProductos; i++) {
            if (nuevoProducto.codigo == inventario[i].codigo) {
                cout << "Este código ya está en uso." << endl;
                nuevoProducto.codigo = leerCadena("Ingrese un código diferente: ");
                i = -1; // Reinicia el ciclo para verificar el nuevo código ingresado
            }
        }

        // Leer el nombre del producto
        nuevoProducto.nombre = leerCadena("Ingrese el nombre del producto: ");
        
        // Leer la cantidad del producto
        nuevoProducto.cantidad = leerDecimal("Ingrese la cantidad del producto (puede ser decimal): ");

        inventario[totalProductos] = nuevoProducto;
        totalProductos++;

        cout << "Producto agregado exitosamente.\n";
        cout << "Total de productos: " << totalProductos << endl;
    } else {
        cout << "El inventario está lleno.\n";
    }
}

// Función para mostrar todos los productos del inventario
void mostrarProductos() {
    if (totalProductos == 0) {
        cout << "No hay productos en el inventario.\n";
    } else {
        cout << "Inventario de productos:\n";
        for (int i = 0; i < totalProductos; i++) {
            cout << "Código: " << inventario[i].codigo
                 << " | Nombre: " << inventario[i].nombre
                 << " | Cantidad: " << inventario[i].cantidad << endl;
        }
    }
}

// Función para actualizar la cantidad de un producto
void actualizarProducto() {
    string codigo;
    codigo = leerCadena("Ingrese el código del producto a actualizar: ");
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            inventario[i].cantidad = leerDecimal("Ingrese la nueva cantidad: ");
            cout << "Nueva cantidad agregada exitosamente." << endl;
            cout << "Cantidad actualizada a: " << inventario[i].cantidad << endl;
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función para eliminar un producto del inventario
void eliminarProducto() {
    string codigo;
    codigo = leerCadena("Ingrese el código del producto a eliminar: ");
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            for (int j = i; j < totalProductos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            totalProductos--;
            cout << "Producto eliminado con éxito." << endl;
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función principal con menú
int main() {
    setlocale(LC_CTYPE, "es_ES.UTF-8"); // Configura la localización para manejar caracteres especiales en español
    int opcion;
    do {
        cout << "\n--- Sistema de Gestión de Inventario ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Actualizar cantidad de producto\n";
        cout << "4. Eliminar producto\n";
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
                agregarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                actualizarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 5);

    return 0;
}