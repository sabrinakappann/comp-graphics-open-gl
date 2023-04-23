Objetivo: 

Um objeto foi pré descrito geométricamente por um conjunto de arestas, 
usando o sistema de referência do objeto (SRO)

<img src="/temp/SRO.png">


Objetivo: 
gerar a imagem do objeto de acordo com o sistema de referência da câmera (SRC), 
que seria um recorte da imagem em questão. Como a imagem é 2D, esse recorte é um
retângulo - nesse caso, uma janela do openGL, onde conseguiremos ver o objeto de frente


O SRC vai ser um quadrado entorno da entidade de interesse. Para isso, será feita
uma transformação no sistema de coordenadas originais,
de fora que os vértices ficam:
A = 0.5, 1.5
B = 1.5, 1.5
C = 1.5, 0.5
D = 0.5, 0.5
E = 1, 2

<img src="/temp/SRC.png">

