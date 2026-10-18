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
    int id = validador.leerEntero("Ingrese la ID del medicamento", 1, 99999  );
    string nombre = validador.leerTextoNoVacio("Ingrese el nombre del medicamento");
    int fdpresentacion = validador.leerEntero("Ingrese el numero correspondiente a la forma de presentacion \n 1 = Tableta \n 2 = Caja \n 3 = Jarabe \n 4 = Ampolla \n 5 = Crema", 1, 5);
    int cantidad = validador.leerEntero("Ingrese la cantidad de medicamento",1, 99999);
    float costo = validador.leerFloatPositivo("Ingrese el costo del medicamento");
    float precio = validador.leerFloatPositivo("Ingrese el precio del medicamento");
    return CMedicamento(id, nombre, fdpresentacion, cantidad, costo, precio);
}

int CFormulario::pedirId(){
    return validador.leerEntero("Ingrese la ID del medicamento", 1, 99999);
}

int CFormulario::pedirCantidad(){
    return validador.leerEntero("Ingrese la cantidad de medicamento", 1, 99999);
}

string CFormulario::pedirFecha(){
    return validador.leerFecha("Ingrese la fecha (DD/MM/AAAA): ");
}
