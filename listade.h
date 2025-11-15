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
void exibir(ListaDE *l);
void exibirCategoria(ListaDE* l,char name[]);
No* searchName(ListaDE *l, char name[]);
int removeName(ListaDE *l, char name[]);
int update(ListaDE *l, char name[], Product* p);