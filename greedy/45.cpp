#include <vector>
#include <algorithm> 

class Solution {
public:
    int jump(std::vector<int>& nums) {
        // Se o array tem 1 ou 0 elementos, não precisamos de saltos.
        if (nums.size() <= 1) {
            return 0;
        }

        int saltos = 0;
        // Inicialmente, estamos no índice 0, então o fim do alcance atual é 0.
        int fim_alcance_atual = 0;
        int alcance_maximo = 0;

        // Percorremos o array até o penúltimo elemento.
        for (int i = 0; i < nums.size() - 1; ++i) {
            // A cada posição 'i', atualizamos o alcance máximo possível.
            alcance_maximo = std::max(alcance_maximo, i + nums[i]);

            
            if (i == fim_alcance_atual) {
            
                saltos++;
                
                fim_alcance_atual = alcance_maximo;

                if (fim_alcance_atual >= nums.size() - 1) {
                    return saltos;
                }
            }
        }

        return saltos;
    }
};