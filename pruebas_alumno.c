#include "pa2m.h"
#include <stdio.h>
#include "src/lista.h"

void prueba_simple()
{
	int i = 14;
	int j = 16;
	pa2m_afirmar(i != j, "i=14 es diferente de j=16");
}

void crear_lista_vacia()
{
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista_tamanio(lista) == 0 && lista_vacia(lista), "Se prueba crear una lista valida y verificar que empiece vacia.");
	lista_destruir(lista);
}

void insertar_final_lista_vacia()
{
	lista_t *lista = lista_crear();
	int elemento = 14;
	pa2m_afirmar(lista_insertar(lista, &elemento) == lista && lista_vacia(lista) == false && lista_tamanio(lista) == 1 ,
	 "Se prueba insertar al final en una lista nula");
}

void insertar_lista_4_elementos(lista_t *lista){
	int elemento1 = 14;
	int elemento2 = 15;
	int elemento3 = 16;
	int elemento4 = 17;
	for(int i = 0; i < 4; i++){
		lista_insertar(lista, &elemento1);
		lista_insertar(lista, &elemento2);
		lista_insertar(lista, &elemento3);
		lista_insertar(lista, &elemento4);
	}
}

void verificar_posicion_insertar_final(){
	lista_t *lista = lista_crear();
	insertar_lista_4_elementos(lista);
	int elemento5 = 18;
	
	pa2m_afirmar(lista_insertar(lista, &elemento5) == lista && lista_vacia(lista) == false && lista_elemento_en_posicion(lista, 5) != NULL ,
	 "Se prueba insertar al final en una lista con elementos y se verifica que está en la posición correcta");
}

void insertar_elemento_null_final(){
	lista_t *lista = lista_crear();
	insertar_lista_4_elementos(lista);
	
	void *elemento = NULL;

	pa2m_afirmar(lista_insertar(lista, elemento) == lista && lista_vacia(lista) == false && lista_elemento_en_posicion(lista, 5) != NULL ,
	 "Se prueba insertar al final en una lista nula");
}

void insertar_x_posicion_lista_nula(){}

void insertar_x_posicion_lista_vacia(){
	lista_t *lista = lista_crear();
	int elemento1 = 14;

	pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento1, 4) == lista && lista_vacia(lista) == false && lista_elemento_en_posicion(lista, 4) != NULL ,
	 "Se prueba insertar en cualquier posición en una lista nula");
}

void insertar_x_posicion_lista_elementos(){
	lista_t *lista = lista_crear();
	insertar_lista_4_elementos(lista);

	size_t posicion_deseada = 2; 
	int elem_insertar = 20;
	
	lista_insertar_en_posicion(lista, &elem_insertar, posicion_deseada);
    int *elemento = (int *)lista_elemento_en_posicion(lista, posicion_deseada);

	pa2m_afirmar(lista_vacia(lista) == false && *elemento == 20,
	 "Se prueba insertar en cualquier posición en una lista con elementos y se verifica que está en la posición correcta");
}

void insertar_posicion_inexistente(){
	lista_t *lista = lista_crear();
	insertar_lista_4_elementos(lista);

	size_t posicion_deseada = 100; 
	int elem_insertar = 20;
	
	lista_insertar_en_posicion(lista, &elem_insertar, posicion_deseada);
	int *elemento = (int *)lista_elemento_en_posicion(lista, posicion_deseada);
	printf("%d", *elemento);

	int *ultimo_elemento = (int *)lista_ultimo(lista);

	pa2m_afirmar(lista_vacia(lista) == false && *ultimo_elemento == 20 && *elemento == 20 ,
	 "Se prueba insertar en una posición inexistente en la lista, y se verifica que la posición de ese elemento es la última");
}

void insertar_nulo_valido() {
    lista_t *lista = lista_crear();
    insertar_lista_4_elementos(lista);

    void *elem_nulo = NULL;
    pa2m_afirmar(lista_insertar(lista, elem_nulo) == lista && 
                 lista_vacia(lista) == false && 
                 lista_elemento_en_posicion(lista, 5) != NULL, 
                 "Se prueba insertar un elemento nulo en una lista válida");
}


int main()
{
	pa2m_nuevo_grupo("------------ PRUEBAS DEL TDA ------------");

	pa2m_nuevo_grupo(
		"\n======================== XXX ========================");
	
	crear_lista_vacia();
	insertar_final_lista_vacia();
	verificar_posicion_insertar_final();
	insertar_elemento_null_final();
	insertar_x_posicion_lista_nula();
	insertar_x_posicion_lista_elementos();
	insertar_posicion_inexistente();
	insertar_nulo_valido();


	return pa2m_mostrar_reporte();
}
