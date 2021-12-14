Especificação


#Especificações do trabalho prático 0

Este trabalho é em dupla e você deverá criar um programa para gerar obras de arte aleatórias. Para isso, o programa deverá imprimir um quadro na tela de 20 linhas por 80 colunas. Na primeira e última linhas deverá ser impresso o símbolo '-' em todas as 80 colunas. Na primeira e última coluna deverá ser impresso o símbolo '|' em todas as linhas, com exceção da primeira e última que já irão conter o símbolo '-'. Desta forma estará delimitado o quadro para a obra de arte aparecer.

A obra de arte deverá ser gerada a partir de 3 figuras básicas:

Asterisco simples:    

*
                                                              
Símbolo de soma com asteriscos:         

 *
***
 *

Letra X com asteriscos: 

* *
 *
* *

No início do programa, o usuário irá escolher qual tipo de figura básica irá utilizar em seu quadro. Poderá escolher apenas uma das três, ou então uma mistura aleatória das três. Logo em seguida irá escolher quantas figuras serão utilizadas para a geração do quadro. Se o usuário digitar um número menor ou igual a zero, será gerado um número de figuras aleatório entre 1 e 100. Se o usuário digitar um número maior do que 100, será considerado o número 100. Exemplo de menu inicial do programa com estas opções (o que está sublinhado foram os dados digitados pelo usuário):

PROGRAMA GERADOR DE OBRA DE ARTE:
=================================
Escolha o tipo de figura basica a ser usada para criar a obra:
1 - asterisco simples.
2 - simbolo de soma com asteriscos.
3 - letra X com asteriscos.
4 - figuras aleatorias
5 ou qualquer outro numero – opcao de obra de arte criada pelo aluno
Digite o tipo de figura basica desejada: 1
Digite a quantidade de figuras (menor ou igual a zero para aleatorio): 5
Após a digitação destas opções o programa irá então gerar e imprimir na tela o quadro, solicitando ao final a opção de fazer um novo quadro com estes mesmos valores. O novo quadro poderá ser diferente, uma vez que a posição em que cada figura será colocada no quadro sempre é aleatória. Se a posição aleatória gerada já estiver ocupada por uma figura gerada anteriormente, uma nova posição aleatória deverá ser gerada. Não pode haver conflito com nenhuma parte das figuras anteriores, nem mesmo com um único asterisco. Outra restrição é que todas as figuras devem aparecer completamente (não pode ser impresso por exemplo um pedaço de uma letra X), e sempre dentro do quadro delimitado pelos símbolos '-' e '|'.

A opção 5 deverá ser criada pelos alunos, criando uma obra de arte específica, inventada pelos alunos, sendo obviamente diferente dos demais alunos. A criatividade será avaliada, e esta opção deverá ser feita de uma forma que obrigatoriamente também utilize números aleatórios. A utilização de números aleatórios não precisa ficar restrita a apenas as posições em que aparecerão as figuras, podendo também influenciar nas próprias figuras geradas.

Exemplos de saída:
Valores: tipo de figura: 1, número de figuras: 50
--------------------------------------------------------------------------------
|*   *                                                   *                     |
|           * *                                                                |
|        *     *                                                *              |
|                             *                     *                          |
|                                         *                                    |
|                **                *                                         * |
|                                                 *                           *|
|                                  *                             *             |
|*                 *            * *                                      *     |
|                                   * **                                       |
|                 *                                          *                 |
|*                                                                 *   *       |
|      *            *                       *                                  |
|                                                                    *         |
|                *           *                      *                          |
|    *               *                     *                       *           |
|       *           *          **                       *                      |
|                                                 *                       *    |
--------------------------------------------------------------------------------
Valores: tipo de figura: 2, número de figuras: 20
--------------------------------------------------------------------------------
|                                                                              |
|                                           *                  *               |
|                                          ***                ***              |
|                                           *                  *               |
|                                                     *                        |
|     *                                              ***             *         |
| *  ***                                              *  *          ***        |
|***  *                                             *   ***          *         |
| *                                                ***   *                     |
|      *                                            *                          |
|     ***      *                                                               |
|      *      ***             *              *          *   *                  |
|              *             ***            ***        *** ***                 |
|    *       *                *            * *          *   *                  |
|   ***     ***             *             ***  *                               |
|    *       *             ***          *  *  ***                              |
|                           *          ***     *                               |
|                                       *                                      |
--------------------------------------------------------------------------------


Valores: tipo de figura: 3, número de figuras: 15
--------------------------------------------------------------------------------
|* *                                                                           |
| *    * *                                 * *  * *    * *                     |
|* *    *                                   *    *      *                      |
|      * *                                 * *  * *    * *                     |
|                                                                              |
|                                  * *    * * * *                              |
|                                   *      *   *                               |
|                                  * *    * * * *                              |
|                                                                         * *  |
|                * *                                       * *             *   |
|                 *                * *                      *      * *    * *  |
|                * *     * *        *                      * *      *  * *     |
|                         *        * *                             * *  *      |
|                        * *                                           * *     |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
--------------------------------------------------------------------------------


Valores: tipo de figura: 4, número de figuras: 10
--------------------------------------------------------------------------------
|                                                                              |
|                                                                              |
|               * *                                                            |
|                *                                  * *                        |
|               * *                                  *                         |
|                                                   * *                        |
|                                *                                             |
|                               ***                                            |
|                                *                    *                        |
|                                                                              |
|                                                                              |
|               *                                                      *       |
|              ***                   * *                                       |
|               *                     *                        *               |
|                                    * *                      ***              |
|     * * * *                                                  *               |
|      *   *                                                                   |
|     * * * *                                                                  |
--------------------------------------------------------------------------------


O que deverá ser entregue:

Os arquivos com o código-fonte (projeto inteiro do Codeblocks ou arquivos .c, .h e makefile), juntamente com um arquivo PDF (testado, para ver se não está corrompido) contendo a documentação. A documentação deverá ter pelo menos as explicações das partes mais relevantes do trabalho, como por exemplo como foram usados os números aleatórios no trabalho, bem como as decisões para se implementar a parte criada pelos próprios alunos. Mais direcionamentos sobre o formato da documentação podem ser vistos no documento “Diretrizes para relatórios de documentação”, também disponível no AVA.

O que deverá ser apresentado no dia 15/12/2021: apenas a execução da parte específica, ou seja, da obra de arte criada pela dupla. Tempo de apresentação: 3 a 4 minutos.

#Diretrizes de entrega de trabalho

É importante atender a estes tópicos: 

1) Capa ou cabeçalho com dados do aluno e disciplina, sumário, e pelo menos as seções introdução, desenvolvimento e conclusão.
2) Falar um pouco do problema e que caminho seguiu para solucioná-lo (em alto nível).
3) Falar um pouco da implementação em si, mostrando possíveis trechos de código que mereçam atenção, também com explicações, e não parafraseando o código.
4) Mostrar testes com o programa, com screenshots com descrições do que está acontecendo.
5) Decisões tomadas durante o desenvolvimento do trabalho, relativas ao próprio funcionamento, relativas à implementação, limitações e/ou alterações justificadas (falar por exemplo o que funciona e o que não funciona), etc.
6) Conclusão. Interessante resumir aqui aprendizados com o trabalho e resultados.
7) Trabalhos que exijam algo específico/diferente de cada aluno ou dupla: mostrar em detalhes esta parte, descrevendo implementação e resultados. Esta é uma parte importante nas avaliações dos trabalhos.
8) Referências: colocar o que você leu/estudou para fazer o trabalho. 

O que NÃO fazer:

1) Copiar toda a especificação do TP. É melhor apenas uma descrição em alto nível, e só do essencial.
2) Entregar em formatos diferentes de PDF ou PDF corrompido, ou entregar fora do PVANet Moodle.
3) Entregar um arquivo compactado (zip, tar.gz, etc) corrompido! Dica: Para garantir que não esteja corrompido, após fazer a entrega, faça o download do arquivo entregue e faça a descompactação.
4) Usar palavras como logar, printar, rodar, etc.
5) Usar muito texto corrido. O ideal é mesclar com figuras, screenshots, trechos de código.
6) Ter figuras soltas no documento. O ideal inclusive é numerar as figuras e referenciá-las no texto. Não precisa usar todas as normas ABNT, mas isso é importante.
7) Escrever pouco, sem analisar nada, sem referenciar nada (código, screenshot, figura criada para descrever algo).

