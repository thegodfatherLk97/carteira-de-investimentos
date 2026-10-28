# Carteira de Investimentos — CP2

Sistema de carteira de investimentos desenvolvido em **linguagem C** para as disciplinas de **Algoritmo e Pensamento Computacional** e **Design Profissional**. A aplicação funciona no terminal e permite cadastrar múltiplos ativos, consultar a carteira e acompanhar seu desempenho com dados informados pelo usuário.

> **Projeto acadêmico e educacional.** Os preços utilizados são exemplos ou valores digitados manualmente; o programa não consulta cotações em tempo real nem realiza operações financeiras.

## 1. Contexto e objetivo

O projeto aborda a **inclusão financeira**, em conexão com a meta **8.10 dos Objetivos de Desenvolvimento Sustentável (ODS)** da ONU, que trata do fortalecimento do acesso a serviços financeiros. A proposta é explorar conceitos básicos de investimentos por meio de uma ferramenta simples de simulação.

Nesta segunda etapa (**CP2**), o sistema evolui para uma carteira com **múltiplos ativos**, utilizando:

- `struct` para representar cada ativo;
- vetor de estruturas para armazenar a carteira em memória;
- funções para separar cadastro, listagem, cálculos e persistência;
- arquivos `.c` e `.h` para organizar a aplicação em módulos;
- arquivo `.txt` para manter os dados entre execuções;
- menu interativo com `do...while` e `switch`.

## 2. Funcionalidades implementadas

| Opção | Funcionalidade | Descrição |
| :---: | --- | --- |
| 1 | Cadastrar ativo | Registra nome, categoria, quantidade, preço de compra e preço atual. |
| 2 | Listar ativos | Exibe os dados de todos os ativos cadastrados. |
| 3 | Valor total da carteira | Soma o valor atual de cada ativo (`quantidade × preço atual`). |
| 4 | Rentabilidade geral | Exibe total investido, valor atual, lucro/prejuízo e rentabilidade percentual. |
| 5 | Sair | Salva a carteira em arquivo e encerra o programa. |

O programa também **carrega os ativos existentes ao iniciar** e **salva os dados após novos cadastros**. A carteira comporta até **100 ativos**.

## 3. Tecnologias e conceitos

- **Linguagem:** C.
- **Compilador:** GCC.
- **Ambiente de desenvolvimento:** Visual Studio Code e terminal.
- **Armazenamento:** arquivo de texto local (`data/carteira.txt`).
- **Conceitos praticados:** estruturas (`struct`), vetores, funções, passagem de parâmetros, repetição, condicionais, modularização, validação de entradas e operações de arquivo com `fopen`, `fscanf`, `fprintf` e `fclose`.

## 4. Estrutura do projeto

```text
CP_2/
├── include/
│   ├── funcoes.h          # Declaração das funções do menu, cadastro e cálculos
│   └── modulo.h           # Struct Ativo, constantes e funções de persistência
├── src/
│   ├── main.c             # Fluxo principal e tratamento das opções do menu
│   ├── funcoes.c          # Cadastro, listagem e cálculos financeiros
│   └── modulo.c           # Leitura e gravação da carteira em arquivo texto
├── data/
│   └── carteira.txt       # Dados de exemplo e persistência dos ativos
├── .gitignore             # Ignora executáveis e arquivos gerados (recomendado)
└── README.md              # Documentação do projeto
```

### Representação de um ativo

Cada elemento da carteira é um `Ativo`, definido em `include/modulo.h`:

```c
typedef struct {
    char nome[50];
    char categoria[30];
    double quantidade;
    double precoCompra;
    double precoAtual;
} Ativo;
```

A capacidade máxima é definida por `MAX_ATIVOS` (`100`). O caminho do arquivo usado na leitura e na gravação é definido por `ARQUIVO_CARTEIRA` (`"data/carteira.txt"`).

## 5. Como executar no VS Code (Windows)

### Pré-requisitos

1. Ter o **Visual Studio Code** instalado.
2. Ter o **GCC** disponível no terminal (por exemplo, por meio do MSYS2/MinGW).
3. Abrir a **pasta raiz `CP_2`**, e não apenas um arquivo `.c`.

No terminal integrado do VS Code (`Terminal` → `Novo Terminal`), confira o compilador:

```powershell
gcc --version
```

Se o comando não for reconhecido, configure o GCC no `PATH` do Windows ou abra um terminal no qual ele esteja disponível.

### Compilar

Execute o comando **a partir da pasta `CP_2`**:

```powershell
gcc -Wall -Wextra -std=c11 -Iinclude src/main.c src/funcoes.c src/modulo.c -o programa.exe
```

### Executar

No PowerShell integrado do VS Code:

```powershell
.\programa.exe
```

> **Importante:** o programa usa o caminho relativo `data/carteira.txt`. Por isso, ele deve ser iniciado a partir da **raiz do projeto**, com a pasta `data` existente.

Em sistemas Linux/macOS com GCC instalado, utilize `-o programa` ao compilar e `./programa` para executar.

## 6. Exemplo de utilização

### Menu apresentado

```text
===== CARTEIRA DE INVESTIMENTOS - CP2 =====
1. Cadastrar ativo
2. Listar ativos
3. Calcular valor total da carteira
4. Calcular rentabilidade geral
5. Sair
Escolha uma opcao:
```

### Dados de exemplo

O arquivo `data/carteira.txt` fornecido com o projeto contém três registros ilustrativos:

```text
PETR4 Acao 10.000000 30.000000 33.000000
TESOURO_SELIC Renda_Fixa 2.000000 1000.000000 1035.000000
HGLG11 Fundo_Imobiliario 3.000000 160.000000 158.000000
```

Com esses dados, **antes de cadastrar ou alterar ativos**, a opção **4 — Rentabilidade geral** apresenta os seguintes valores:

| Indicador | Resultado |
| --- | ---: |
| Valor investido | R$ 2.780,00 |
| Valor atual | R$ 2.874,00 |
| Lucro/prejuízo | R$ 94,00 |
| Rentabilidade geral | 3,38% |

Esses valores são **simulados** e servem apenas para demonstrar o cálculo.

## 7. Regras de cadastro e armazenamento

- Nome e categoria devem ser informados **sem espaços**; use `_` para separar palavras, como `Tesouro_Selic`.
- Para números decimais, utilize **ponto**, por exemplo `10.5`.
- A **quantidade** e o **preço de compra** devem ser maiores que zero.
- O **preço atual** pode ser zero, mas não pode ser negativo.
- O cadastro é recusado quando os valores numéricos são inválidos ou o limite de 100 ativos é atingido.
- Cada linha do arquivo contém, nesta ordem: `nome categoria quantidade precoCompra precoAtual`.
- Registros inválidos podem ser ignorados durante a leitura; se um registro estiver incompleto, a leitura é interrompida.
- Se o arquivo não existir, o programa inicia com a carteira vazia. A pasta `data` ainda precisa existir para que a gravação funcione.
- Ao cadastrar um ativo, o programa tenta salvar imediatamente. Ele também tenta salvar ao selecionar **5 — Sair**.

> **Atenção ao Git:** `data/carteira.txt` faz parte do projeto como **massa de dados de demonstração**. Ao utilizar o programa, os novos cadastros podem modificar esse arquivo. Revise as mudanças com `git status` e não publique informações pessoais ou financeiras reais.

## 8. Fórmulas utilizadas

Para cada ativo `i`:

```text
Valor investido do ativo = quantidade_i × preçoCompra_i
Valor atual do ativo     = quantidade_i × preçoAtual_i
```

Os indicadores gerais são calculados assim:

```text
Valor investido total = soma dos valores investidos de todos os ativos
Valor atual total     = soma dos valores atuais de todos os ativos
Lucro/prejuízo        = valor atual total - valor investido total
Rentabilidade (%)     = (lucro/prejuízo / valor investido total) × 100
```

Para evitar divisão por zero, quando o total investido é menor ou igual a zero a função de rentabilidade retorna `0.0`. Na opção 4, se a carteira estiver vazia, o programa informa que não há ativos para calcular.

## 9. Organização do código

| Arquivo | Responsabilidade |
| --- | --- |
| `src/main.c` | Inicializa a carteira, carrega dados e controla o menu e suas opções. |
| `src/funcoes.c` | Exibe o menu, limpa a entrada, cadastra, lista e calcula os indicadores. |
| `src/modulo.c` | Lê e grava os registros no arquivo de texto. |
| `include/funcoes.h` | Declara as funções de interação e os cálculos. |
| `include/modulo.h` | Define a estrutura `Ativo`, constantes e funções de persistência. |
| `data/carteira.txt` | Armazena os ativos entre execuções. |

## 10. Limitações atuais e possíveis evoluções

Esta versão contempla o escopo acadêmico da **CP2**. Ainda **não** implementa:

- atualização ou exclusão de um ativo já cadastrado;
- ordenação da lista de ativos;
- consulta automática de cotações financeiras;
- histórico de transações ou atualização automática de preços;
- interface gráfica ou banco de dados.

Como melhorias futuras, o projeto poderá incorporar edição de ativos, filtros por categoria, testes automatizados e relatórios mais detalhados, conforme os requisitos das próximas etapas.

## 11. Sobre o projeto

Projeto acadêmico das disciplinas de **Algoritmo e Pensamento Computacional** e **Design Profissional**, desenvolvido para praticar o raciocínio lógico, a organização do código e o uso de arquivos em C.

**Aviso:** não constitui orientação ou recomendação de investimentos.
