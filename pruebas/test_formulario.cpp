// Pruebas de CFormulario. Responsable: GRUPO 2
#include <sstream>
#include "minitest.h"
#include "CFormulario.h"
using namespace std;

int main(){
    SECCION("CFormulario: pedirMedicamento con datos validos");
    {
        stringstream in("5\nAcetaminofen\n1\n100\n1000\n2000\n");
        stringstream out;
        CValidador validador(in, out);
        CFormulario formulario(validador, out);
        CMedicamento m = formulario.pedirMedicamento();
        CHECK_EQ(m.getId(), 5);
        CHECK_EQ(m.getNombre(), "Acetaminofen");
        CHECK_EQ(m.getFormaDePresentacion(), 1);
        CHECK_EQ(m.getCantidadDisponible(), 100);
        CHECK_NEAR(m.getCostoDeCompra(), 1000.0, 0.001);
        CHECK_NEAR(m.getPrecioDeVenta(), 2000.0, 0.001);
    }

    SECCION("CFormulario: pedirId y pedirCantidad");
    {
        stringstream in("42\n7\n");
        stringstream out;
        CValidador validador(in, out);
        CFormulario formulario(validador, out);
        CHECK_EQ(formulario.pedirId(), 42);
        CHECK_EQ(formulario.pedirCantidad(), 7);
    }

    SECCION("CFormulario: pedirFecha");
    {
        stringstream in("14/03/2024\n");
        stringstream out;
        CValidador validador(in, out);
        CFormulario formulario(validador, out);
        CHECK_EQ(formulario.pedirFecha(), "14/03/2024");
    }

    // TODO (Grupo 2): ¿el formulario muestra las opciones de forma de presentación?
    // Nota: la validación real es del Grupo 3; aquí use entradas válidas.

    return RESUMEN();
}
