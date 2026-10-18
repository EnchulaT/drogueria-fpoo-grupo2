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
    // STUB (Grupo 2): implementar
    return CMedicamento(0, "", 0, 0, 0, 0);
}

int CFormulario::pedirId(){
    // STUB (Grupo 2): implementar
    return 0;
}

int CFormulario::pedirCantidad(){
    // STUB (Grupo 2): implementar
    return 0;
}

string CFormulario::pedirFecha(){
    // STUB (Grupo 2): implementar
    return validador.leerFecha("Ingrese la fecha (DD/MM/AAAA): ");
}
