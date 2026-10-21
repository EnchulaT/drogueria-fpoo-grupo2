/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Formularios de captura (GRUPO 2)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CFormulario.h"
using namespace std;

CFormulario::CFormulario(CValidador& validador_, ostream& salida_) : validador(validador_), salida(salida_) {
}

CMedicamento CFormulario::pedirMedicamento(){
    int id = validador.leerEntero("Ingrese la ID del medicamento: ", 1, 99999);
    string nombre = validador.leerTextoNoVacio("Ingrese el nombre del medicamento: ");
    int fdpresentacion = validador.leerEntero("Formas de presentacion:\n 1 = Tableta\n 2 = Caja\n 3 = Jarabe\n 4 = Ampolla\n 5 = Crema\nIngrese el numero de la forma de presentacion (1-5): ", 1, 5);
    int cantidad = validador.leerEntero("Ingrese la cantidad de medicamento: ", 1, 99999);
    float costo = validador.leerFloatPositivo("Ingrese el costo de compra: ");
    float precio = validador.leerFloatPositivo("Ingrese el precio de venta: ");


    // Extra: mostrar un resumen de lo ingresado antes de crear el medicamento.
    string formas[] = {"", "Tableta", "Caja", "Jarabe", "Ampolla", "Crema"};
    string forma = (fdpresentacion >= 1 && fdpresentacion <= 5) ? formas[fdpresentacion] : "Desconocida";
    salida << "\nResumen:\n";
    salida << "ID: " << id << "\n";
    salida << "Nombre: " << nombre << "\n";
    salida << "Forma de presentacion: " << forma << "\n";
    salida << "Cantidad: " << cantidad << "\n";
    salida << "Costo de compra: " << costo << "\n";
    salida << "Precio de venta: " << precio << "\n";

    return CMedicamento(id, nombre, fdpresentacion, cantidad, costo, precio);
}

int CFormulario::pedirId(){
    return validador.leerEntero("Ingrese la ID del medicamento: ", 1, 99999);
}

int CFormulario::pedirCantidad(){
    return validador.leerEntero("Ingrese la cantidad: ", 1, 99999);
}

string CFormulario::pedirFecha(){
    return validador.leerFecha("Ingrese la fecha (dd-mm-aaaa): ");
}
