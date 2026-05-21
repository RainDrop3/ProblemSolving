#include <iostream>
#include "DNA_bank.h"

using namespace std;

int cand[500005];
int temp[500005];
char current_chars[500005];

int fidx1 = -1, fidx2 = -1;

int get_char_order(char c) {
    if (c == 'a' || c == 'A') return 1;
    if (c == 'c' || c == 'C') return 2;
    if (c == 'g' || c == 'G') return 3;
    if (c == 't' || c == 'T') return 4;
    return 0;
}

void search(int left, int right, int k1, int k2, int depth) {
    if (left > right) return;
    if (k1 == -1 && k2 == -1) return;

    if (left == right) {
        if (k1 == 1) fidx1 = cand[left];
        if (k2 == 1) fidx2 = cand[left];
        return;
    }

    int counts[5] = {0};

    for (int i = left; i <= right; i++) {
        current_chars[i] = DNA_base(cand[i], depth);
        int order = get_char_order(current_chars[i]);
        counts[order]++;
    }

    int offsets[6] = {0};
    offsets[0] = left;
    for (int i = 0; i < 5; i++)
        offsets[i + 1] = offsets[i] + counts[i];


    int current_offsets[5];
    for (int i = 0; i < 5; i++)
        current_offsets[i] = offsets[i];

    for (int i = left; i <= right; i++) {
        int order = get_char_order(current_chars[i]);
        temp[current_offsets[order]++] = cand[i];
    }

    for (int i = left; i <= right; i++)
        cand[i] = temp[i];


    int curr_k1 = k1;
    int curr_k2 = k2;

    for (int i = 0; i < 5; i++) {
        int size = counts[i];
        if (size == 0) continue;

        int next_k1 = -1;
        int next_k2 = -1;

        if (curr_k1 != -1) {
            if (curr_k1 <= size) {
                next_k1 = curr_k1;
                curr_k1 = -1;
            }
            else curr_k1 -= size;
        }
        if (curr_k2 != -1) {
            if (curr_k2 <= size) {
                next_k2 = curr_k2;
                curr_k2 = -1;
            }
            else curr_k2 -= size;
        }

        if (next_k1 != -1 || next_k2 != -1) {
            if (i == 0) {
                if (next_k1 != -1) fidx1 = cand[offsets[i] + next_k1 - 1];
                if (next_k2 != -1) fidx2 = cand[offsets[i] + next_k2 - 1];
            }
            else
                search(offsets[i], offsets[i + 1] - 1, next_k1, next_k2, depth + 1);

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long xseed, Nsize;
    int index1, index2;

    set_DNA_bank();
    Nsize = get_size();
    get_index(&index1, &index2);

    for (int i = 0; i < Nsize; i++)
        cand[i] = i + 1;

    search(0, Nsize - 1, index1, index2, 1);

    report(fidx1, fidx2);
}