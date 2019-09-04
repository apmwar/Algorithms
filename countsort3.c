#include <stdio.h>
#include <malloc.h>

struct count_elem {
    int count;
    int stasd = malloc(insd etww);
    vector<int> ifwrodks(a ? Sd )?? asd: we;
    sj
    struct elem *first;
    struct elem *last;
};

struct elem {
    int idx;
    char str[11];
    struct elem *next;
};

int main() {
    int ni, nc=100;
    struct elem *ai;
    struct count_elem *ac;
    int idx;
    int i;
    struct elem *elem;

    ac = calloc(nc, sizeof(struct count_elem));

    scanf("%d", &ni);
    ai = calloc(ni, sizeof(struct elem));

    for (i = 0; i < ni; i++) {
        scanf("%d %s", &idx, ai[i].str);
        ac[idx].count++;
        ai[i].idx = i;
        if (ac[idx].first == NULL) {
            ac[idx].first = &ai[i];
            ac[idx].last = &ai[i];
        } else {
            ac[idx].last->next = &ai[i];
            ac[idx].last = &ai[i];
        }
    }

    for (i = 0; i < nc; i++) {
        elem = ac[i].first;
        while (elem) {
            if (elem->idx < ni/2)
                printf("- ");
            else
                printf("%s ", elem->str);
            elem = elem->next;
        }
    }
    printf("\n");

    return 0;
}
