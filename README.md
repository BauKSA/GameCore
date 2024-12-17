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

## UPDATE 13-12-2024 20:20
Bueno, hoy hice unos refactors importantes. Pasé varias cosas de raw a smart pointers y mandé algunas mejoras al sistema de colisión. La idea es separar un poco más las responsabilidades y acomodar y limpiar la clase BaseActor.

# UPDATE 16-12-2024 22:45
## ME VOLVÍ COMPLETAMENTE LOCO??
Bueno, puede ser... analizando varios aspectos y aprovechando que el proyecto está en una fase todavía inicial, decidí cambiar de ALLEGRO a SFML. Esto significa (al menos por ahora) el fin de una etapa... crecí programando con ALLEGRO, pero siento que ya es momento de pegar el salto y animarme a una librería un poco más compleja y fuerte en ciertos aspectos.
Igualmente, una cosa me hace sentir bastante bien. Hice toda la migración en UN DÍA. Qué significa esto?? No sé, pero siento que el código y la estructura está bastante bien armada, porque solamente tuve que modificar la carga de sprites y la creación de la ventana (más algunos detalles menores). Eso habla bien de lo que estoy armando?? Espero que sí.
Pero bueno... veremos cómo sigue todo. Espero poder seguir sumando funcionalidades a este Core, que ya tuvo su debut (aún cuando estaba con ALLEGRO) con este juego, y siento que quedó bastante bien, por más que haya cosas obvias por pulir (algunas de las cuales ya corregí en los últimos commits): https://fox-hushen.itch.io/reindeers-and-hearths.
