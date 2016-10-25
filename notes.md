####**to do:**####
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

Parar el examen en papel:
* listas dinamicas: simple y doble enlazada.
* colas dinamicas.
