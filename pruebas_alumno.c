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

void insertar_x_posicion_lista_nula(){
	lista_t *lista = NULL;
	int elemento1 = 14;
	size_t posicion_deseada = 2; 

	pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento1, posicion_deseada) == NULL && lista_elemento_en_posicion(lista, posicion_deseada) == NULL ,
	 "No se puede insertar en cualquier posición en una lista nula");

}

void insertar_x_posicion_lista_vacia(){
	lista_t *lista = lista_crear();
	// int elemento1 = 14;
	size_t posicion_deseada = 4; 

	// lista_insertar_en_posicion(lista, &elemento1, posicion_deseada);

	pa2m_afirmar(lista_elemento_en_posicion(lista, posicion_deseada) != NULL ,
	 "Se prueba insertar en cualquier posición en una lista vacia");
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

void insertar_elem_repetido() {
    lista_t *lista = lista_crear();

    int elem = 42;

    lista_insertar(lista, &elem); 
    lista_insertar(lista, &elem);

    pa2m_afirmar(lista_vacia(lista) == false &&
				*(int *)lista_elemento_en_posicion(lista, 0) == elem &&
				*(int *)lista_elemento_en_posicion(lista, 1) == elem, 
                 "Se prueba insertar un elemento repetido en la lista");
}

void quitar_de_lista_nula() {
    lista_t *lista = NULL; 

    void *elemento = lista_quitar(lista); 

    pa2m_afirmar(elemento == NULL, "No se puede quitar un elemento de una lista nula");
}

void quitar_de_lista_vacia() {
    lista_t *lista = lista_crear();

    void *elemento = lista_quitar(lista);

    pa2m_afirmar(elemento == NULL, "No se puede quitar un elemento de una lista vacía");
	
	lista_destruir(lista);
}

void quitar_ultimo_elemento() {
    lista_t *lista = lista_crear();

    int elem1 = 10;
    int elem2 = 20;
    int elem3 = 30;

    lista_insertar(lista, &elem1);
    lista_insertar(lista, &elem2);
    lista_insertar(lista, &elem3);

    void *elemento_quitado = lista_quitar(lista);

    pa2m_afirmar(*(int *)elemento_quitado == elem3 &&
				*(int *)lista_ultimo(lista) == elem2, 
				"Se prueba quitar el último elemento de una lista con elementos");
	
	// lista_destruir(lista);
}

void quitar_de_posicion_en_lista_nula() {
    lista_t *lista = NULL;

    size_t posicion = 2; 
    void *elemento = lista_quitar_de_posicion(lista, posicion); 

    pa2m_afirmar(elemento == NULL, "No se puede quitar un elemento de cualquier posición en una lista nula");
}

void quitar_de_posicion_en_lista_vacia() {
    lista_t *lista = lista_crear(); 

    size_t posicion = 2;
    void *elemento = lista_quitar_de_posicion(lista, posicion); 

    pa2m_afirmar(elemento == NULL, "No se puede quitar un elemento de cualquier posición en una lista vacía");

    lista_destruir(lista);
}

void quitar_elemento_de_posicion_en_lista_con_elementos() {
    lista_t *lista = lista_crear(); 

    int elem1 = 10;
    int elem2 = 20;
    int elem3 = 30;

    lista_insertar(lista, &elem1);
    lista_insertar(lista, &elem2);
    lista_insertar(lista, &elem3);

    size_t posicion = 1; 
    void *elemento_quitado = lista_quitar_de_posicion(lista, posicion);

  
    pa2m_afirmar(*(int *)elemento_quitado == elem2,
		"Se prueba quitar un elemento de cualquier posición de una lista con elementos");

    // Limpia los recursos
    // Si tienes una función para liberar la lista, úsala aquí
    // lista_destruir(lista);
}

void quitar_multiples_elementos_de_lista() {
    lista_t *lista = lista_crear(); 

    int elem1 = 10;
    int elem2 = 20;
    int elem3 = 30;
    int elem4 = 40;

    lista_insertar(lista, &elem1);
    lista_insertar(lista, &elem2);
    lista_insertar(lista, &elem3);
    lista_insertar(lista, &elem4);

    void *elemento_quitado1 = lista_quitar_de_posicion(lista, 0);
    void *elemento_quitado2 = lista_quitar(lista);
    pa2m_afirmar(*(int *)elemento_quitado1 == elem1 && *(int *)elemento_quitado2 == elem4 && 
		*(int *)lista_ultimo(lista) != elem4 && *(int *)lista_elemento_en_posicion(lista, 0) != elem1, 
		"Se prueba quitar múltiples elementos de una lista");
    
	//lista_destruir(lista);
}

void quitar_elemento_posicion_inexistente() {
    lista_t *lista = lista_crear(); 

    int elem1 = 10;
    int elem2 = 20;
    int elem3 = 30;

    lista_insertar(lista, &elem1);
    lista_insertar(lista, &elem2);
    lista_insertar(lista, &elem3);

    void *elemento_quitado = lista_quitar_de_posicion(lista, 5);
    pa2m_afirmar(*(int *)elemento_quitado == elem3 && lista_ultimo(lista) != &elem3, 
		"Se prueba quitar de una posición inexistente en la lista y el último elemento ya no está en la lista");

    //lista_destruir(lista);
}

void quitar_elemento_null() {
    lista_t *lista = lista_crear(); 

    int elem1 = 10;
    int elem2 = 20;
	size_t posicion = 1;

    lista_insertar(lista, &elem1);
    lista_insertar(lista, NULL);
    lista_insertar(lista, &elem2);

    void *elemento_quitado = lista_quitar_de_posicion(lista, posicion); 
    pa2m_afirmar(elemento_quitado == NULL && lista_elemento_en_posicion(lista, posicion) != NULL, 
		"El elemento NULL ya no está en la lista");

	 // lista_destruir(lista);
}

void obtener_elemento_lista_nula() {
    lista_t *lista = NULL;

    void *elemento = lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(elemento == NULL, "No se puede obtener un elemento de una lista nula");
}

void obtener_elemento_lista_vacia() {
    lista_t *lista = lista_crear(); 

    void *elemento = lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(elemento == NULL, "No se puede obtener un elemento de una lista vacía");

	lista_destruir(lista);
}

void obtener_elemento_posicion_inexistente() {
    lista_t *lista = lista_crear();

    int elem1 = 10;
    lista_insertar(lista, &elem1);

    void *elemento = lista_elemento_en_posicion(lista, 5); // Posición inexistente
    pa2m_afirmar(elemento == NULL, "No se puede obtener un elemento de una posición inexistente");

    // lista_destruir(lista);
}

void obtener_elemento_posicion_existente() {
    lista_t *lista = lista_crear();

    int elem1 = 10;
    lista_insertar(lista, &elem1);

    void *elemento = lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(*(int *)elemento == elem1, "Se obtuvo correctamente el elemento de una posición existente");

   // lista_destruir(lista);
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
	insertar_x_posicion_lista_vacia();
	insertar_x_posicion_lista_elementos();
	insertar_posicion_inexistente();
	insertar_nulo_valido();
	insertar_elem_repetido();

	quitar_de_lista_nula();
	quitar_de_lista_vacia();
	quitar_ultimo_elemento();
	quitar_de_posicion_en_lista_nula();
	quitar_de_posicion_en_lista_vacia();
	quitar_elemento_de_posicion_en_lista_con_elementos();
	quitar_multiples_elementos_de_lista();
	quitar_elemento_posicion_inexistente();
	quitar_elemento_null();

	obtener_elemento_lista_nula();
	obtener_elemento_lista_vacia();
	obtener_elemento_posicion_inexistente();
	obtener_elemento_posicion_existente();


	return pa2m_mostrar_reporte();
}
