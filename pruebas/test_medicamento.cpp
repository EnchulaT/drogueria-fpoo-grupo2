// Pruebas de CMedicamento (clase base). Responsable: GRUPO 2
#include "minitest.h"
#include "CMedicamento.h"

int main(){
    CMedicamento m(1, "Acetaminofen 60Mg", 1, 100, 1000, 2000);

    SECCION("CMedicamento: getters");
    CHECK_EQ(m.getId(), 1);
    CHECK_EQ(m.getNombre(), "Acetaminofen 60Mg");
    CHECK_EQ(m.getFormaDePresentacion(), 1);
    CHECK_EQ(m.getCantidadDisponible(), 100);
    CHECK_NEAR(m.getCostoDeCompra(), 1000.0, 0.001);
    CHECK_NEAR(m.getPrecioDeVenta(), 2000.0, 0.001);

    SECCION("CMedicamento: setCantidadDisponible");
    m.setCantidadDisponible(50);
    CHECK_EQ(m.getCantidadDisponible(), 50);

    SECCION("CMedicamento: cantidad en 0");
    m.setCantidadDisponible(0);
    CHECK_EQ(m.getCantidadDisponible(), 0);

    SECCION("CMedicamento: valores muy grandes");
    CMedicamento grande(99999, "Insulina", 4, 1000000, 250000.5f, 499999.5f);
    CHECK_EQ(grande.getId(), 99999);
    CHECK_EQ(grande.getCantidadDisponible(), 1000000);
    CHECK_NEAR(grande.getCostoDeCompra(), 250000.5, 0.01);
    CHECK_NEAR(grande.getPrecioDeVenta(), 499999.5, 0.01);

    SECCION("CMedicamento: nombre vacio se guarda tal cual");
    CMedicamento sinNombre(2, "", 2, 5, 100, 200);
    CHECK_EQ(sinNombre.getNombre(), "");

    SECCION("CMedicamento: la copia es independiente");
    CMedicamento original(3, "Ibuprofeno", 2, 10, 500, 2500);
    CMedicamento copia = original;
    copia.setCantidadDisponible(99);
    CHECK_EQ(original.getCantidadDisponible(), 10);
    CHECK_EQ(copia.getCantidadDisponible(), 99);
    CHECK_EQ(copia.getNombre(), "Ibuprofeno");

    return RESUMEN();
}
