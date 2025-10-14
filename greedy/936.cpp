#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.length();
        int n = target.length();
        vector<int> moves;
        int stamped_count = 0;

        // Continua enquanto a string alvo não estiver completamente preenchida com '?'.
        while (stamped_count < n) {
            bool found_match_in_pass = false;

            // Itera por todas as janelas possíveis do tamanho do carimbo.
            for (int i = 0; i <= n - m; ++i) {
                if (can_unstamp(stamp, target, i)) {
                    found_match_in_pass = true;
                    int new_stamps = do_unstamp(target, m, i);
                    stamped_count += new_stamps;
                    moves.push_back(i);
                }
            }

            // Se uma varredura completa não encontrou nenhuma nova correspondência, é impossível.
            if (!found_match_in_pass) {
                return {}; // Retorna um vetor vazio.
            }
        }

        // A lista de movimentos foi criada na ordem inversa de aplicação.
        reverse(moves.begin(), moves.end());
        return moves;
    }

private:
    /**
     * Verifica se a janela em 'target' começando em 'start_idx' pode ser "descarimbada".
     * Uma janela pode ser descarimbada se ela corresponde ao carimbo, permitindo '?' como curingas,
     * e se a janela não for composta inteiramente por '?'.
     */
    bool can_unstamp(const string& stamp, const string& target, int start_idx) {
        int m = stamp.length();
        bool contains_non_q_mark = false;
        for (int j = 0; j < m; ++j) {
            if (target[start_idx + j] == '?') {
                continue;
            }
            contains_non_q_mark = true;
            if (target[start_idx + j] != stamp[j]) {
                return false; // Não corresponde.
            }
        }
        // Retorna true apenas se houver uma correspondência e a janela não for toda de '?'.
        return contains_non_q_mark;
    }

    /**
     * "Descarimba" a janela substituindo seus caracteres por '?' e retorna o número de
     * novos '?' criados.
     */
    int do_unstamp(string& target, int stamp_len, int start_idx) {
        int count = 0;
        for (int j = 0; j < stamp_len; ++j) {
            if (target[start_idx + j] != '?') {
                target[start_idx + j] = '?';
                count++;
            }
        }
        return count;
    }
};