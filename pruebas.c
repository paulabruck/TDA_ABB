#include "abb.h"
#include <stdio.h>
#include "pa2mm.h"
#include "string.h"
#define MAXIMO 10

const int MAYOR_=1;
const int IGUALES_=0;
const int MENOR_=-1;

void dadoUnArbolInexistente_SiQuieroInsertarUnElemento_NoPuedoHacerlo(){
    abb_t* arbol_= NULL;
    int estado=0;
    estado= arbol_insertar(arbol_, (void*)1);
    pa2m_afirmar(!arbol_, "El arbol no existe.");
    pa2m_afirmar(estado==-1, "Dado un arbol inexistente no puedo insertar elementos.");
}
void dadoUnArbol_SiQuieroInsertarUnElementoNulo_PuedoHacerlo(){
    abb_t * arbol_= arbol_crear(NULL, NULL);
    int estado= arbol_insertar(arbol_, (void*)NULL);
    pa2m_afirmar(estado==0, "Dado un arbol existente puedo insertar un elemento nulo.");

    arbol_destruir(arbol_);
}
/* Funcion  utilizada para comparar enteros. Si el primero es mayor devuelve 1, si es menor -1,si son iguales devuelve 0.
*/
int comparador_de_enteros(void* entero1,void* entero2){
    if(*(int*)entero1>*(int*)entero2){
        return 1;
    }
    else if(*(int*)entero1<*(int*)entero2){
        return -1;
    }
    else{
        return 0;
    }
}
/* Inserta enteros en el arbol.
*/
void insertar_enteros(abb_t* arbol,int elementos[MAXIMO],int tope){
    for(int i=0;i<tope;i++){
        arbol_insertar(arbol,&elementos[i]);
    }
}
void dadoUnArbol_SiQuieroINsertarElementos_PuedoHacerlo(){
    int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
    abb_t * arbol_= arbol_crear(comparador_de_enteros,NULL);
    pa2m_afirmar(arbol_!=NULL, "El arbol ha sido creado con exito.");
    insertar_enteros(arbol_, enteros, MAXIMO);
    pa2m_afirmar(*(int*)arbol_raiz(arbol_)== enteros[0], "El primer elemento se inserta como raiz");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->derecha->elemento== enteros[1] , "EL segundo elemento al ser mayor que la raiz se ha insertado a la derecha");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->derecha->derecha->elemento== enteros[2] , "EL tercer elemento se ha insertado a la derecha del nodo padre ya que es mayor");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->izquierda->elemento== enteros[3] , "EL cuarto elemento al ser menor que la raiz se ha insertado a la izquierda");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->izquierda->derecha->elemento== enteros[4] , "EL quinto elemento se ha insertado a la derecha de su nodo padre ya que es mayor");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->derecha->derecha->derecha->elemento== enteros[5] , "EL sexto elemento se ha insertado a la derecha de su nodo padre ya que es mayor");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->izquierda->derecha->izquierda->elemento== enteros[6] , "EL septimo elemento se ha insertado a la izquierda de su nodo padre ya que es menor");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->derecha->izquierda->elemento== enteros[7] , "EL octavo elemento se ha insertado a la izquierda de su nodo padre ya que es menor");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->derecha->izquierda->derecha->elemento== enteros[8] , "EL noveno elemento se ha insertado a la derecha de su nodo padre ya que es mayor");
    pa2m_afirmar(*(int*)arbol_->nodo_raiz->derecha->izquierda->derecha->elemento== enteros[9] , "EL arbol inserta elementos repetidos correctamente.");
    arbol_destruir(arbol_);
}
void dadoUnArbol_SiQuieroBuscarUnElemento_SiEsteEstaEnElArbolPuedoHacerlo(){
    int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
    abb_t * arbol_= arbol_crear(comparador_de_enteros,NULL);
    insertar_enteros(arbol_, enteros, MAXIMO);
    int elemento= enteros[1];
    pa2m_afirmar(*(int*)arbol_buscar(arbol_, &elemento)== enteros[1],"Si quiero buscar el segundo elemento insertado me devuleve el elemento 20 ." );
    elemento= 1;
    pa2m_afirmar(arbol_buscar(arbol_, &elemento)== NULL,"Me devuleve NULL, el elemento buscado no esta en el arbol." );
    elemento= enteros[2];
    pa2m_afirmar(*(int*)arbol_buscar(arbol_, &elemento)== enteros[2],"Si quiero buscar el tercer elemento insertado me devuleve el elemento 30." );
    elemento= enteros[3];
    pa2m_afirmar(*(int*)arbol_buscar(arbol_, &elemento)== enteros[3],"Si quiero buscar el cuarto elemento insertado me devuleve el elemento 4." );
    elemento= enteros[4];
    pa2m_afirmar(*(int*)arbol_buscar(arbol_, &elemento)== enteros[4],"Si quiero buscar el quinto elemento insertado me devuleve el elemento 8." );
    elemento= enteros[5];
    pa2m_afirmar(*(int*)arbol_buscar(arbol_, &elemento)== enteros[5],"Si quiero buscar el sexto elemento insertado me devuleve el elemento 70." );
    elemento= enteros[6];
    pa2m_afirmar(*(int*)arbol_buscar(arbol_, &elemento)== enteros[6],"Si quiero buscar el septimo elemento insertado me devuleve el elemento 6." );
    elemento= enteros[7];
    pa2m_afirmar(*(int*)arbol_buscar(arbol_, &elemento)== enteros[7],"Si quiero buscar el octavo elemento insertado me devuleve el elemento 14." );
    elemento= enteros[8];
    pa2m_afirmar(*(int*)arbol_buscar(arbol_, &elemento)== enteros[8],"Si quiero buscar el noveno elemento insertado me devuleve el elemento 18." );
    arbol_destruir(arbol_);
}
void dadoUnArbolInexistente_SiQuieroBorrarUnElemento_NoPuedoHacerlo(){
    abb_t* arbol_= NULL;
    int estado_borrar=0;
    estado_borrar= arbol_borrar(arbol_, (void*)1);
    pa2m_afirmar(!arbol_, "El arbol no existe.");
    pa2m_afirmar(estado_borrar==-1, "Dado un arbol inexistente no puedo borrar  elementos.");
}
void dadoUnArbol_SiQuieroBorrarElementos_PuedoHacerloMientrasTengaElementos(){
    int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
    abb_t * arbol_= arbol_crear(comparador_de_enteros,NULL);
    pa2m_afirmar(arbol_!=NULL, "El arbol ha sido creado con exito.");
    insertar_enteros(arbol_, enteros, MAXIMO);
    int contador=0;
    for (int i = 0; i < MAXIMO-1; i++){
        contador++;
        pa2m_afirmar(arbol_borrar(arbol_, &enteros[i])==0 , "Puedo borrar el elemento insertado :");
        printf("\t\t\t\t\t%i en el arbol.\n", contador);
    }
    pa2m_afirmar(arbol_borrar(arbol_, &enteros[9])==0, "Puedo borrar la raiz  del arbol");
    pa2m_afirmar(arbol_vacio(arbol_), "EL arbol esta vacio.");
    pa2m_afirmar(arbol_raiz(arbol_)==NULL, "El arbol tiene raiz NULL .");

    arbol_destruir(arbol_);
}
void dadoUnArbol_SiQuieroConocerLaRaiz_PuedoHacerlo(){
    int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
    abb_t * arbol_= arbol_crear(comparador_de_enteros,NULL);
    pa2m_afirmar(arbol_raiz(arbol_)==NULL, "El arbol no tiene raiz .");
    insertar_enteros(arbol_, enteros, MAXIMO);
    pa2m_afirmar(*(int*)arbol_raiz(arbol_)== enteros[0], "El elemento insertado en la raiz es el 10.");
    pa2m_afirmar(arbol_borrar(arbol_, &enteros[0])==0, "Puedo borrar la raiz de un arbol con 10 elementos");
    pa2m_afirmar(*(int*)arbol_raiz(arbol_)== enteros[4], "La nueva raiz del arbol es el predecesor inorden(8) del elemento borrado.");
    pa2m_afirmar( *(int*)arbol_->nodo_raiz->izquierda->derecha->elemento == enteros[6] , "El lugar donde estaba el predecesor inorden fue ocupado por el nodo correspondiente.");
    pa2m_afirmar(*(int*)arbol_raiz(arbol_)!= enteros[1], "El segundo elemento insertado no es la raiz del arbol.");
    pa2m_afirmar(arbol_borrar(arbol_, &enteros[4])==0, "Puedo borrar la raiz de un arbol con 9 elementos");
    pa2m_afirmar(*(int*)arbol_raiz(arbol_)== enteros[6], "Si borro la raiz, la nueva raiz es el predecesor inorden");
    arbol_destruir(arbol_);
}
void dadoUnArbol_SiEstaVacio_MeDevuelveQueLoEsta(){
    int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
    abb_t *arbol_ = arbol_crear(comparador_de_enteros, NULL);
    pa2m_afirmar(arbol_vacio(arbol_), "EL arbol esta vacio.");
    insertar_enteros(arbol_, enteros, MAXIMO);
    pa2m_afirmar(!arbol_vacio(arbol_), "EL arbol NO esta vacio.");
    for (int i = 0; i < MAXIMO; i++){
        arbol_borrar(arbol_, &enteros[i]);
    }
    pa2m_afirmar(arbol_vacio(arbol_), "Si borro todos los elementos del arbol este pasa a estar vacio.");
    
    arbol_destruir(arbol_);
}
void dadoUnArbolInexistente_SiQuieroRecorrerloInorden_MeDevulevNUll(){
    abb_t* arbol_=NULL;
    size_t array[MAXIMO];
    size_t estado_recorrido_inorden= arbol_recorrido_inorden(arbol_,(void**)array, MAXIMO);
    pa2m_afirmar(estado_recorrido_inorden==0, "A un arbol inexistente no se lo puede recorrer inorden.");
}
void dadoUnArbol_SiQuieroRecorrerloInorden_PuedoHacerloCorrectamente(){
    abb_t* arbol_= arbol_crear(comparador_de_enteros, NULL);
    size_t* array[MAXIMO];
    size_t auxiliar= arbol_recorrido_inorden(arbol_,(void**)array, 0);
    pa2m_afirmar(auxiliar==0, "La cantidad de elementos guardados es 0 ya que el arbol no tenia elementos " );
    
    
    int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
    insertar_enteros(arbol_, enteros, MAXIMO);
    auxiliar= arbol_recorrido_inorden(arbol_,(void**)array, MAXIMO);
    pa2m_afirmar(auxiliar==MAXIMO, "La cantidad de elementos guardados es la correcta " );
    pa2m_afirmar(*(int*)array[0]== enteros[3], "El elemento guardado en la posicion 0 es el esperado");
    pa2m_afirmar(*(int*)array[1]== enteros[6], "El elemento guardado en la posicion 1 es el esperado");
    pa2m_afirmar(*(int*)array[2]== enteros[4], "El elemento guardado en la posicion 2 es el esperado");
    pa2m_afirmar(*(int*)array[3]== enteros[0], "El elemento guardado en la posicion 3 es el esperado");
    pa2m_afirmar(*(int*)array[4]== enteros[7], "El elemento guardado en la posicion 4 es el esperado");
    pa2m_afirmar(*(int*)array[5]== enteros[9], "El elemento guardado en la posicion 5 es el esperado");
    pa2m_afirmar(*(int*)array[6]== enteros[8], "El elemento guardado en la posicion 6 es el esperado");
    pa2m_afirmar(*(int*)array[7]== enteros[1], "El elemento guardado en la posicion 7 es el esperado");
    pa2m_afirmar(*(int*)array[8]== enteros[2], "El elemento guardado en la posicion 8 es el esperado");
    pa2m_afirmar(*(int*)array[9]== enteros[5], "El elemento guardado en la posicion 9 es el esperado");

    arbol_destruir(arbol_);
}
void dadoUnArbolInexistente_SiQuieroRecorrerloPreorden_MeDevulevNUll(){
    abb_t* arbol_=NULL;
    size_t array[MAXIMO];
    size_t estado_recorrido_preorden= arbol_recorrido_preorden(arbol_,(void**)array, MAXIMO);
    pa2m_afirmar(estado_recorrido_preorden==0, "A un arbol inexistente no se lo puede recorrer preorden.");
}
void dadoUnArbol_SiQuieroRecorrerloPreorden_PuedoHacerloCorrectamente(){
    abb_t* arbol_= arbol_crear(comparador_de_enteros, NULL);
    size_t* array[MAXIMO];
    size_t auxiliar= arbol_recorrido_preorden(arbol_,(void**)array, 0);
    pa2m_afirmar(auxiliar==0, "La cantidad de elementos guardados es 0 ya que el arbol no tenia elementos " );
    
    int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
    insertar_enteros(arbol_, enteros, MAXIMO);
    auxiliar= arbol_recorrido_preorden(arbol_,(void**)array, MAXIMO);
    pa2m_afirmar(auxiliar==MAXIMO, "La cantidad de elementos guardados es la correcta " );
    pa2m_afirmar(*(int*)array[0]== enteros[0], "El elemento guardado en la posicion 0 es el esperado");
    pa2m_afirmar(*(int*)array[1]== enteros[3], "El elemento guardado en la posicion 1 es el esperado");
    pa2m_afirmar(*(int*)array[2]== enteros[4], "El elemento guardado en la posicion 2 es el esperado");
    pa2m_afirmar(*(int*)array[3]== enteros[6], "El elemento guardado en la posicion 3 es el esperado");
    pa2m_afirmar(*(int*)array[4]== enteros[1], "El elemento guardado en la posicion 4 es el esperado");
    pa2m_afirmar(*(int*)array[5]== enteros[7], "El elemento guardado en la posicion 5 es el esperado");
    pa2m_afirmar(*(int*)array[6]== enteros[8], "El elemento guardado en la posicion 6 es el esperado");
    pa2m_afirmar(*(int*)array[7]== enteros[9], "El elemento guardado en la posicion 7 es el esperado");
    pa2m_afirmar(*(int*)array[8]== enteros[2], "El elemento guardado en la posicion 8 es el esperado");
    pa2m_afirmar(*(int*)array[9]== enteros[5], "El elemento guardado en la posicion 9 es el esperado");

    arbol_destruir(arbol_);
}
void dadoUnArbolInexistente_SiQuieroRecorrerloPostorden_MeDevulevNUll(){
    abb_t* arbol_=NULL;
    size_t array[MAXIMO];
    size_t estado_recorrido_postorden= arbol_recorrido_postorden(arbol_,(void**)array, MAXIMO);
    pa2m_afirmar(estado_recorrido_postorden==0, "A un arbol inexistente no se lo puede recorrer postorden.");
}
void dadoUnArbol_SiQuieroRecorrerloPostorden_PuedoHacerloCorrectamente(){
    abb_t* arbol_= arbol_crear(comparador_de_enteros, NULL);
    size_t* array[MAXIMO];
    size_t auxiliar= arbol_recorrido_postorden(arbol_,(void**)array, 0);
    pa2m_afirmar(auxiliar==0, "La cantidad de elementos guardados es 0 ya que el arbol no tenia elementos " );
    
    int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
    insertar_enteros(arbol_, enteros, MAXIMO);
    auxiliar= arbol_recorrido_postorden(arbol_,(void**)array, MAXIMO);
    pa2m_afirmar(auxiliar==MAXIMO, "La cantidad de elementos guardados es la correcta " );
    pa2m_afirmar(*(int*)array[0]== enteros[6], "El elemento guardado en la posicion 0 es el esperado");
    pa2m_afirmar(*(int*)array[1]== enteros[4], "El elemento guardado en la posicion 1 es el esperado");
    pa2m_afirmar(*(int*)array[2]== enteros[3], "El elemento guardado en la posicion 2 es el esperado");
    pa2m_afirmar(*(int*)array[3]== enteros[8], "El elemento guardado en la posicion 3 es el esperado");
    pa2m_afirmar(*(int*)array[4]== enteros[9], "El elemento guardado en la posicion 4 es el esperado");
    pa2m_afirmar(*(int*)array[5]== enteros[7], "El elemento guardado en la posicion 5 es el esperado");
    pa2m_afirmar(*(int*)array[6]== enteros[5], "El elemento guardado en la posicion 6 es el esperado");
    pa2m_afirmar(*(int*)array[7]== enteros[2], "El elemento guardado en la posicion 7 es el esperado");
    pa2m_afirmar(*(int*)array[8]== enteros[1], "El elemento guardado en la posicion 8 es el esperado");
    pa2m_afirmar(*(int*)array[9]== enteros[0], "El elemento guardado en la posicion 9 es el esperado");

    arbol_destruir(arbol_);
}
bool funcion_de_prueba(void* abb,void* contador){  
   if(*(int*)contador== MAXIMO){
		return true;
	}
	(*(int*)contador)++;	
	return false;
}
void dadoUnArbol_AlCrearUnIteradorInterno_SeCreaElIterador(){
  abb_t* arbol_= NULL;
  pa2m_afirmar(abb_con_cada_elemento(arbol_, ABB_RECORRER_INORDEN,funcion_de_prueba , 0)==0,"Si el arbol es NULL no se puede iterar" );  
  pa2m_afirmar(abb_con_cada_elemento(arbol_, ABB_RECORRER_INORDEN,NULL , 0)==0, "Si la funcion pasada es NULL no se puede iterar." );
  arbol_= arbol_crear(comparador_de_enteros, NULL);
  int contador=0;
  int enteros[MAXIMO]={10,20,30,4,8,70,6,14,18,18};
  insertar_enteros(arbol_, enteros, MAXIMO);
  abb_con_cada_elemento(arbol_, ABB_RECORRER_INORDEN,funcion_de_prueba , &contador);
  pa2m_afirmar(contador==MAXIMO, "Se itera con recorrido inorden sobre un arbol de 10 elementos");
  for(int i=0; i<MAXIMO;i++){
      arbol_borrar(arbol_, &enteros[i]);
      contador--;
  }
  pa2m_afirmar(contador==0, "Al no haber elementos  devuelve 0 iteraciones ");
  insertar_enteros(arbol_, enteros, MAXIMO);
  abb_con_cada_elemento(arbol_, ABB_RECORRER_PREORDEN,funcion_de_prueba , &contador);
  pa2m_afirmar(contador==MAXIMO, "Se itera con recorrido preorden sobre un arbol de 10 elementos");
  for(int i=0; i<MAXIMO;i++){
      arbol_borrar(arbol_, &enteros[i]);
      contador--;
  }
  pa2m_afirmar(contador==0, "Al no haber elementos  devuelve 0 iteraciones ");
  
  insertar_enteros(arbol_, enteros, MAXIMO);
  abb_con_cada_elemento(arbol_, ABB_RECORRER_POSTORDEN,funcion_de_prueba , &contador);
  pa2m_afirmar(contador==MAXIMO, "Se itera con recorrido postorden sobre un arbol de 10 elementos");
  for(int i=0; i<MAXIMO;i++){
      arbol_borrar(arbol_, &enteros[i]);
      contador--;
  }
  pa2m_afirmar(contador==0, "Al no haber elementos  devuelve 0 iteraciones ");

  arbol_destruir(arbol_);
}



int main(){
    pa2m_nuevo_grupo("Pruebas de ABB");
    pa2m_nuevo_grupo("Pruebas de insertar");
    dadoUnArbolInexistente_SiQuieroInsertarUnElemento_NoPuedoHacerlo();
    dadoUnArbol_SiQuieroInsertarUnElementoNulo_PuedoHacerlo();
    dadoUnArbol_SiQuieroINsertarElementos_PuedoHacerlo();

    pa2m_nuevo_grupo("Pruebas de borrar");
    dadoUnArbolInexistente_SiQuieroBorrarUnElemento_NoPuedoHacerlo();
    dadoUnArbol_SiQuieroBorrarElementos_PuedoHacerloMientrasTengaElementos();

    pa2m_nuevo_grupo("Pruebas de buscar");
    dadoUnArbol_SiQuieroBuscarUnElemento_SiEsteEstaEnElArbolPuedoHacerlo();

    pa2m_nuevo_grupo("Pruebas de raiz");
    dadoUnArbol_SiQuieroConocerLaRaiz_PuedoHacerlo();

    pa2m_nuevo_grupo("Pruebas de vacio");
    dadoUnArbol_SiEstaVacio_MeDevuelveQueLoEsta();

    pa2m_nuevo_grupo("Pruebas de recorrido inorden");
    dadoUnArbolInexistente_SiQuieroRecorrerloInorden_MeDevulevNUll();
    dadoUnArbol_SiQuieroRecorrerloInorden_PuedoHacerloCorrectamente();

    pa2m_nuevo_grupo("Pruebas de recorrido preorden");
    dadoUnArbolInexistente_SiQuieroRecorrerloPreorden_MeDevulevNUll();
    dadoUnArbol_SiQuieroRecorrerloPreorden_PuedoHacerloCorrectamente();

    pa2m_nuevo_grupo("Pruebas de recorrido postorden");
    dadoUnArbolInexistente_SiQuieroRecorrerloPostorden_MeDevulevNUll();
    dadoUnArbol_SiQuieroRecorrerloPostorden_PuedoHacerloCorrectamente();

    pa2m_nuevo_grupo("Pruebas de iterador");
    dadoUnArbol_AlCrearUnIteradorInterno_SeCreaElIterador();

  return pa2m_mostrar_reporte();
}


