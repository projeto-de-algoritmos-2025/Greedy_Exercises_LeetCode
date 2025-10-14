# Greedy_Exercises_LeetCode

**Número da Lista**: 3<br>
**Conteúdo da Disciplina**: Algoritmos Ambiciosos <br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 22/1007994 |  Diego Sousa Leite |
| 22/1031354 |  Pedro Henrique Fernandino da Silva |

## Sobre 

Para o Trabalho 3, nossa dupla selecionou e resolveu quatro desafios da plataforma LeetCode, em conformidade com as diretrizes do professor Maurício Serrano. Foram solucionados três problemas de nível difícil e um de nível médio. O objetivo deste trabalho é demonstrar o conhecimento adquirido nas aulas e estudos sobre a teoria dos Algoritmos Ambiciosos.

Para cada exercício, são apresentados o código-fonte da solução, a captura de tela da submissão bem-sucedida no LeetCode e um vídeo explicativo de até cinco minutos detalhando o raciocínio utilizado.



## Linguagem utilizada

- C++

## Screenshots

### [632 - Difícil](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/?envType=problem-list-v2&envId=greedy)
A solução gulosa usa um Min-Heap para manter uma janela com um elemento de cada lista. A cada passo, o menor elemento da janela é removido e substituído pelo próximo da mesma lista. Essa estratégia avança a janela eficientemente, atualizando o menor intervalo (`[mínimo, máximo]`) encontrado até que uma lista se esgote.


![785](/assets/632.png)

### [936 - Difícil](https://leetcode.com/problems/stamping-the-sequence/description/?envType=problem-list-v2&envId=greedy)
A solução adota uma abordagem gulosa reversa, desconstruindo a string `target` de volta para `'?'`s. A cada passo, ela busca e substitui qualquer substring que corresponda ao `stamp` — tratando `'?'`s como curingas — até que toda a string seja convertida. A sequência final de movimentos é a ordem inversa das substituições feitas.

![785](/assets/936.png)

### [ - Difícil]()


<!--![785](/assets/1579.PNG) -->

### [ - Médio]()


<!--![785](/assets/1579.PNG) -->

## Link para vídeo da apresentação:
