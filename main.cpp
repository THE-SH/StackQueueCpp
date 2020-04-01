#include <iostream>
#include <stack>
#include <queue>
#include <stdlib.h>

using namespace std;

stack<string> pilha;
queue<string> fila;

string dadosPilha, dadosFila;

void addPilha()
{
    cout << "STACK > ";
    cin >> dadosPilha;

    pilha.push(dadosPilha);
}

void removerPDado()
{
    pilha.pop();
    cout << "[DESEMPILHADO] > " << pilha.top() << " na posicao " << pilha.size() << endl;
    pilha.pop();
}

void exibirTopo()
{
    pilha.pop();
    cout << pilha.top() << endl;
}

void tamanhoDado()
{
    pilha.pop();
    if (pilha.empty())
    {
        cout << "[!] A pilha esta vazia" << endl;
    }
    else
    {
        cout << pilha.size() << endl;
    }
}

void esvaziar()
{
    pilha.pop();
    while(!pilha.empty())
    {
        pilha.pop();
    }
}


void addFila()
{
    cout << "QUEUE > ";
    cin >> dadosFila;

    if (dadosFila != "remove" || dadosFila != "show" || dadosFila != "size" || dadosFila != "clear" || dadosFila != "exit")
    {
        fila.push(dadosFila);
    }
    //Este if não está funcionando. A função dele é não permitir que seja adicionado um comando à fila.
}

void tamanhoFila()
{
    cout << fila.size() << endl;
}

void removerFila()
{
    cout << "[DESENFILEIRADO] " << fila.front() << endl;
    fila.pop();
}

void exibirItem()
{
    if (!fila.empty())
    {
        cout << fila.front() << endl;
    }
    else
    {
        cout << "Fila vazia" << endl;
    }
}

void limparFila()
{
    while(!fila.empty())
    {
        fila.pop();
    }
}

int main()
{
    int opt;

    while (opt != 0)
    {
        system("cls");
        cout << "[01] Stack\n[02] Queue\n";
        cout << "\n> ";
        cin >> opt;

        if (opt == 1)
        {
            system("cls");
            cout << "[COMANDOS P/ PILHA]\nremove - remover dado\ntopo   - exibir topo da pilha\nsize   - exibir tamanho\nclear  - esvaziar\nback   - voltar ao menu\n\n";
            dadosPilha = "join";
            while (dadosPilha != "back")
            {
                addPilha();

                if (dadosPilha == "remove")
                {
                    removerPDado();
                }
                else if (dadosPilha == "topo")
                {
                    exibirTopo();
                }
                else if (dadosPilha == "size")
                {
                    tamanhoDado();
                }
                else if (dadosPilha == "clear")
                {
                    esvaziar();
                }
            }
        }
        else if (opt == 2)
        {
            system("cls");
            cout << "[COMANDOS P/ FILA]\nremove - remover dado\nshow   - exibir primeiro dado da fila\nsize   - exibir tamanho\nclear  - esvaziar\nback   - voltar ao menu\n\n";
            dadosPilha = "join";
            while (dadosFila != "back")
            {
                addFila();

                if (dadosFila == "remove")
                {
                    removerFila();
                }
                else if (dadosFila == "show")
                {
                    exibirItem();
                }
                else if (dadosFila == "size")
                {
                    tamanhoFila();
                }
                else if (dadosFila == "clear")
                {
                    limparFila();
                }
            }
        }
    }
    cout << "Saindo do programa...";
}
/* Este código possui bugs de filtragem de comandos, por exemplo, se escrever um comando, ele será adicionado à fila */
