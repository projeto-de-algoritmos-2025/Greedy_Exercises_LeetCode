
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        // Fila de prioridade para funcionar como um max-heap.
        // Armazenará o combustível dos postos que já passamos.
        priority_queue<int> pq;
        
        int paradas = 0;
        long long alcance_atual = startFuel;
        int i = 0; 

        // O loop continua enquanto não alcançamos o destino.
        while (alcance_atual < target) {
            
            // Adiciona ao heap todos os postos que estão dentro do nosso alcance atual.
            while (i < n && stations[i][0] <= alcance_atual) {
                pq.push(stations[i][1]);
                i++;
            }
            
            if (pq.empty()) {
                return -1;
            }
            
            alcance_atual += pq.top();
            pq.pop();
            paradas++;
        }
        
        return paradas;
    }
};