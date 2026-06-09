# Quiz-com-Niveis

## Integrantes

- André de Oliveira Magalhães
- Bruno Lopes Borges
- Jean Daniel da Silva Santos
- Pedro Henrique Narriman Lima Plácido

## Sobre o Quiz

Quiz está desenvolvido em linguagem C como trabalho da disciplina de Lógica de Programação

O jogo apresenta perguntas de múltipla escolha divididas em níveis, a cada resposta correta o jogador avança para o próximo nível. Caso erre uma pergunta ou estoure o tempo máximo para responder, a partida acaba.

## Funcionalidades

- Menu principal
- Leitura de perguntas através de arquivo externo (`perguntas.txt`)
- Correção automática das respostas
- Sistema de níveis
- Temporizador para cada pergunta
- Tela de vitória e derrota

## Estrutura do Projeto

```text
Quiz-com-Niveis/
│
├── .idea/
│
├── .gitignore
│
├── Perguntas.txt
│   └── Banco de perguntas e respostas do quiz
│
├── jogo.c
│   └── Código-fonte principal do jogo
│
└── README.md
    └── Documentação do projeto
```

## Como Executar

1. Compile o arquivo `jogo.c`
2. Certifique-se de que o arquivo `perguntas.txt` esteja na mesma pasta do executável
3. Execute o programa
4. Escolha a opção desejada no menu
