
*Un Readme.txt donde explique el TDA implementado. Explique qué es una árbol, árbol binario y árbol binario
de búsqueda. Explique por qué es importante la distinción de cada uno de estos conceptos.


Un arbol es una coleccion de nodos. Los nodos son los elementos o vertices del arbol.  Esta coleccion puede estar vacıa, o puede que consista
de un nodo destacado, llamado raız, que puede tener 0 o varios sub-arboles no vacios conectados a la raiz , donde cada uno de ellos esta
conectado a una raiz. Esta conexion que tiene el nodo raiz a a sus sub-arboles esta hecha por lo que se denomina el nodo hijo. Y a su vez
el nodo hijo esta conectado a la raiz a traves del nodo padre.
Los arboles binarios son un tipo de arbol que se encunetra muy relacionado con el concepto de la busqueda binaria ya que en este tipo de
operaciones uno debe saber donde seguir buscando, si a la derecha o a la izquierda de un determinado valor y en el caso de los arboles
binarios se permite la nocion de derecha izquierda abstrayendo ese comportamiento propio de este tipo de  busqueda .Un arbol binario
puede estar vacıo, o consistir en un nodo llamado raız conjuntamente con dos arboles binarios uno llamado derecha y otro llamado
izquierda ambos respecto del nodo raız. Las operaciones basicas de un arbol binario son: crear, destruir , vacio,insertar, eliminar,
buscar y recorrer. Este tipo de arboles tiene multiples formas de recorrerse las 3 principales son : Preorden, Postorden e Inorden.
En el caso de recorrido preorden primero se visita el nodo actual luego el sub-arbol izquierdo y luego el derecho( se suele utilizar
cuando se quiere clonar un arbol), cuando se recorre postorden primero se visita el sub-arbol izquierdo, luego al sub-arbol derecho
y por ultimo al nodo actual( sirve para destruir el arbol) y cuando es Inorden primero se visita el sub-arbol izquierdo, luego el nodo
actual y por ultimo el sub-arbol derecho. Este ultimo recorrido sirve para obtener todos los elementos del arbol ordenados de menor
a a mayor.
Los arboles binarios de busqueda son arboles binarios a los que se les han agregado mejoras. Una de ellas es que se le agrega un
comparador que lo que hace es que al valor que almacena  cada nodo que vos tenes en el arbol le asigna un valor unico o si no puede ser
asi le asigna una clave asociada que sea unica. De esta manera podemos diferenciar y empezar a ordenar segun el criterio que nos devuelva
el comparador , dicho esto se va a establecer que los sub-arboles derechos van a contener valores mayores que la raiz y los sub-arboles
izquierdos valroes menores a la raiz. Estos permiten tener las ventajas de las listas enlazadas y ademas obtener la velocidad de
la busqueda binaria mediante el aprovechamiento de la estructura misma del arbol. Las operaciones basicas de un arbol binario son: crear,
destruir, vacio , insertar, eliminar, buscar, recorrer. En la operacion de buscar la busqueda de un elemento comienza en el nodo raız
y consta de 3 pasos. Primero la clave buscada se compara con la clave del nodo raız, si las claves son iguales, la busqueda se detiene y
si la clave buscada es mayor que la clave raız, la busqueda se reanuda en el sub-arbol derecho o si la clave buscada es menor que la clave
raız, la busqueda se reanuda en el sub-arbol izquierdo. En la operacion de insertar lo que se hace es comparar la clave del elemento a
insertar con la clave del nodo raız, si es mayor avanzar hacia el sub-arbol derecho, si es menor hacia el izquierdo. Repite el paso anterior
hasta encontrar un elemento con clave igual o llegar al final del sub-arbol donde debiera situarse el nuevo elemento. Cuando se llega al
final es porque no se ha encontrado, por tanto se debera reservar memoria para una nueva estructura nodo, se introduce en la parte
reservada para los datos los valores del nuevo elemento y se asigna nulo a los punteros izquierdo y derecho del mismo. Luego se colocara
el nuevo nodo como hijo izquierdo o derecho del anterior segun sea el valor de su clave comparada con la de aquel. En la operacion de
eliminar la eliminacion de un nodo es tambien una extension de la operacion de busqueda. El borrado de un elemento requerira, una vez
buscado, considerar las siguientes posibilidades:Que no tenga hijos( sea hoja). En ese caso se suprime, asignando nulo al puntero de su
antecesor que antes lo apuntaba a el. Que tenga un unico hijo. En ese caso el elemento anterior se enlaza con el hijo del que queremos
borrar. Que tenga dos hijos. En ese caso se sustituye por el elemento mas proximo en clave, inmediato superior o inmediato inferior.
Para localizar estos elementos debe situarse en el hijo derecho del nodo a borrar y avanzar desde el siguiendo la rama izquierda de
cada nodo hasta que a la izquierda ya no haya ningun nodo mas, o bien, situarse en el hijo izquierdo y avanzar siguiendo siempre la rama
derecha de cada nodo hasta llegar al final. Es muy importante conocer las caracteristicas de cada uno de estos tipos de arboles ya que
de esta manera dependiendo de que es lo que queramos hacer teniendo en cuenta las diferencias podremos elegir cual nos conviene o es el que
tenemos que implementar y a su vez sabiendo como se comporta podemos asi implementarlo.


*El Readme.txt deberá contener también una explicación de la solución implementada. Este archivo le sirve a
su corrector para saber si entendió o no el tema. Explique la implementación como si se lo estuviese explicando
a alguien que no sabe del tema. Explique las decisiones que tomó al implementar las primitivas. Si hizo alguna
suposición para resolver el TP (ya sea por enunciado poco claro o cualquier otro motivo) también explı́quela.

Bueno para implementar este TDA ABB lo primero que hice fue responder la pregunta teórica para poder repasar y tener bien en claro
 qué es lo que iba a implementar. Una vez que tuve eso lo que hice fue pasar a hacer dibujos de cada una de las primitivas en especial
 dibuje sobre las de  insertar , borrar y también sobre los recorridos inorden, preorden y postorden. Lo primero que hice fue crear un 
árbol crear y con eso fijarme que se podía crear un árbol haciendo una prueba. Una vez que logre que pasara esa prueba pase a hacer
 árbol insertar lo primero que hice fue hacer varias pruebas donde corroboraba que: si tenía un árbol inexistente no pudiera insertar un
 elemento, si tenía un árbol que pudiera insertar un elemento nulo, que si tuviera un árbol pudiera insertar muchos elementos y que 
estos se insertarán en las posiciones correspondientes. A su vez verifique que se aceptarán repetidos y en la creación de estas 
pruebas realice las primitivas de arbol_raiz y arbol_vacio para así usarlas al momento de testear. Una vez que hice estas pruebas lo 
que hice fue pasar a hacer el código para esta función . Para esto cree un par de funciones auxiliares: una de esas que me creara 
nuevos nodos a medida que iba insertando elementos en el árbol otra que me recorriera el árbol buscando la posición en la que se
 tenía que insertar dicho elemento . Luego use estas funciones en arbol_insertar . Una vez que pasaron todas las pruebas de esa 
categoría realice las pruebas para arbol_borrar. En estas tuve en cuenta que no se pudiera borrar de un árbol inexistente y que si 
tuviéramos un árbol con muchos elementos se pudieran borrar cada uno de ellos, también probé tener un árbol con elementos y borrar
 la raíz o un elemento que no sea hoja. Luego para realizar arbol_borrar cree funciones auxiliares. Como por ejemplo las de verificar si 
el nodo es hoja , si tiene dos hijos, la de buscar el predecesor inorden , la de buscar el padre del predecesor inorden, la de destruir los
 nodos que se eliminan, la de acomodar el árbol cuando se elimina un elemento y asi despues poder hacer uso de ellas al momento de
 borrar el elemento. Una vez que pasaron estas pruebas realice árbol buscar, para esto en pruebas.c corrobore que al insertar un árbol
 se pudieran encontrar cada uno de sus elementos y que si se pudiera encontrar un elemento que no estuviera en el árbol me 
devolviera null. Para implementar esta primitiva cree la función buscar_elemento que me recorriera el árbol y vaya comparando el 
elemento a buscar y los elementos del árbol hasta que sean iguales(osea que haya encontrado el que buscaba). Ya teniendo todas 
esas funciones testeadas pase a hacer los recorridos inorden preorden y postorden . Para los 3 casos hice pruebas similares, verifique
 que no se pudiera recorrer de ninguna de las tres formas un árbol inexistente, que la cantidad de elementos guardados en el array sea
 la esperada en distintos casos, y que los elementos que hayan sido guardados respetaran el orden esperado en base a las 
condiciones que tiene cada uno de los tres recorridos. Pasando al código , crea una función auxiliar para cada uno de los recorridos 
que a medida que avanzaban en el árbol(cada uno como corresponde) fueran guardando los elementos en un array. Y por último 
realice las pruebas del iterador interno , para esto  cheque que el iterador no permite iterar sobre un árbol nulo o si se le pasaba una
 función nula, también que si se le insertaba un árbol con 10 elementos iterara sobre esos 10 elementos en cada uno de los recorridos y que si no hubieran elementos en un árbol me devolviera 0 iteraciones. Para el código cree 3 funciones auxiliares que recorrieran el 
árbol de la manera correspondiente hasta recorrerlo entero o hasta donde tuviera que ser. Después en el iterador lo que hice fue crear 
contadores para cada uno de los recorridos y de esa manera que me devuelva la cantidad de iteraciones. 
