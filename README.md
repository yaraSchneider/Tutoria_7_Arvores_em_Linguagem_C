# Tutoria 7: Árvores Binárias de Busca em Linguagem C

## 📋 Descrição do Projeto

Este repositório contém implementações de **Árvores Binárias de Busca (ABB)** em C, aplicando conceitos fundamentais de estruturas de dados em problemas práticos e completos. O objetivo é desenvolver habilidades na manipulação e análise de árvores, comparando a eficiência com buscas sequenciais.

## 🎯 Objetivos de Aprendizagem

Através dos exercícios propostos, foram desenvolvidas as seguintes competências:

- ✅ **Cadastro**: Inserção de nós em árvores binárias de busca mantendo a propriedade de ordenação
- ✅ **Contagem**: Contabilização de nós na árvore
- ✅ **Altura**: Cálculo da altura da árvore
- ✅ **Valores Extremos**: Identificação do menor e maior elemento
- ✅ **Remoção**: Exclusão de nós respeitando a estrutura de ABB
- ✅ **Comparação de Desempenho**: Análise da eficiência entre buscas em árvore vs busca sequencial

## 📁 Estrutura do Repositório

```
Tutoria_7_Arvores_em_Linguagem_C/
├── Exercício 1/          # Conceitos básicos de ABB
├── Exercício 2/          # Operações de busca e inserção
├── Exercício 3/          # Cálculo de altura e contagem
├── Exercício 4/          # Remoção de nós
├── Exercício 5/          # Comparação com busca sequencial
└── README.md             # Este arquivo
```

## 💡 Conceitos Implementados

### 1. Estrutura de Dados
```c
typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;
```

### 2. Operações Principais

#### Inserção (ABB)
- Mantém a propriedade: elementos à esquerda < nó < elementos à direita
- Complexidade: O(log n) em média, O(n) no pior caso

#### Busca
- Aproveitando a ordenação da árvore para busca mais eficiente
- Complexidade: O(log n) em média

#### Contagem
- Percorre toda a árvore (pós-ordem)
- Complexidade: O(n)

#### Altura
- Distância máxima da raiz até uma folha
- Complexidade: O(n)

#### Valores Extremos
- Menor: sempre à esquerda até não poder descer mais
- Maior: sempre à direita até não poder descer mais
- Complexidade: O(log n) em média

#### Remoção
- Três casos: nó folha, nó com um filho, nó com dois filhos
- Complexidade: O(log n) em média

## 🔍 Comparação: ABB vs Busca Sequencial

| Operação | ABB | Sequencial |
|----------|-----|-----------|
| **Busca** | O(log n) | O(n) |
| **Inserção** | O(log n) | O(n) |
| **Remoção** | O(log n) | O(n) |
| **Espaço** | O(n) | O(n) |

A vantagem da ABB fica evidente em conjuntos de dados grandes, especialmente quando múltiplas buscas são realizadas.

## ❓ Questões Práticas e Análises

### 1. Qual busca fez menos comparações?

**Resposta:** A busca em **Árvore Binária de Busca** realiza significativamente **menos comparações** que a busca sequencial em conjuntos de dados bem estruturados.

**Exemplo prático:**
- Buscar o valor **15** em um array de 15 elementos: **15 comparações** (pior caso)
- Buscar o valor **15** em uma ABB balanceada: **~4 comparações** (log₂ 15 ≈ 4)

**Por que?** Na ABB, a cada comparação, você elimina metade das possibilidades restantes. Na busca sequencial, você verifica elemento por elemento.

```
ABB Balanceada:          Busca Sequencial:
        50                  10, 20, 30, 40, 50, 60, 70, 80, 90
       /  \                 ↑   ↑   ↑   ↑   ↑
      30   70            5 comparações para encontrar 50
     / \   / \
    20 40 60 80
   /
  10
  
Comparações: 50 > 15? 30 > 15? 20 > 15? 10 < 15? (4 comparações)
```

---

### 2. A árvore sempre será melhor? Justifique.

**Resposta:** **NÃO, nem sempre!** Existem cenários onde a busca sequencial pode ser tão boa ou até melhor:

#### Casos onde a ABB é melhor:
- ✅ **Muitos dados** (n > 100)
- ✅ **Múltiplas buscas** no mesmo conjunto
- ✅ **Dados já organizados** aleatoriamente
- ✅ **Atualizações frequentes** (inserções e remoções)

#### Casos onde a busca sequencial é melhor ou equivalente:
- ✅ **Poucos dados** (n < 20): overhead de ponteiros não compensa
- ✅ **Um único elemento**: ambas fazem 1 comparação
- ✅ **Buscar primeiro elemento**: busca sequencial faz 1 comparação
- ✅ **Array ordenado pequeno**: busca binária é simples e rápida
- ✅ **Cache eficiente**: arrays contíguos em memória são mais rápidos que árvores espalhadas

#### Análise de Overhead:
```
Busca Sequencial em Array:
- Memória contígua (cache-friendly)
- Sem overhead de ponteiros
- Simples de implementar

ABB:
- Múltiplos acessos a memória (pode causar cache misses)
- Overhead de 2 ponteiros por nó
- Mais complexa de implementar

Conclusão: Para dados pequenos, a simplicidade da busca sequencial vence!
```

---

### 3. O que pode acontecer se os valores forem inseridos já ordenados?

**Resposta:** A árvore **degenera em uma lista ligada**, perdendo toda a eficiência!

#### Exemplo - Inserção de valores ordenados (1, 2, 3, 4, 5):

```
Sequência inserida: 1, 2, 3, 4, 5

ABB Resultante (DEGENERADA):
1
 \
  2
   \
    3
     \
      4
       \
        5

⚠️ Não é mais uma árvore! É uma lista ligada!

Complexidade resultante:
- Busca: O(n) - idêntico à busca sequencial
- Inserção: O(n)
- Altura: 5 (máxima possível)
```

#### Comparação:

```
Inserção Ordenada vs Aleatória (15 elementos):

ORDENADA:           ALEATÓRIA (Balanceada):
    1                      8
     \                    /  \
      2                  4    12
       \                /\    /\
        3              2  6  10 14
         \            /\ /\ /\ /\
          ...        1 3 5 7 9 11...
          
Altura: 15              Altura: ~4
Comparações: 15         Comparações: ~4
Eficiência: PÉSSIMA     Eficiência: EXCELENTE
```

#### Impacto:
| Aspecto | Dados Aleatórios | Dados Ordenados |
|---------|------------------|-----------------|
| **Altura** | O(log n) | O(n) |
| **Busca** | O(log n) | O(n) |
| **Pior Caso** | Aceitável | Catastrófico |

---

### 4. Como uma árvore balanceada ajudaria nesse caso?

**Resposta:** Uma **árvore balanceada** garante que a altura seja sempre mantida próxima de log₂(n), mesmo com inserções ordenadas!

#### Tipos de Árvores Balanceadas:

##### **Árvore AVL (Auto-Balanceada)**
- Mantém a diferença de altura entre subárvores ≤ 1
- Realiza rotações após cada inserção/remoção
- Garante altura máxima = 1.44 × log₂(n)

```
Inserção Ordenada com AVL:
Sequência: 1, 2, 3, 4, 5

Após cada inserção, rotações garantem balanceamento:

1. Inserir 1:      1
2. Inserir 2:    1       Desbalanceado! Rotação esquerda
                  \
                   2
                   
   Após rotação:   2
                  /
                 1
                 
3. Inserir 3:      2       Desbalanceado! Rotação esquerda
                  / \
                 1   3
                 
   Após rotação:   2
                  / \
                 1   3
                 
4. Inserir 4:      2       Desbalanceado! Rotação esquerda
                  / \
                 1   3
                      \
                       4
                       
   Após rotação:    3
                   / \
                  2   4
                 /
                1
```

##### **Árvore Rubro-Negra**
- Mantém propriedades de cor (vermelho/preto)
- Menos rotações que AVL (melhor para muitas inserções)
- Altura máxima = 2 × log₂(n + 1)

##### **Árvore B**
- Cada nó pode ter múltiplos filhos
- Otimizada para disco (bancos de dados)
- Altura O(log n) garantida

#### Comparação com ABB Simples:

```
15 elementos inseridos em ordem:

ABB Simples (sem balanceamento):
- Altura: 15
- Busca: O(n)
- ❌ Falha catastroficamente

ABB AVL (auto-balanceada):
- Altura: ~4
- Busca: O(log n)
- ✅ Mantém eficiência
- Custo: rotações durante inserção

Busca Sequencial:
- Altura: N/A
- Busca: O(n)
- ✅ Simples, sem rotações
- Sem surpresas ruins
```

#### Exemplo de Rotação em AVL:

```c
// Quando a subárvore direita fica muito maior (desbalanceada):
// Antes da rotação à esquerda:
    A                B
     \              / \
      B      →     A   C
       \
        C

// Isso restaura o balanceamento!
```

#### Benefícios da Árvore Balanceada:

| Benefício | Descrição |
|-----------|-----------|
| **Altura Garantida** | Sempre próxima de log₂(n) |
| **Desempenho Previsível** | Sem pior caso catastrófico |
| **Escalabilidade** | Funciona bem com dados ordenados |
| **Operações Eficientes** | Busca, inserção, remoção: O(log n) |

---

## 📊 Resumo Comparativo Final

```
Cenário: Buscar valor em 1.000.000 elementos

┌─────────────────────────┬───────────────┬─────────────┐
│ Estrutura              │ Comparações   │ Tempo       │
├─────────────────────────┼───────────────┼─────────────┤
│ Busca Sequencial        │ ~500.000      │ ~500.000 μs │
│ ABB Simples (pior caso) │ 1.000.000     │ ~1.000.000 μs│
│ ABB Balanceada (melhor) │ ~20           │ ~20 μs      │
│ ABB AVL (garantido)     │ ~24           │ ~24 μs      │
└─────────────────────────┴───────────────┴─────────────┘

Diferença: 20.000x mais rápido com árvore balanceada!
```

## 📚 Referências e Conceitos

### Árvores Binárias de Busca
- **Propriedade ABB**: Para cada nó, todos os valores à esquerda são menores e todos à direita são maiores
- **Balanceamento**: Uma ABB desbalanceada (como uma lista) piora o desempenho
- **Altura**: Determina a profundidade e eficiência das operações

### Tipos de Percurso
- **Pré-ordem**: Nó → Esquerda → Direita
- **Em-ordem**: Esquerda → Nó → Direita (resulta em sequência ordenada)
- **Pós-ordem**: Esquerda → Direita → Nó

## 🛠️ Como Compilar e Executar

### Pré-requisitos
- GCC ou outro compilador C
- Linux/Windows/MacOS

### Compilação
```bash
cd "Exercício [número]"
gcc -o programa main.c
```

### Execução
```bash
./programa
```

## 🎓 Conclusões

Através deste trabalho, foi possível:

1. **Compreender** a importância da estrutura de dados correta para cada problema
2. **Implementar** operações complexas em árvores de forma eficiente
3. **Comparar** algoritmos diferentes e entender trade-offs
4. **Aplicar** conhecimentos teóricos em problemas práticos
5. **Reconhecer** limitações da ABB simples e a necessidade de balanceamento

As Árvores Binárias de Busca são fundamentais para muitas aplicações reais, como sistemas de banco de dados, compiladores, sistemas de arquivos e algoritmos de ordenação.

## 📝 Notas Finais

- Cada exercício aumenta em complexidade
- É importante testar com diferentes entradas (árvores balanceadas e desbalanceadas)
- Considere usar ferramentas de debug para visualizar a estrutura da árvore durante a execução
- **Lição importante**: A estrutura dos dados (como você os insere) é tão importante quanto a estrutura de dados escolhida!
- **Próximo passo**: Implementar balanceamento (AVL ou Rubro-Negra) para garantir performance em casos reais

---

**Autor**: Yara Schneider  
**Data**: 2026  
**Disciplina**: Estruturas de Dados  
**Linguagem**: C
