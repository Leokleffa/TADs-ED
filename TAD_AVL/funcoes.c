pNodoA* rotacao_direita(pNodoA* pt){
    pNodoA *ptu;
    ptu = pt->esq;
    pt->esq = ptu->dir;
    ptu->dir = pt;
    pt->FB = 0;
    pt = ptu;
    return pt;
}

pNodoA* rotacao_esquerda(pNodoA *pt){
    pNodoA *ptu;
    ptu = pt->dir;
    pt->dir = ptu->esq;
    ptu->esq = pt;
    pt->FB = 0;
    pt = ptu;
    return pt;
}

pNodoA* rotacao_dupla_direita (pNodoA* pt){
    pNodoA *ptu, *ptv;
    ptu = pt->esq;
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    pt->esq = ptv->dir;
    ptv->dir = pt;
    if (ptv->FB == 1)
        pt->FB = -1;
    else
        pt->FB = 0;
    if (ptv->FB == -1)
        ptu->FB = 1;
    else
        ptu->FB = 0;
    pt = ptv;
    return pt;
}

pNodoA rotacao_dupla_esquerda (pNodoA *pt){
    pNodoA *ptu, *ptv;
    ptu = pt->dir;
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    pt->dir = ptv->esq;
    ptv->esq = pt;
    if (ptv->FB == -1)
        pt->FB = 1;
    else
        pt->FB = 0;
    if (ptv->FB == 1)
        ptu->FB = -1;
    else
        ptu->FB = 0;
    pt = ptv;
    return pt;
}

pNodoA* InsereAVL (pNodoA *a, TipoInfo x, int *ok){ /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,   x, a chave a ser inserida e h a altura da árvore */
    if (a == NULL) {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    }
    else if (x < a->info) {
        a->esq = InsereAVL(a->esq,x,ok);
        if (*ok) {
            switch (a->FB) {
                case -1: a->FB = 0;
                        *ok = 0;
                        break;
                case  0:  a->FB = 1; break;
                case  1:  a=Caso1(a,ok); break;
            }
        }
    }
    else {
        a->dir = InsereAVL(a->dir,x,ok);
        if (*ok) {
            switch (a->FB) {
                case  1:  a->FB = 0; *ok = 0; break;
                case  0:  a->FB = -1; break;
                case -1:  a = Caso2(a,ok); break;
            }
        }
    }
    return a;
}

pNodoA* Caso1 (pNodoA *a , int *ok) {
    pNodoA *ptu;
    ptu = a->esq;
    if (ptu->FB == 1)  {
        printf("fazendo rotacao direita em %d\n",a->info);
        a = rotacao_direita(a);
    }
    else {
        printf("fazendo rotacao dupla direita em %d\n",a->info);
        a = rotacao_dupla_direita(a);
    }
    a->FB = 0;
    *ok = 0;
    return a;
}
pNodoA* Caso2 (pNodoA *a , int *ok) {
    pNodoA *ptu;
    ptu = a->dir;
    if (ptu->FB == -1){
        printf("fazendo rotacao esquerda em %d\n",a->info);
        a=rotacao_esquerda(a);
    }
    else {
        printf("fazendo rotacao dupla esquerda em %d\n",a->info);
        a=rotacao_dupla_esquerda(a);
    }
    a->FB = 0;
    *ok = 0;
    return a;
}

int Altura (pNodoA *a){
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
        return 0;
    else{
        Alt_Esq = Altura (a->esq);
        Alt_Dir = Altura (a->dir);
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}

int fator(pNodoA *a){
    return Altura(a->esq)-Altura(a->dir);
}
