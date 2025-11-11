typedef struct product{
  char name[40];
  char categoria[40];
  int quantidade;
  float price;
}Product;
typedef struct no {
  Product* prod;
  struct no *prox;
  struct no *ant;
} No;
typedef struct lista {
  No *inicio;
  No *fim;
  int tamanho;
} ListaDE;

void criar(ListaDE *l);
int vazia(ListaDE *l);
int tamanho(ListaDE *l);
int inserir(ListaDE *l, Product* elem);
int inserirInicio(ListaDE *l, int elem);
int inserirPosicao(ListaDE *l, int elem, int pos);
void exibir(ListaDE *l);
int buscaPorElemento(ListaDE *l, int elem);
int buscaPorPosicao(ListaDE *l, int pos);
int removerInicio(ListaDE *l);
int removerFim(ListaDE *l);
int remover(ListaDE *l, int elem);