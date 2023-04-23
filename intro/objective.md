Objetivo: 

Um objeto foi pré descrito geométricamente por um conjunto de arestas, 
usando o sistema de referência do objeto (SRO)

<img src="/temp/SRO.png">


Objetivo: 
gerar a imagem do objeto de acordo com o sistema de referência da câmera (SRC), 
que seria um recorte da imagem em questão. Como a imagem é 2D, esse recorte é um
retângulo - nesse caso, uma janela do openGL, onde conseguiremos ver o objeto de frente

Antes, precisamos converter o sistema de referência RPO (do objeto) para RPU (em
referência ao 'universo')
![RPU](https://user-images.githubusercontent.com/86981064/233833177-d9848361-0630-466e-8cd5-ce2e68a55eec.png)


