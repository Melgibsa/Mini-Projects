#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct produto {
    int id;
    string nome;
    int quantidade;
};

int consulta(vector<produto>& estoque) {
    int id;
    printf("Digite o ID do produto: ");
    cin >> id;

    for (size_t i = 0; i < estoque.size(); ++i) {
        if (estoque[i].id == id) {
            printf("%s - ID: %d - Quantidade: %d\n", estoque[i].nome.c_str(), estoque[i].id, estoque[i].quantidade);
            
            printf("Deseja atualizar os dados desse produto? (1-Sim, 0-Não): ");
            int opcao;
            cin >> opcao;
            printf("O que deseja atualizar?\n");
            printf("1 - Nome\n");
            printf("2 - Quantidade\n");
            printf("3 - Voltar\n");

            int opcao2;
            cin >> opcao2;
            cin.ignore();
            if (opcao2 == 1){
                printf("Digite o novo nome: ");
                getline(cin, estoque[i].nome);
                if (estoque[i].nome.empty()) {
                    printf("Nome inválido!\n");
                    return -1;
                }
                printf("Produto atualizado!\n");

            } else if (opcao2 == 2) {
                printf("Digite a nova quantidade: ");
                cin >> estoque[i].quantidade;
                printf("Produto atualizado!\n");
                if (estoque[i].quantidade < 0) {
                    printf("Quantidade inválida!\n");
                    return -1;
            }
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
        printf("Insira os dados do produto:\n\n");

        printf("ID: ");
        cin >> p.id;
        cin.ignore(); 
        if (p.id <= 0) {
            continue;
        }

        printf("Nome: ");
        getline(cin, p.nome);
        if (p.nome.empty()) {
            break;
        }

        printf("Quantidade: ");
        cin >> p.quantidade;
        if (p.quantidade < 0) {
            break;
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
            printf("1-Sair, 2-Consultar produto\n");
            int acao2;
            cin >> acao2;
            cin.ignore();

            if (acao2 == 1) {
                break;
            } else if (acao2 == 2) {
                consulta(estoque);
            }
        } else if (acao == 1) {
        break;   
        }
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