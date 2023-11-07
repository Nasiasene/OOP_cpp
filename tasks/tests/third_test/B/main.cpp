#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. **uva**
//    - Atributos: nome (string), safra (int), preço por quilo (double).
//    - Métodos: construtor, getters e setters.
class Uva{
    string nome;
    int safra;
    double preco_por_quilo;

    public:
        Uva(string nn, int ss, double pq): nome(nn), safra(ss), preco_por_quilo(pq){}

        //GETTERS
        string get_nome(){return nome;}
        int get_safra(){return safra;}
        double get_preco_por_quilo(){return preco_por_quilo;}

        //SETTERS
        void set_nome(string nn){nome = nn;}
        void set_safra(int ss){safra = ss;}
        void set_preco_por_quilo(double pq){preco_por_quilo = pq;}
};
 
// 2. **vinho** (classe base, abstrata)
//    - Atributos: nome (string), safra (int), volume (double), uva (ponteiro para
//      a classe Uva), quantidade (int, variável de classe)
//    - Métodos: construtor, getters e setters, exibir informações (virtual), 
//      get_quantidade (método de classe)
// Tratamento de exceções: use o tratamento de exceções para garantir que não
// sejam cadastrados vinhos sem uva definida ou ano de safra inválido.
 class Vinho{
        protected:
        string nome;
        int safra;
        double volume;
        Uva *uva;
        int quantidade;
    
        public:
            Vinho(string nn, int ss, double vv, Uva *uu, int qq){
                //Tratamento de exceções.
                if (uu == NULL)
                    throw "Uva não definida";
                if (ss < 0)
                    throw "Safra inválida"; 
                nome = nn;
                safra = ss;
                volume = vv;
                uva = uu;
                quantidade = qq;
            }
    
            //GETTERS
            string get_nome(){return nome;}
            int get_safra(){return safra;}
            double get_volume(){return volume;}
            Uva *get_uva(){return uva;}
            int get_quantidade() { return quantidade; }
    
            //SETTERS
            void set_nome(string nn){nome = nn;}
            void set_safra(int ss){safra = ss;}
            void set_volume(double vv){volume = vv;}
            void set_uva(Uva *uu){uva = uu;}
            void set_quantidade(int qq){quantidade = qq;}
    
            virtual void exibir_informacoes(){
                cout << "Nome: " << nome << endl;
                cout << "Safra: " << safra << endl;
                cout << "Volume: " << volume << endl;
                cout << "Uva: " << uva->get_nome() << endl;
                cout << "Quantidade: " << quantidade << endl;
            }
 };


// 3. **vinho_tinto** (herança pública de vinho)
//    - Atributos: nível de tanino (float), quantidade de polifenois (float)
//    - Métodos: construtor, getters e setters, sobrescrever exibir informações
class VinhoTinto : public Vinho{
    double nivel_de_tanino;
    double quantidade_de_polifenois;

    public:
        VinhoTinto(string nn, int ss, double vv, Uva *uu, int qq, double nt, double qp): Vinho(nn, ss, vv, uu, qq), nivel_de_tanino(nt), quantidade_de_polifenois(qp){}

        //GETTERS
        double get_nivel_de_tanino(){return nivel_de_tanino;}
        double get_quantidade_de_polifenois(){return quantidade_de_polifenois;}

        //SETTERS
        void set_nivel_de_tanino(double nivel_de_tanino){nivel_de_tanino = nivel_de_tanino;}
        void set_quantidade_de_polifenois(double quantidade_de_polifenois){quantidade_de_polifenois = quantidade_de_polifenois;}

        void exibir_informacoes(){
            Vinho::exibir_informacoes();
            cout << "Nível de tanino: " << nivel_de_tanino << endl;
            cout << "Quantidade de polifenois: " << quantidade_de_polifenois << endl;
        }
};
 
// 4. **vinho_branco** (herança pública de Vinho)
//    - Atributos: subtipo (string, ex. "Seco" ou "Suave")
//    - Métodos: construtor, getters e setters, sobrescrever exibir informações
class VinhoBranco : public Vinho{
    string subtipo;

    public:
        VinhoBranco(string nn, int ss, double vv, Uva *uu, int qq, string st): Vinho(nn, ss, vv, uu, qq), subtipo(st){}

        //GETTERS
        string get_subtipo(){return subtipo;}

        //SETTERS
        void set_subtipo(string subtipo){subtipo = subtipo;}

        void exibir_informacoes(){
            Vinho::exibir_informacoes();
            cout << "Subtipo: " << subtipo << endl;
        }
};


// 5. **cliente**
//    - Atributos: nome (string), sobrenome (string), email (string), telefone 
//    (string).
//    - Métodos: construtor, getters e setters.
class Client{
    string nome;
    string sobrenome;
    string email;
    string telefone;

    public:
        Client(string nn, string sn, string em, string tel): nome(nn), sobrenome(sn), email(em), telefone(tel){}

        //GETTERS
        string get_nome(){return nome;}
        string get_sobrenome(){return sobrenome;}
        string get_email(){return email;}
        string get_telefone(){return telefone;}

        //SETTERS
        void set_nome(string nn){nome = nn;}
        void set_sobrenome(string sn){sobrenome = sn;}
        void set_email(string em){email = em;}
        void set_telefone(string tel){telefone = tel;}
};
 
// 6. **venda**
//    - Atributos: cliente (ponteiro para a classe cliente), vinho (ponteiro para
//      a classe vinho), quantidade (int).
//    - Métodos: construtor, getters e setters, calcular_total() para calcular o 
//      valor total da venda.
class Venda{
    Client *cliente;
    Vinho *vinho;
    int quantidade;

    public:
        Venda(Client *cc, Vinho *vv, int qq): cliente(cc), vinho(vv), quantidade(qq){}

        //GETTERS
        Client *get_cliente(){return cliente;}
        Vinho *get_vinho(){return vinho;}
        int get_quantidade(){return quantidade;}

        //SETTERS
        void set_cliente(Client *cc){cliente = cc;}
        void set_vinho(Vinho *vv){vinho = vv;}
        void set_quantidade(int qq){quantidade = qq;}

        double calcular_total(){
            return quantidade * vinho->get_volume();
        }
};
 
// 7. **vinicola** (singleton)
//    - Atributos: lista de uvas (vector de uva), lista de vinhos (vector de
//      vinho), lista de clientes (vector de cliente), lista de vendas (vector 
//      de venda).
//    - Métodos: adicionar uva, adicionar vinho, adicionar cliente, registrar 
//      venda, calcular soma de todas as vendas.
class Vinicola{
    Vinicola () {}
    static Vinicola *_instance; //ponteiro para a instância única da classe.

    protected:
        vector<Uva> lista_de_uvas;
        vector<Vinho> lista_de_vinhos;
        vector<Client> lista_de_clientes;
        vector<Venda> lista_de_vendas;

    public:
        static Vinicola *get_instance(){ //método para acessar a instância única da classe.
            if (_instance == NULL)
                _instance = new Vinicola();
            return _instance;
        }

        void adicionar_uva(Uva uu){lista_de_uvas.push_back(uu);}
        void adicionar_vinho(Vinho vv){lista_de_vinhos.push_back(vv);}
        void adicionar_cliente(Client cc){lista_de_clientes.push_back(cc);}

        void registrar_venda(Venda vv){lista_de_vendas.push_back(vv);}

        double calcular_soma_de_todas_as_vendas(){
            double soma = 0;
            for (auto i = 0; i < int(lista_de_vendas.size()); i++){
                soma += lista_de_vendas[i].calcular_total();
            }
            return soma;
        }
};
Vinicola *Vinicola::_instance = NULL; //inicialização do ponteiro para a instância única da classe.

 
// 8. **vinoteca** (classe genérica usando templates)
//    - Atributos: lista de vinhos (vector de T), onde T é o tipo de vinho (pode 
//      ser vinho_tinto, vinho_branco, etc.).
//    - Métodos: adicionar vinho, listar vinhos, encontrar vinho por safra, 
//      calcular o valor total do estoque.
template <typename T> //T é o tipo de vinho(CLASSE) .
class Vinoteca{
    protected:
        vector<T> lista_de_vinhos; //T é o tipo de vinho(OBJETO) .

    public:
        void adicionar_vinho(T vv){lista_de_vinhos.push_back(vv);} //T é o tipo de vinho(OBJETO) .
        void listar_vinhos(){
            for (int i = 0; i < lista_de_vinhos.size(); i++){
                lista_de_vinhos[i].exibir_informacoes();
            }
        }

        void encontrar_vinho_por_safra(int ss){
            for (int i = 0; i < lista_de_vinhos.size(); i++){
                if (lista_de_vinhos[i].get_safra() == ss){
                    lista_de_vinhos[i].exibir_informacoes();
                }
            }
        }

        double calcular_valor_total_do_estoque(){
            double soma = 0;
            for (int i = 0; i < lista_de_vinhos.size(); i++){
                soma += lista_de_vinhos[i].get_quantidade() * lista_de_vinhos[i].get_volume();
            }
            return soma;
        }
};

int main() {
    // Crie uma instância da Vinicola (singleton)
    Vinicola *vinicola = Vinicola::get_instance();

    // Adicione algumas uvas
    Uva uva1("Uva A", 2020, 5.0);
    Uva uva2("Uva B", 2021, 6.0);
    Uva uva3("Uva C", 2019, 4.5);
    vinicola->adicionar_uva(uva1);
    vinicola->adicionar_uva(uva2);
    vinicola->adicionar_uva(uva3);

    // Crie alguns vinhos
    VinhoTinto vinhoTinto1("Vinho Tinto A", 2020, 0.75, &uva1, 10, 3.5, 200);
    VinhoBranco vinhoBranco1("Vinho Branco A", 2021, 0.75, &uva2, 15, "Seco");
    VinhoTinto vinhoTinto2("Vinho Tinto B", 2021, 0.75, &uva2, 8, 4.0, 220);
    VinhoBranco vinhoBranco2("Vinho Branco B", 2019, 0.75, &uva3, 12, "Suave");
    vinicola->adicionar_vinho(vinhoTinto1);
    vinicola->adicionar_vinho(vinhoBranco1);
    vinicola->adicionar_vinho(vinhoTinto2);
    vinicola->adicionar_vinho(vinhoBranco2);

    // Crie alguns clientes
    Client cliente1("Cliente 1", "Sobrenome 1", "cliente1@email.com", "123456789");
    Client cliente2("Cliente 2", "Sobrenome 2", "cliente2@email.com", "987654321");
    vinicola->adicionar_cliente(cliente1);
    vinicola->adicionar_cliente(cliente2);

    // Realize vendas
    Venda venda1(&cliente1, &vinhoTinto1, 3);
    Venda venda2(&cliente2, &vinhoBranco1, 5);
    vinicola->registrar_venda(venda1);
    vinicola->registrar_venda(venda2);

    // Crie duas Vinotecas: uma para vinhos tintos e outra para vinhos brancos
    Vinoteca<VinhoTinto> vinotecaTintos;
    Vinoteca<VinhoBranco> vinotecaBrancos;

    // Adicione alguns vinhos às Vinotecas
    vinotecaTintos.adicionar_vinho(vinhoTinto1);
    vinotecaTintos.adicionar_vinho(vinhoTinto2);
    vinotecaBrancos.adicionar_vinho(vinhoBranco1);
    vinotecaBrancos.adicionar_vinho(vinhoBranco2);

    // Realize buscas nas Vinotecas por safra
    int safraParaBuscar = 2021;
    cout << "Vinhos tintos da safra " << safraParaBuscar << ":" << endl;
    vinotecaTintos.encontrar_vinho_por_safra(safraParaBuscar);

    cout << "Vinhos brancos da safra " << safraParaBuscar << ":" << endl;
    vinotecaBrancos.encontrar_vinho_por_safra(safraParaBuscar);

    // Calcule e exiba o valor total das Vinotecas
    double valorTotalTintos = vinotecaTintos.calcular_valor_total_do_estoque();
    double valorTotalBrancos = vinotecaBrancos.calcular_valor_total_do_estoque();

    cout << "Valor total dos vinhos tintos na Vinoteca: " << valorTotalTintos << " unidades monetárias." << endl;
    cout << "Valor total dos vinhos brancos na Vinoteca: " << valorTotalBrancos << " unidades monetárias." << endl;

    return 0;
}
