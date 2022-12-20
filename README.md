# Sistemas Embarcados 2022.2

Projeto desenvolvido para a matéria de sistemas embarcados no primeiro semestre de 2022.

Para a construção deste projeto, foram utilizados os seguintes componentes:

- [Colibri VF50](https://www.toradex.com/pt-br/computer-on-modules/colibri-arm-family/nxp-freescale-vybrid-vf5xx)
- [Viola Carrier Board (rev 1.2)](https://www.toradex.com/pt-br/products/carrier-board/viola-carrier-board)
- 2 x LED
- 3 x Botões de pressão
- 2 x Resistores
- 1 X protoboard
- Fonte de alimentação 5V 1A

 Já para a compilação do projeto foram utilizadas as seguintes dependencias:

 - Ubuntu 22.04
 - [Toolchain Colibri VF50](https://developer-archives.toradex.com/getting-started/module-2-my-first-hello-world-in-c/configure-toolchain-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux)
- [Linux/Yocto Project](https://developer-archives.toradex.com/getting-started/module-1-from-the-box-to-the-shell/update-the-linux-image-iris-carrier-board-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux)


 A montagem está está na imagem a seguir:

 ![Montagem](/Midia/montagem.jpeg)

A seguir, estão descritos os processos de instalação de cada dependência. 

- Ubuntu

A imagem ISO do sistema operacional foi baixada [no site oficial](https://ubuntu.com/). A instalação do SO foi realizada em uma máquina virtual utilizando Virtual Box. Lembrando de atualizar todos os softwares do sistema antes de começar.

- Toolchain Colibri VF50

A **Toolchain Colibri VF50** é utilizada para a realização da compilação cruzada entre o sistema base e o sistema embarcado (**Linux/Yocto Project**). Para instalá-la, basta executar os passos descritos neste [tutorial](https://developer-archives.toradex.com/getting-started/module-2-my-first-hello-world-in-c/configure-toolchain-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux).

- Linux/Yocto Project

O **Linux/Yocto Project** é utilizado como sistema operacional embarcado na placa utilizada. Para instalá-lo, basta executar os passos descritos neste [tutorial](https://developer-archives.toradex.com/getting-started/module-1-from-the-box-to-the-shell/update-the-linux-image-iris-carrier-board-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux). 

- Código

Para finalizar a instalação, é necessário clonar o pacote no qual está o desenvolvimento deste projeto. Para isso, acesse a pasta de preferência e execute os comandos a seguir. (lembrando de executar a conexão por cabo Ethernet com a placa)

```console
git clone https://github.com/vasc-code/embarcados.git
```

```console
cd embarcados
```

Para se realizar a compilação cruzada se executa o seguinte comando:

```console
${CC} -Wall code.c -o codeARM
```

O arquivo **codeARM** consiste do executável em arquitertura *ARM*. Com o Host na mesma rede que o sistema embarcado, a fim de facilitar a conexão, realiza-se os seguintes comandos:

```console
scp codeARM root@<ip>:/home/root
```

Para acessar e executar o projeto:

```console
ssh root@<ip>
```
Dentro do ambiente embarcado:

```console
./codeARM
```

Por fim, basta reiniciar a placa para testar o projeto como um todo:

```console
reboot
```

Pronto agora sua placa pode funcionar independente de conexão com computador, apenas com energia.

