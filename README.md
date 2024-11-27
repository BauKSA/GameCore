## UPDATE 25-11-24 11:56
Agregué un InputHandler que, aunque no es definitivo y tiene bastantes limitaciones, funciona y voy 
a dejar hasta que pueda conseguir uno que tenga el funcionamiento que espero y sea lo más eficiente 
posible.

## UPDATE 25-11-24 16:39
Ahí dejé funcionando el componente de salto. Tuve que hardcodear una "colisión" hasta que esté completo dicho sistema, pero bueno... queda 
bien para probar salto y gravedad. Hay unas pequeñas fluctuaciones en la altura del salto, que asumo que tendrán que ver con cómo se maneja 
delta_time, pero ya habrá tiempo para solucionarlas. La base del sistema está hecha.

## UPDATE 25-11-24 17:52
Corregido el tema fluctuaciones en el salto y frame rate.

## UPDATE 27-11-24 16:40
Costó, pero al fin puedo decir que está un 90% terminado el CollisionSystem. Falta únicamente la colisión del "techo" del actor 1 con el "suelo 
del otro", pero como por ahora no le doy uso a eso, lo dejo para más adelante y le meto a cosas que creo más relevantes. También quedan algunas 
correcciones para perfeccionar el sistema, pero son minor issues.

#### UPDATE 27-11-24 18:00
Metí un refactor importante a las clases Actor, eliminando ComplexAnimatedActor, cambiando nombres de variables y métodos y ordenando un poco mejor todo. 
Estoy viendo de meter una mini documentación para cada una.