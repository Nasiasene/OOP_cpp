#include <iostream>
#include <vector>
#include <string>

using namespace std;


// * Cliente: informações sobre um cliente do restaurante
class Cliente {
    string nome;
    string telefone;
    string endereco;

    public:
        Cliente(string nn, string tt, string ee) : nome{nn}, telefone{tt}, endereco{ee} {}
        ~Cliente() {}

        //Getters
        string get_nome() {return nome;}
        string get_telefone() {return telefone;}
        string get_endereco() {return endereco;}
        
        //Setters
        void set_nome(string nn) {nome = nn;}
        void set_telefone(string tt) {telefone = tt;}
        void set_endereco(string ee) {endereco = ee;}


        void print_info(){ //Para printar as informações do cliente.
            cout << "Nome cliente: " << nome;
            cout << ", Telefone cliente: " << telefone;
            cout << ", Endereco cliente: " << endereco << endl;
        }
};


// * Item: um prato, bebida ou sobremesa
class Prato{
    string tipo; //PRATO, BEBIDA OU SOBREMESA
    string nome;
    float preco;

    public:
        Prato(string tt, string nn, float pp) : tipo{tt}, nome{nn}, preco{pp} {}
        ~Prato() {}

        //Getters
        string get_tipo() {return tipo;}
        string get_nome() {return nome;}
        float get_preco() {return preco;}

        //Setters
        void set_tipo(string tt) {tipo = tt;}
        void set_nome(string nn) {nome = nn;}
        void set_preco(float pp) {preco = pp;}


        void print_info(){ //Para printar as informações do prato.
            cout << "Nome do prato: " << nome << endl;
            cout << "Tipo: " << tipo << endl;
            cout << "Preco: " << preco << endl;
        }
};


// * Cardápio: uma coleção de itens (pratos, bebidas e sobremesas) oferecidos
//   pelo restaurante.
class Cardapio{
    //Array dinamico de elementos do tipo Prato.
    vector<Prato*> pratos;   
    vector<Prato*> bebidas;
    vector<Prato*> sobremesas;

    public:
        Cardapio() {}
        ~Cardapio() {pratos.clear(); bebidas.clear(); sobremesas.clear();} //Desalocando memória dos vetores do tipo Prato.

        //Getters
        vector<Prato*> get_pratos() {return pratos;}
        vector<Prato*> get_bebidas() {return bebidas;}
        vector<Prato*> get_sobremesas() {return sobremesas;}

        //Setters
        void set_pratos(vector<Prato*> pp) {pratos = pp;}
        void set_bebidas(vector<Prato*> bb) {bebidas = bb;}
        void set_sobremesas(vector<Prato*> ss) {sobremesas = ss;}

        //Adicionando pratos, bebidas e sobremesas ao cardápio.
        void add_prato(Prato* p) {pratos.push_back(p);}
        void add_bebida(Prato* b) {bebidas.push_back(b);}
        void add_sobremesa(Prato* s) {sobremesas.push_back(s);}


        void print_info(){ //Para printar as informações do cardápio.
            cout << "Pratos principais:\n";
            for (auto& prato : pratos) {
                cout << "Nome: " << prato->get_nome() << ", Preco: " << prato->get_preco() << "\n";
            }

            cout << "\nBebidas:\n";
            for (auto& bebida : bebidas) {
                cout << "Nome: " << bebida->get_nome() << ", Preco: " << bebida->get_preco() << "\n";
            }

            cout << "\nSobremesas:\n";
            for (auto& sobremesa : sobremesas) {
                cout << "Nome: " << sobremesa->get_nome() << ", Preco: " << sobremesa->get_preco() << "\n";
            }
        }
};

// * Reserva: uma reserva de mesa feita por um cliente.
class Reserva{
    Cliente* cliente;
    int numero_mesa;

    public:
        Reserva(Cliente* c, int nm): cliente{c}, numero_mesa{nm} {}
        ~Reserva() {delete cliente;}

        //Getters
        Cliente* get_cliente(){return cliente;}
        int get_mesa(){return numero_mesa;}

        //Setters
        void set_cliente(Cliente *c){cliente = c;}
        void set_mesa(int num){numero_mesa = num;}

        void print_info(){//Para printar as informações da reserva.
            cout << "Cliente:\n";
            cliente->print_info();
            cout << "Mesa: " << numero_mesa << endl;
        }
};

// * Pedido: um pedido feito por um cliente.
class Pedido{
    Cliente* cliente;
    vector<Prato*> pedidos;

    public:
        Pedido(Cliente *c, vector<Prato*> pp): cliente{c}, pedidos{pp} {}
        ~Pedido() {delete cliente; pedidos.clear();}

        //Getters
        Cliente* get_cliente(){return cliente;}
        vector<Prato*>& get_pedidos(){return pedidos;}

        //Setters
        void set_cliente(Cliente *c){cliente = c;}
        void set_pedidos(vector<Prato*> pp){pedidos = pp;}

        void print_info(){ //Para printar as informações do pedido.
            cout << "Cliente:\n";
            cliente->print_info();
            cout << "Pedidos:\n";
            for (auto& pedido : pedidos) {
                cout << "Nome: " << pedido->get_nome() << ", Preco: " << pedido->get_preco() << "\n";
            }
        }
};

// * Restaurante: cardápio, coleção de pedidos e reservas.
class Restaurante{
    Cardapio cardapio;
    vector<Pedido*> pedidos;
    vector<Reserva*> reservas;

    public:
        Restaurante() {}
        ~Restaurante() {pedidos.clear(); reservas.clear();} //Desalocando memória dos vetores do tipo Pedido e Reserva.

        //Getters
        Cardapio& get_cardapio(){return cardapio;}
        vector<Pedido*>& get_pedidos(){return pedidos;}
        vector<Reserva*>& get_reservas(){return reservas;}

        //Setters
        void adicionar_reserva(Reserva *r) { reservas.push_back(r); }
        void adicionar_pedido(Pedido *p) { pedidos.push_back(p); }
        void set_cardapio(Cardapio c) { cardapio = c; }
};


// - Faça uma função main de tal forma que a verificar as seguintes funcionalidades:
// * Cadastro: permitir o cadastro de novos itens no cardápio, reservas e pedidos.
// * Gerenciamento de reservas: permitir a visualização de reservas cadastradas.
// * Gerenciamento de pedidos: permitir a visualização de pedidos registrados.
int main() {
    Restaurante restaurante;
    Cardapio cardapio;

    // Cria instâncias de pratos, bebida e sobremesa e aloca dinamicamente memória para eles.
    Prato* prato1 = new Prato("PRATO PRINCIPAL", "Yakissoba", 25.0);
    Prato* prato2 = new Prato("PRATO PRINCIPAL", "Sushi", 20.0);
    Prato* bebida1 = new Prato("BEBIDA", "Pepsi", 5.0);
    Prato* sobremesa1 = new Prato("SOBREMESA", "Brigadeiro", 8.0);

    // Adiciona os pratos, bebida e sobremesa ao cardápio.
    cardapio.add_prato(prato1);
    cardapio.add_prato(prato2);
    cardapio.add_bebida(bebida1);
    cardapio.add_sobremesa(sobremesa1);

    // Define o cardápio no restaurante.
    restaurante.set_cardapio(cardapio);

    // Cria instâncias de clientes e aloca dinamicamente memória para eles.
    Cliente* cliente1 = new Cliente("nasiasene", "123-456-7890", "Cabo Branco");
    Cliente* cliente2 = new Cliente("Bidu", "987-654-3210", "CI");

    // Cria instâncias de reservas e aloca dinamicamente memória para elas.
    Reserva* reserva1 = new Reserva(cliente1, 1);
    Reserva* reserva2 = new Reserva(cliente2, 2);

    // Cria vetores de pedidos para clientes.
    vector<Prato*> pedidos_cliente1_novo;
    pedidos_cliente1_novo.push_back(prato2);
    pedidos_cliente1_novo.push_back(bebida1);
    pedidos_cliente1_novo.push_back(sobremesa1);

    // Cria instâncias de pedidos e aloca dinamicamente memória para eles.
    Pedido* pedido1 = new Pedido(cliente1, pedidos_cliente1_novo);

    // Cria vetores de pedidos para clientes.
    vector<Prato*> pedidos_cliente2_novo;
    pedidos_cliente2_novo.push_back(prato2);
    pedidos_cliente2_novo.push_back(bebida1);

    // Cria instâncias de pedidos e aloca dinamicamente memória para eles.
    Pedido* pedido2 = new Pedido(cliente2, pedidos_cliente2_novo);

    // Adiciona reservas e pedidos ao restaurante.
    restaurante.adicionar_reserva(reserva1);
    restaurante.adicionar_reserva(reserva2);
    restaurante.adicionar_pedido(pedido1);
    restaurante.adicionar_pedido(pedido2);

    // Cria outro vetor de pedidos para o cliente1.
    vector<Prato*> pedidos_cliente1_novo2;
    pedidos_cliente1_novo2.push_back(prato2);
    pedidos_cliente1_novo2.push_back(bebida1);
    pedidos_cliente1_novo2.push_back(sobremesa1);

    // Cria mais uma instância de pedido e aloca dinamicamente memória para ela.
    Pedido* pedido3 = new Pedido(cliente1, pedidos_cliente1_novo2);

    // Adiciona mais um pedido ao restaurante.
    restaurante.adicionar_pedido(pedido3);

    // Obtém as listas de reservas e pedidos do restaurante.
    auto reservas = restaurante.get_reservas();
    auto pedidos = restaurante.get_pedidos();

    // Exibe as informações de reservas e pedidos.
    cout << "--------------------------------------------------------------------\n";
    if (!reservas.empty()) {
        cout << "Reservas: \n";
        for (Reserva* reserva : reservas) {
            reserva->print_info();
            cout << endl;
        }
    } else {
        cout << "Nenhuma reserva cadastrada.\n";
    }

    cout << "--------------------------------------------------------------------\n";
    if (!pedidos.empty()) {
        cout << "Pedidos: \n";
        for (Pedido* pedido : pedidos) {
            pedido->print_info();
            cout << endl;
        }
    } else {
        cout << "Nenhum pedido registrado.\n";
    }

     // Libera memória alocada para clientes, pratos e cardápio
    delete cliente1;
    delete cliente2;
    delete prato1;
    delete prato2;
    delete bebida1;
    delete sobremesa1;   
}