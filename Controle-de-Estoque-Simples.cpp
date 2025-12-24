#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct produto {
    int id;
    string nome;
    int quantidade;
};

void cadastrarProduto(vector<produto>& estoque) {
    while(true) {
        produto p;
        printf("Insira os dados do produto:\n\n");

        do {
            printf("ID: ");
            
            if (!(cin >> p.id)) {  
                printf("ID inválido! Digite apenas números acima de 0.\n");
                cin.clear();   
                cin.ignore(1000, '\n');
                p.id = -1;  
            }
            if (p.id <= 0) {
                printf("ID inválido! Digite apenas números acima de 0.\n");
            }
        } while (p.id <= 0);

        cin.ignore(); 

        printf("Nome: ");
        getline(cin, p.nome);
        if (p.nome.empty()) {
            printf("Nome não pode ser vazio!\n");
            continue;  
        }

        printf("Quantidade: ");
        cin >> p.quantidade;
        if (p.quantidade < 0) {
            printf("O valor deve ser acima de 0!\n");
            continue;
        } else if (p.quantidade == 0) {
            printf("Produto fora de estoque\n");
        }
        estoque.push_back(p);
        printf("Produto cadastrado com sucesso!\n");

        printf("Deseja cadastrar outro produto? (1-Sim, 0-Não): ");
        int acao;
        cin >> acao;
        cin.ignore();

        if (acao == 0) {
            break;
        }
    }
}

int consulta(vector<produto>& estoque) {
    int id;
    printf("Digite o ID do produto: ");
    cin >> id;

    for (size_t i = 0; i < estoque.size(); ++i) {
        if (estoque[i].id == id) {
            printf("%s - ID: %d - Quantidade: %d\n", 
                   estoque[i].nome.c_str(), 
                   estoque[i].id, 
                   estoque[i].quantidade);
 
            printf("Deseja atualizar os dados desse produto? (1-Sim, 0-Não): ");
            int opcao;
            cin >> opcao;
            
            if (opcao == 0) {
                return 1;
            }

            printf("O que deseja atualizar?\n");
            printf("1 - Nome\n");
            printf("2 - Quantidade\n");
            printf("3 - Menu\n");

            int opcao2;
            cin >> opcao2;
            cin.ignore();
            
            if (opcao2 == 3) { //bug fix: o programa está parando 
                return 1;
            }
            
            if (opcao2 == 1) { //bug fix: o programa para depois de atualizar a quantidade
                printf("Digite o novo nome: ");
                getline(cin, estoque[i].nome);
                
                if (estoque[i].nome.empty()) {
                    printf("Nome inválido!\n");
                    return -1;
                }                
                printf("Produto atualizado!\n");
            } 
            else if (opcao2 == 2) { //bug fix: o programa para 
                printf("Digite a nova quantidade: ");
                cin >> estoque[i].quantidade;
                
                if (estoque[i].quantidade < 0) {
                    printf("Quantidade inválida!\n");
                    return -1;
                }
                
                printf("Produto atualizado!\n");
            }
            return 1;
        } 
    }
    
    printf("Produto não encontrado!\n");
    return -1;
}

int main() {
    vector<produto> estoque;
    
    printf("MENU PRINCIPAL\n");
    while(true) {
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar ou atualizar produto\n");
        printf("3 - Sair\n");

        int option;
        cin >> option;

        if (option == 1){
        produto p;
        cadastrarProduto(estoque);
    } else if (option == 2) {
        consulta(estoque);
    } else if (option == 3) {
        printf("Saindo do programa...\n");
        break;
    } else {
        printf("Opção inválida!\n");
    }
    }
    return 0;
}