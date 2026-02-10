---
title: Como usar Git
tag: Tutorial
pubDate: 2026-02-10T13:13:00
description: O básico para versionar seus projetos
author: IzuBot
---

**Esse pequeno tutorial será para apresentar o básico sobre gerenciamento de versões usando o Git, é um requisito muito importante se você quer disponibilizar suas aplicações saber usar essa ferramenta.**

- [O que é Git?](#o-que-é-git)
- [Bash](#bash)
  - [Comandos Básicos de Navegação](#comandos-básicos-de-navegação)
  - [Prática com Bash](#prática-com-bash)
  - [Saídas no terminal](#saídas-no-terminal)
- [O Básico do Git](#o-básico-do-git)
  - [Integridade](#integridade)
  - [Três Estados](#três-estados)
- [Comandos Básicos e o Clico de Vida](#comandos-básicos-e-o-clico-de-vida)

## O que é Git?

O **Git** é um sistema de controle de versão (VCS) que monitora o histórico de alterações à medida que desenvolvedores colaboram com o código. Ele gerencia ramificações (*branches*), o que facilita a colaboração entre equipes. Também é possível salvar o histórico de edições (*commits*), facilitando assim o retorno a versões anteriores e o trabalho simultâneo de vários desenvolvedores sem sobrescrever o código de outra pessoa.

Mesmo sendo fortemente recomendado para trabalho simultâneo, você ainda consegue usá-lo sozinho para se organizar e salvar seu trabalho.
Imagine que você está trabalhando em uma atualização em seu software e, por descuido, colocou seu sistema operacional para atualizar e ele reiniciou; bom, se você não salvou a sua edição, tudo será perdido. Ou, em colaboração com um colega, você queira ver as alterações feitas por ele: como você irá distinguir isso?

É por isso e para isso que usamos o Git. Com ele, podemos revisitar códigos antigos navegando pelos nossos *commits* anteriores, criar novos registros de progresso e trabalhar em funcionalidades novas em *branches* diferentes para não estragar o código que já está funcionando. Além disso, podemos fazer a mesclagem (*merge*) de outras *branches* quando essas funções estiverem prontas e, assim, disponibilizar novas versões para os usuários de forma segura.

---

## Bash

O **Bash** — ou, neste caso, o **Git Bash** — é uma interface que interpreta comandos para sistemas *Unix-like*, precisamos falar um pouco dele antes de usarmos o Git. Em poucas palavras, é ele quem vai interpretar os seus comandos e passá-los para o sistema operacional. É através dessa interface que interagimos com o Git.

---

### Comandos Básicos de Navegação

- `ls` - Lista os arquivos e diretórios no diretório atual.
- `cd` - Muda o diretório atual. Por exemplo, `cd Documents` ou `cd ..` para subir um nível.
- `pwd` - Mostra o caminho do diretório atual.
- `mkdir` - Cria um novo diretório. Por exemplo, `mkdir my_project`
- `rm` - Remove arquivos ou diretórios. Use com cuidado! Por exemplo, `rm file.txt` ou `rm -r my_project` para remover um diretório e seu conteúdo.
- `clear` - Limpa a tela do terminal.

### Prática com Bash

Para entender melhor esses comandos a melhor maneira é praticar.

![Exemplo de uso do Bash](/feb-10-2026.png)

Esse é meu terminal aberto, e o que significa tudo isso? Bom, `kauan` é o nome do meu **usuario**, o `@` é um **separador visual**, indicando "no" ou "em" e o `archlinux` é o **nome da minha máquina**, no seu computador isso estará um pouco diferente.
O simbolo `~` é um atalho do **Linux/Unix** que indica o **diretório home** do usuário local então significa que é meu diretório de trabalho na minha máquina. O `$` mostra que estou com o **usuário padrão não root**.

---

### Saídas no terminal

Agora que você já sabe os comandos mais básicos você pode abrir o Bash e se familiarizar com ele. Caso queira saber mais simplemente procure por comandos do bash no seu navegador.
> Muito importante, para que funcione você precisa está no terminal com o Bash, caso esteja no Windows, baixe a ferramenta do Git pois já vem um terminal com Bash.

---

## O Básico do Git

O Git trata seus dados como um conjunto de imagens de um sistema de arquivos em miniatura. Toda vez que você faz um commit, ou salva o estado de seu projeto no Git, ele basicamente tira um **snapshot** de todos os seus arquivos e armazena uma referência para esse conjunto.
Para ser eficiente, se os seus arquivos não foram alterados, o Git não armazena o arquivo novamente; ele apenas cria um *link* para o arquivo idêntico anterior que já está armazenado.

As operações no Git são quase todas locais, o que faz com que quase todos os comandos respondam instantaneamente. O Git armazena o histórico localmente em seu disco, portanto, ele não precisa acessar um servidor externo ou outro computador em sua rede para a maioria das tarefas. Assim, se você precisar ver os seus últimos *commits*, o Git os buscará no banco de dados local e, em segundos, apresentará a saída no terminal.

---

### Integridade

Tudo no Git passa por *checksum* (soma de verificação) antes de ser armazenado e é referenciado por esse *checksum*. Isto significa que é impossivel mudar um conteúdo sem que o Git saiba. Essa funcionalidade está incorporada nos níveis mais baixos do Git. Você não perderá informações durante a transferência e não receberá um arquivo corrompido sem que o Git seja capaz de detectar.
O mecanismo que o Git usa para fazer a soma de verificação é chamado de hash **SHA-1**. Está é uma sequencia de 40 caracteres hexadecimais (0-9 e-f) e é calculada com base no conteúdo de uma estrutura de arquivos ou diretório Git. Um hash SHA-1 é algo parecido com:
`24b9da6552252987aa493b52f8696cd6d3b00373`
Você verá valores de hash em todo o lugar no Git. Na verdade, o Git armazena tudo em seu banco de dados não pelo no do arquivo, mas pelo valor do hash do seu conteúdo.

---

### Três Estados

Essa é a parte mais importante do funcionamento de Git. O Git possui três estados diferentes que seus arquivos podem estar: *commited*, modificado (*modified*) e preparado (*staged*).

- **Commited** significa que os dados estão armazenados de forma segura no seu banco de dados local.
- **Modified** significa que você alterou o arquivo, mas ainda não fez o *commit* no seu banco de dados.
- **Staged** significa que você marcou a versão atual de um arquivo modificado para fazer parte de seu próximo *commit*

Isso nos leva a três seções principais de um projeto: o **diretório Git**, o **diretório de trabalho** e **área de preparo**.

- **O diretório Git** é onde o Git armazena os metadados do banco de dados de objetos de seu projeto. É a parte mais importante do Git, e é o que é copiado quando você clona o repositório de outro computador.

- **O diretório de trabalho** é uma cópia simples de um versão do projeto. Esses arquivos são pegos do banco de dados compactados no diretório Git e colocados no disco para que você possa usar.

- **A área de preparo** é um arquivo, geralmente dentro do seu repositório Git, que armazena as informações sobre o que irá entrar no seu próximo commit. É comumente chamado de área de preparo (staging area).

---

## Comandos Básicos e o Clico de Vida

Agora que você entende os estados, veja como os comandos movem seus arquivos entre eles:

1. **git init**

    É o ponto de partida. Este comando cria um novo diretório Git (a pasta oculta `.git`). Ele inicializa o projeto para que o Git comece a monitorar suas alterações.

    - Onde se aplica: Cria o Diretório Git.

2. **git status**

    Este é o seu melhor amigo. Ele mostra em qual estado seus arquivos estão. Ele dirá se você tem arquivos modificados que ainda não foram preparados, ou arquivos na área de preparo aguardando um *commit*.

3. **git add**

    Quando você altera um arquivo no seu Diretório de Trabalho, ele entra no estado *Modified*. Para movê-lo para o próximo estágio, você usa o `git add`.

    - Onde se aplica: Move o arquivo do diretório de trabalho para a Área de Preparo (*Staging Area*).

4. **git commit**

    O commit tira o "snapshot" de tudo o que você colocou na área de preparo. Ele salva permanentemente essa versão no seu banco de dados local com uma mensagem descrevendo o que foi feito.

    - Onde se aplica: Move os arquivos da área de preparo para o estado *Committed* (Diretório Git).

5. **git branch**

    Como vimos, o Git trabalha com ramificações. O comando `git branch` permite listar, criar ou excluir essas ramificações. É o que permite que você saia da linha principal (geralmente chamada de main) para testar uma ideia nova sem estragar o que já está pronto.

**No seu dia a dia como desenvolvedor, você provavelmente usará esses comandos em um ciclo contínuo: editar arquivos, verificar o status, preparar as alterações e fazer *commits* regularmente para salvar seu progresso. Com o tempo, você se familiarizará com esses comandos e eles se tornarão uma segunda natureza para você.**
