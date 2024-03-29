#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

class fisica
{
public:
    //Atributo que guarda referencia do quadro a ser utilizado em cada passo.
    int* quadro;
    //Atributo que guarda tamanho do quadro, para que seja possivel iterar sobre este
    int quadro_tamanho;

    /**
     * @brief Chama métodos responsáveis pela codificação da mensagem
     * de acordo com o valor definido dentro do próprio método
     */
    void CamadaFisicaTransmissora();

    /**
     * @brief Simplesmente transmite o quadro que foi codificado
     * com codificação binária
     */
    void CamadaFisicaTransmissoraCodificacaoBinaria();

    /**
     * @brief Realiza a codificação Manchester para a transmissão
     * Para simular o clock, a cada bit da mensagem foi feito uma
     * operação de XOR com o bit 0 e em seguida com o bit 1. O 
     * resultado dessas operações formam uma nova mensagem com dobro 
     * de tamanho e então à transmitem.
     */
    void CamadaFisicaTransmissoraCodificacaoManchester();

    /**
     * @brief Realiza a codificação Manchester Diferencial para a
     * transmissão
     * Para simular o clock, juntamente com a codificação é utilizado
     * um bit de referência e então, é feita a operação de XOR neste
     * bit com o valor 0 e 1, e o resultado dessas operações formam a
     * mensagem codificada. Caso o bit de mensagem seja 1, o valor do
     * bit de refência é invertido (de 0 para 1 ou de 1 para 0) e 
     * então é feita a mesma operação de XOR e o resultado é adicionado
     * à mensagem 
     * 
     */
    void CamadaFisicaTransmissoraCodificacaoManchesterDiferencial();

    /**
     * @brief Chama métodos responsáveis pela decodificação da mensagem
     * de acordo com o valor definido dentro do próprio método
     */
    void CamadaFisicaReceptora();

    /**
     * @brief Realiza a decodificação binária verificando se 
     * algum bit é diferente de 0 ou 1 e, caso seja, devolve uma 
     * mensagem de erro e descarta a mensagem. Caso a mensagem 
     * esteja correta, salva o quadro
     */
    void CamadaFisicaReceptoraDecodificacaoBinaria();

    /**
     * @brief Realiza a decodificação Manchester verificando se
     * alguma sequencia de bits tomados dois a dois é diferente
     * de '01' ou '10' e, caso seja, devolve uma mensagem de 
     * erro e descarta a mensagem. Caso a mensagem esteja correta,
     * salva o quadro
     */
    void CamadaFisicaReceptoraDecodificacaoManchester();

    /**
     * @brief Realiza a decodificação Manchester Diferencial 
     * verificando se alguma sequencia de bits tomados dois a dois
     * é diferente de '01' ou '10' e, caso seja, devolve uma 
     * mensagem de erro e descarta a mensagem. Caso seja '10', o
     * bit de referencia é invertido e a decodificação também. 
     * Caso seja '01' apenas prossegue com a decodificação
     * 
     */
    void CamadaFisicaReceptoraDecodificacaoManchesterDiferencial();

    /**
     * @brief Simula a comunicação entre um ponto A e B. Por questão
     * de simplificação, a comunicação é realizada dentro da própria
     * classe instanciada, realizando chamadas de métodos
     */
    void MeioDeComunicacao();

    /**
     *  @brief Construtor da classe fisica, recebe o quadro incial como 
     *  parametro
     */
    fisica(int* quadro, int quadro_tamanho);

    /**
     *  @brief Destrutor da classe fisica, libera espaços de memória alocados
     *  ao decorrer do processo
     */
    ~fisica();
};

