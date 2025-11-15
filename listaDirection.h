typedef struct no {
  int idTrecho;
  char direction;
  float distance;
  struct no *prox;
  struct no *ant;
} No;
typedef struct lista {
  No *inicio;
  No *fim;
  int tamanho;
} ListaDE;
void criar(ListaDE **l);
int vazia(ListaDE *l);
int tamanho(ListaDE *l);
int inserir(ListaDE *l, char direction, float distance, int index);
void exibir(ListaDE *l, float x, float y);
float searchDirection(ListaDE *l, char direction);
int remover(ListaDE *l,char direction);