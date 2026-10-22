#include <stdio.h>

void maiorMenor(int **matriz, int linhas, int colunas,
                int lin, int col, int *maior, int *menor) {

    // Caso base:
    // já percorremos todas as posições da matriz
    if(lin == linhas)
        return;

    // Compara o elemento atual com o maior e o menor
    if(matriz[lin][col] > *maior)
        *maior = matriz[lin][col];

    if(matriz[lin][col] < *menor)
        *menor = matriz[lin][col];

    // Se ainda não chegou na última coluna,
    // avança para a próxima coluna
    if(col < colunas - 1) {

        maiorMenor(matriz, linhas, colunas,
                   lin, col + 1, maior, menor);

    } else {

        // Chegou ao final da linha.
        // Vai para a primeira coluna da próxima linha.
        maiorMenor(matriz, linhas, colunas,
                   lin + 1, 0, maior, menor);
    }
}

int main() {

    int linhas = 3;
    int colunas = 3;

    int matriz[3][3] = {
        {5, 2, 9},
        {1, 7, 3},
        {8, 4, 6}
    };

    int maior = matriz[0][0];
    int menor = matriz[0][0];

    maiorMenor((int **)matriz, linhas, colunas,
               0, 0, &maior, &menor);

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}

/*
Questão 1 [01:26]
Enunciado: Um funcionário de uma filial está fazendo um orçamento para um cliente. Para isso, ele precisa acessar informações confidenciais 
sobre preços que estão nos servidores internos da sede principal. A que tipo de rede o funcionário deve acessar?

Resposta Correta: Intranet

Questão 2 [02:11]
Enunciado: Quais são os dois critérios utilizados para selecionar um meio de rede entre vários meios disponíveis? (Escolha duas opções)

Respostas Corretas:

A distância que o meio selecionado pode transportar um sinal com êxito.

O ambiente em que o meio selecionado deve ser instalado.

Questão 3 [02:55]
Enunciado: Associe os requisitos de uma rede confiável à sua definição/arquitetura correspondente:

Escalabilidade: Expandir a rede sem degradar o serviço para os usuários existentes.

Tolerância a falhas: Fornecer links e dispositivos redundantes.

Segurança: Proteger a rede contra acessos não autorizados.

Questão 4 [03:47]
Enunciado: Qual dos seguintes comandos ou combinações de teclas permite que um usuário retorne ao nível anterior na hierarquia de comandos do Cisco IOS?

Resposta Correta: exit

Questão 5 [04:07]
Enunciado: Quais das seguintes opções são três características de uma SVI (Switch Virtual Interface)? (Escolha três opções)

Respostas Corretas:

Não está associada a uma interface física do switch.

Fornece um meio de gerenciar o switch remotamente.

Está associada à VLAN 1 por padrão.

Questão 6 [04:37]
Enunciado: Quais são os dois nomes de host (hostnames) que atendem às convenções de nomenclatura em dispositivos Cisco IOS? (Escolha duas opções)

Respostas Corretas:

Nomes estruturados sem espaços e com separadores válidos (ex.: Floor1-Switch2 e Branch-2 — nomes sem espaços e sem caracteres especiais proibidos como @ ou ?).

Questão 7 [05:34]
Enunciado: Podem ser usadas senhas para restringir o acesso a todo ou parte do Cisco IOS. Selecione os modos e interfaces que podem ser protegidos
por senha: (Escolha três opções)

Respostas Corretas:

Modo EXEC Privilegiado (enable secret / enable password)

Interface VTY (linhas de terminal virtual para Telnet/SSH)

Interface de Console (line console 0)

Questão 8 [05:59]
Enunciado: Depois de fazer alterações na configuração de um switch Cisco, o administrador executa o comando copy running-config startup-config.
O que acontece ao executar esse comando?

Resposta Correta: Se o switch for reiniciado, a nova configuração será carregada (pois foi salva na NVRAM).

Questão 9 [06:39]
Enunciado: Quais são duas características da memória RAM em um dispositivo Cisco? (Escolha duas opções)

Respostas Corretas:

O conteúdo da RAM é perdido quando o dispositivo é desligado ou reiniciado (memória volátil).

O arquivo de configuração que está atualmente em execução (running-config) fica armazenado na RAM.

Questão 10 [07:20]
Enunciado: Qual destas interfaces permite o gerenciamento remoto de um switch de Camada 2?

Resposta Correta: A interface virtual do switch (SVI / Switch Virtual Interface)

Questão 11 [07:39]
Enunciado: Um técnico configura um switch acessando a interface vlan 1, inserindo um endereço IP com máscara e o comando no shutdown. 
O que o técnico está configurando?

Resposta Correta: SVI (Switch Virtual Interface)

Questão 12 [07:56]
Enunciado: No comando show running-config, que parte da sintaxe é representada por running-config?

Resposta Correta: Palavra-chave (keyword) (enquanto show é o comando).

Questão 13 [08:34]
Enunciado: (Consulte a imagem) Um administrador está configurando o controle de acesso ao Switch 1. Se o administrador usar uma conexão via cabo console, 
qual senha será solicitada para acessar o modo EXEC Usuário?

Resposta Correta: A senha definida sob line con 0 (no exemplo do vídeo: letmein).

Questão 14 [09:22]
Enunciado: Ao tentar resolver um problema de rede, um técnico fez várias alterações na configuração atual que pioraram a situação. Nenhuma alteração foi salva. 
O que o técnico pode fazer para descartar essas alterações e restaurar a configuração anterior da NVRAM?

Resposta Correta: Executar o comando reload sem salvar a configuração em execução.

Questão 15 [10:08]
Enunciado: Qual comando é usado para verificar o resumo do status de todas as interfaces do dispositivo, incluindo endereço IP atribuído e se estão operacionais?

Resposta Correta: show ip interface brief

Questão 16 [10:24]
Enunciado: Qual comando no modo de configuração global impede que senhas não criptografadas sejam exibidas em texto claro nos arquivos de configuração?

Resposta Correta: service password-encryption

Questão 17 [10:51]
Enunciado: Qual método permite que um computador reaja e tome uma ação quando solicita dados de um servidor e este demora muito para responder?

Resposta Correta: Tempo limite de resposta (Response Timeout)

Questão 18 [11:09]
Enunciado: Quais três protocolos da camada de aplicação fazem parte da suíte TCP/IP? (Escolha três opções)

Respostas Corretas:
DNS
DHCP
FTP

Questão 19 [11:38]
Enunciado: Um cliente web está recebendo a resposta de uma página web vinda de um servidor. Do ponto de vista do cliente receptor, 
qual é a ordem correta da pilha de protocolos usada para decodificar (desencapsular) a transmissão recebida?

Resposta Correta: Ethernet → IP → TCP → HTTP (Camada de Enlace → Rede → Transporte → Aplicação)

Questão 20 [12:09]
Enunciado: Qual afirmação sobre protocolos de rede é correta?

Resposta Correta: Eles definem como as mensagens são trocadas entre a origem e o destino.

Questão 21 [12:52]
Enunciado: Ao configurar manualmente o IPv4 em um servidor, qual parâmetro identifica as porções de rede e de host de um endereço IP?

Resposta Correta: Máscara de sub-rede (Subnet Mask)

Questão 22 [13:19]
Enunciado: Qual formato de PDU é utilizado quando a placa de rede (NIC) de um host recebe bits do meio físico de transmissão?

Resposta Correta: Quadro (Frame / Trama)

Questão 23 [13:45]
Enunciado: (Consulte a ilustração) O Servidor B precisa enviar dados para o Host A, que está localizado em uma rede remota diferente. 
Quais duas afirmações identificam corretamente o endereçamento gerado pelo Servidor B? (Escolha duas opções)

Respostas Corretas:

O Servidor B gerará um quadro com o endereço MAC de destino do Router B (Gateway padrão).

O Servidor B gerará um pacote com o endereço IP de destino final do Host A.

Questão 24 [14:57]
Enunciado: Qual processo envolve colocar uma PDU dentro de outra PDU conforme os dados descem as camadas da rede?

Resposta Correta: Encapsulamento (Encapsulation)

Questão 25 [15:06]
Enunciado: No modelo TCP/IP, qual camada é responsável por rotear as mensagens através de diferentes redes interconectadas?

Resposta Correta: Internet (equivalente à camada de Rede no modelo OSI)

Questão 26 [15:25]
Enunciado: Em qual camada do modelo OSI é adicionado um endereço lógico (como endereço IPv4 ou IPv6) durante o processo de encapsulamento?

Resposta Correta: Camada de Rede (Camada 3)

Questão 27 [15:44]
Enunciado: Qual das seguintes é uma característica das mensagens de multicast (multidifusão)?

Resposta Correta: A mensagem é enviada para um grupo selecionado e específico de hosts.

Questão 28 [16:15]
Enunciado: (Consulte a ilustração) Um administrador tenta digitar config t no switch, mas o comando é rejeitado com erro de sintaxe. Qual é a causa do problema?

Resposta Correta: O administrador precisa primeiro entrar no modo EXEC Privilegiado (enable) antes de executar o comando de configuração global.

Questão 29 [17:01]
Enunciado: Por que um switch de Camada 2 (Layer 2) precisa ter um endereço IP configurado?

Resposta Correta: Para permitir o gerenciamento remoto do switch (via SSH, Telnet ou navegador).

Questão 30 [17:23]
Enunciado: Qual dispositivo tem a função principal de determinar o melhor caminho/rota que as mensagens devem seguir através de redes interconectadas?

Resposta Correta: Roteador (Router)

Questão 31 [17:48]
Enunciado: (Atividade Packet Tracer) Acesse o PC, abra a aplicação Terminal conectada ao Switch 0 e descubra qual é o endereço IP configurado na 
interface virtual (SVI) do switch.

Comando executado: show ip interface brief

Resposta Correta: 192.168.5.10 (na VLAN 1) [19:07]

Questão 32 [19:27]
Enunciado: Qual termo descreve a tendência/capacidade dos usuários utilizarem seus próprios dispositivos pessoais para trabalhar na rede corporativa?

Resposta Correta: BYOD (Bring Your Own Device / Traga Seu Próprio Dispositivo)

Questão 33 [19:46]
Enunciado: Em qual camada do modelo OSI o endereço MAC de origem é adicionado à PDU durante o processo de encapsulamento?

Resposta Correta: Camada de Enlace de Dados (Data Link Layer / Camada 2)
*/