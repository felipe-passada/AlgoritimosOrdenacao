typedef struct PESSOA{
    int id;
    char nome[255];
    int idade;
    char empresa[255];
    char departamento[255];
    float salario;
}PESSOA;

int listaPessoas(int size);
void liberaPessoas(PESSOA *pessoa);
