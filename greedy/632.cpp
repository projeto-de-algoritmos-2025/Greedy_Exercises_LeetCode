#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Usa um vetor de inteiros para representar um nó no heap: {valor, indice_da_lista, indice_do_elemento}
        using Node = vector<int>;

        // Cria uma fila de prioridade que funcionará como um min-heap.
        // O comparador greater<Node> garante que o menor elemento fique no topo.
        priority_queue<Node, vector<Node>, greater<Node>> min_heap;

        int k = nums.size();
        int max_val = numeric_limits<int>::min();

        // 1. Inicialização: Adiciona o primeiro elemento de cada lista no min-heap.
        for (int i = 0; i < k; ++i) {
            // Pega o primeiro elemento da lista i.
            int val = nums[i][0];
            
            // Adiciona o nó {valor, indice_da_lista, indice_do_elemento} ao heap.
            min_heap.push({val, i, 0});
            
            // Atualiza o valor máximo encontrado até agora.
            if (val > max_val) {
                max_val = val;
            }
        }

        // Inicializa o intervalo resultante com o primeiro intervalo válido.
        int range_start = min_heap.top()[0];
        int range_end = max_val;
        int min_range_size = range_end - range_start;

        // 2. Loop principal: Itera enquanto tiver elementos de todas as listas.
        while (true) {
            // Pega o nó com o menor valor do heap.
            Node min_node = min_heap.top();
            min_heap.pop();

            int list_idx = min_node[1];
            int elem_idx = min_node[2];

            // 3. Condição de término: Se alguma lista chegou ao fim, para.
            if (elem_idx + 1 >= nums[list_idx].size()) {
                break;
            }

            // Pega o próximo elemento da lista de onde o mínimo saiu.
            int next_elem_idx = elem_idx + 1;
            int next_val = nums[list_idx][next_elem_idx];
            
            // Adiciona o novo elemento ao heap.
            min_heap.push({next_val, list_idx, next_elem_idx});

            // Atualiza o valor máximo da janela atual.
            if (next_val > max_val) {
                max_val = next_val;
            }

            // O novo mínimo é o elemento no topo do heap.
            int new_min_val = min_heap.top()[0];
            
            // 4. Atualização: Verifica se o novo intervalo é menor que o melhor encontrado.
            if (max_val - new_min_val < min_range_size) {
                min_range_size = max_val - new_min_val;
                range_start = new_min_val;
                range_end = max_val;
            }
        }

        return {range_start, range_end};
    }
};