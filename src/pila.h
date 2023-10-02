#include "pila.h"
#include "lista.h"
struct _pila_t {
  lista_t *lista;
};

pila_t *pila_crear() {
  pila_t *pila = malloc(sizeof(pila_t));
  if (!pila) {
    return NULL;
  }
  pila->lista = lista_crear();
  if (!pila->lista) {
    free(pila);
    return NULL;
  }
  return pila;
}

pila_t *pila_apilar(pila_t *pila, void *elemento) {
  if (!pila) {
    return NULL;
  }
  if (!lista_insertar(pila->lista, elemento)) {
    return NULL;
  }
  return pila;
}

void *pila_desapilar(pila_t *pila) {
  if (!pila || lista_vacia(pila->lista)) {
    return NULL;
  }
  size_t ultima_posicion = lista_tamanio(pila->lista) - 1;
  return lista_quitar_de_posicion(pila->lista, ultima_posicion);
}

void *pila_tope(pila_t *pila) {
  if (!pila || lista_vacia(pila->lista)) {
    return NULL;
  }
  size_t ultima_posicion = lista_tamanio(pila->lista) - 1;
  return lista_elemento_en_posicion(pila->lista, ultima_posicion);
}

size_t pila_tamanio(pila_t *pila) {
  if (!pila) {
    return 0;
  }
  return lista_tamanio(pila->lista);
}

bool pila_vacia(pila_t *pila) {
  if (!pila) {
    return true;
  }
  return lista_vacia(pila->lista);
}

void pila_destruir(pila_t *pila) {
  if (!pila) {
    return;
  }
  lista_destruir(pila->lista);
  free(pila);
}
