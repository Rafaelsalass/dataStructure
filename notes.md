###**to do:**###
* revisar el codigo en multilistas.rar (esta en el correo)

**multilistas:**

se hace una composicion, donde una lista incluya objetos que contienen listas.
por ejemplo un departamento con una lista de productos.
de tal menra que yo creo una lista de despartamento (siendo esta mi lista externa)
com dentro de departamento tengo una lista de productos entoces tendria una lista de departamentos con cada uno de los
productos (en una lista).

**regla importante:**
el pbjeto compuesto debe ser un puntero.
Lo que esta anidado debe ser manipulado por un puntero.

`linkedList<departamento> tienda;`

dentro de la clase departamento:

`linkedList<producto> *subList;`

existe la necesidad de manejar nodos especializados:
`node<departamento> *p; //para apuntar a los departamentos de mi lista`

`node<productos> *q; // para apuntar a los productos dentro de los departamentos.`

progrmar el metodo getHead():

```c++
node<t>* linkedList<t>::getHead(){
  return head;
  //con este metodo abro la puerta para hacer manejo de la lista fuera de ella.
}
```

Parar el examen:**(sabado 12)**
* listas dinamicas: simple y doble enlazada. (DONE).
* colas dinamicas y circulares. FALTA LA CIRCULAR.
* pilas dinamicas y circulares. FALTA LA CIRCULAR.
* colas de prioridad. (DONE).
* bicolas.
* multilistas


##Colas de prioridad: como hacer un lista ordenada per en lugar de ordenar por la informacion.
ordeno por la prioridad. En la clase del objeto debo tner un atributo prioridad.
En el metodo de eliminar recibo una bandera para saber si debo eliminar lo que tienen mayor prioridad.
Si no se envia en elemento a eliminar la prioridad que debo tomar en cuenta para eliminar uso este valor en lugar de
la que tenga mayor prioridad.

hacer un metodo para saber si existen elemntos con la prioridad que quiero eliminar.

* elimina el principio FIFO
* Los datos de la cola son eliminados para su procesamiento en orden de prioridad o nivel de urgencia

Se puede hacer con una lista enlazada o doble enlazada y se puede hacer con una lista con nodos de cola.


###Para el ejercicio del interprete:
* pasar del archivo a la lista ordenada
* imprimir la lista (progrma ordenado)
* Imprimir cada instruccion en orden de ejecucion (usando una pila de direcciones de nodo de instruciones)

###Recorrido en el arbol:

###tipos:

* En profundidad:
desplazar un puntero desde la raiz hacia las hojas, pasando por las ramas (este es el recorrido mas común)
se usa recursividad para hacer el backtraking en el arbol para moverme a nodos en niveles superiores, recorrido con multipropositos
una hoja es el caso base, tenemos: preorden, inorden, postorden.


```c++

  //recorrido en profundida preorden
  template <class t>
  void arbolbb<t>::preorden(nodea<t>* p, int niv){
    for(int i = 0; i < niv; i++){
      cout << "  ";
     }
    cout << p->getInfo() << endl;
    if(p->getHI()){
      preorden(p->getHI(), niv + 1);
    }
    if(p->getHD()){
      preorden(p->getHD(), niv + 1);
    }
  }
  
  template <class t>
  void arbolbb::imprimir(){
    if(!raiz){
      return;
    }
    preorden(raiz, 0);
  }
```

* En anchura: 
deasplazar un puntero desde la raiz, procesando sus hijos y se avanza al siguiente nivel o capa cunado la totalidad de hijos y/o
primos sean procesados.
