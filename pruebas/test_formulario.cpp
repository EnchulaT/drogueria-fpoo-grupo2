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
        stringstream in("14-03-2024\n");
        stringstream out;
        CValidador validador(in, out);
        CFormulario formulario(validador, out);
        CHECK_EQ(formulario.pedirFecha(), "14-03-2024");
    }

    SECCION("CFormulario: muestra las 5 formas de presentacion");
    {
        stringstream in("5\nAcetaminofen\n3\n100\n1000\n2000\n");
        stringstream out;
        CValidador validador(in, out);
        CFormulario formulario(validador, out);
        formulario.pedirMedicamento();
        string texto = out.str();
        CHECK_CONTIENE(texto, "1 = Tableta");
        CHECK_CONTIENE(texto, "2 = Caja");
        CHECK_CONTIENE(texto, "3 = Jarabe");
        CHECK_CONTIENE(texto, "4 = Ampolla");
        CHECK_CONTIENE(texto, "5 = Crema");
    }

    SECCION("CFormulario: pregunta en el orden del contrato");
    {
        stringstream in("5\nAcetaminofen\n1\n100\n1000\n2000\n");
        stringstream out;
        CValidador validador(in, out);
        CFormulario formulario(validador, out);
        formulario.pedirMedicamento();
        string texto = out.str();
        size_t pId = texto.find("ID");
        size_t pNombre = texto.find("nombre");
        size_t pForma = texto.find("Formas de presentacion");
        size_t pCantidad = texto.find("cantidad");
        size_t pCosto = texto.find("costo");
        size_t pPrecio = texto.find("precio");
        CHECK(pId < pNombre);
        CHECK(pNombre < pForma);
        CHECK(pForma < pCantidad);
        CHECK(pCantidad < pCosto);
        CHECK(pCosto < pPrecio);
    }

    SECCION("CFormulario (extra): muestra el resumen de lo ingresado");
    {
        stringstream in("7\nIbuprofeno\n2\n50\n500\n2500\n");
        stringstream out;
        CValidador validador(in, out);
        CFormulario formulario(validador, out);
        CMedicamento m = formulario.pedirMedicamento();
        string texto = out.str();
        CHECK_CONTIENE(texto, "Resumen");
        CHECK_CONTIENE(texto, "ID: 7");
        CHECK_CONTIENE(texto, "Nombre: Ibuprofeno");
        CHECK_CONTIENE(texto, "Forma de presentacion: Caja");
        CHECK_CONTIENE(texto, "Cantidad: 50");
        CHECK_CONTIENE(texto, "Costo de compra: 500");
        CHECK_CONTIENE(texto, "Precio de venta: 2500");
        CHECK_EQ(m.getFormaDePresentacion(), 2);
    }

    SECCION("CFormulario: pedirMedicamento con cada forma de presentacion");
    {
        for (int forma = 1; forma <= 5; forma++) {
            stringstream in("1\nJarabe\n" + to_string(forma) + "\n10\n100\n200\n");
            stringstream out;
            CValidador validador(in, out);
            CFormulario formulario(validador, out);
            CHECK_EQ(formulario.pedirMedicamento().getFormaDePresentacion(), forma);
        }
    }

    // Nota: la validación real es del Grupo 3; aquí se usan entradas válidas.

    return RESUMEN();
}
