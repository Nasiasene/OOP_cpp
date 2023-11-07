// uso do copilot: GETS/SETS
// Uso do GPT: main

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

class Calcado; //Para poder usar na classe fornecedor.

// 1. **fornecedor**
//    - Atributos: nome (string), cnpj (string).
//    - Métodos: construtor, getters e setters, listar produtos do fornecedor.
class Fornecedor{
    string nome, cnpj;
    
    public:
        Fornecedor(string no, string cn) : nome{no}, cnpj{cn} {}

        //GETS:
        string get_nome(){return nome;}
        string get_cnpj(){return cnpj;}

        //SETS:
        void set_nome(string no){nome = no;}
        void set_cnpj(string cn){cnpj = cn;}

        // // //LISTAR PRODUTOS DO FORNECEDOR:
        // void listar_produtos(vector<Calcado>& calcados) {
        //     for (auto& calcado : calcados) {
        //         if (calcado.get_fornecedor() == this) {
        //             cout << "Marca: " << calcado.get_marca() << ", Modelo: " << calcado.get_modelo() << endl;
        //         }
        //     }
        // }
};

// 2. **calcado** (classe base, abstrata)
//    - Atributos: marca (string), modelo (string), cor (string), tamanho (int),
//      preço (double), fornecedor (ponteiro para fornecedor).
//    - Métodos: construtor, getters e setters, exibir informações (virtual)
// Tratamento de exceções: faça com que só produtos com preços positivos possam 
// ser incluídos no estoque - use o tratamento de exceções para garantir isso.
class Calcado{
    private:
        string marca, modelo, cor;
        int tamanho;
        double preco;
        Fornecedor *fornecedor;

    public:
        Calcado(string ma, string mo, string co, int ta, double pr, Fornecedor &f) : marca{ma}, modelo{mo}, cor{co}, tamanho{ta}, preco{pr}, fornecedor{&f} {}

        //GETS:
        string get_marca(){return marca;}
        string get_modelo(){return modelo;}
        string get_cor(){return cor;}
        int get_tamanho(){return tamanho;}
        double get_preco(){return preco;}
        Fornecedor *get_fornecedor(){return fornecedor;}

        //SETS:
        void set_marca(string ma){marca = ma;}
        void set_modelo(string mo){modelo = mo;}
        void set_cor(string co){cor = co;}
        void set_tamanho(int ta){tamanho = ta;}
        void set_preco(double pr) {
            if (pr <= 0) {
                preco = pr;
            } else {
                throw invalid_argument("Preço nao pode ser negativo."); //CUIDANDO DAS EXCEÇÕES EM CASO DE NUMEROS NEGATIVOS.
            }
        }
        void set_fornecedor(Fornecedor &f){fornecedor = &f;}

        //EXIBIR INFORMAÇÕES:
        virtual void exibir_informacoes(){ //Método virtual, tornando a classe abstrata.
            cout << "Marca: " << get_marca() << endl;
            cout << "Modelo: " << get_modelo() << endl;
            cout << "Cor: " << get_cor() << endl;
            cout << "Tamanho: " << get_tamanho() << endl;
            cout << "Preço: " << get_preco() << endl;
            cout << "Fornecedor: " << get_fornecedor()->get_nome() << endl;
        }

        void listar_produtos(vector<Calcado>& calcados) {
            for (auto& calcado : calcados) {
                if (calcado.get_fornecedor() == fornecedor) {
                    cout << "Marca: " << calcado.get_marca() << ", Modelo: " << calcado.get_modelo() << endl;
                }
            }
        }
};

// 3. **tenis** (herança pública de calcado)
//    - Atributos: tipo de esporte (string).
//    - Métodos: construtor, getters e setters, sobrescrever o método de exibir 
//      informações.
class Tenis : public Calcado{
    string tipo_esporte;

    public:
        Tenis(string ma, string mo, string co, int ta, double pr, Fornecedor &f, string te) : Calcado(ma, mo, co, ta, pr, f), tipo_esporte{te} {}

        //GETS:
        string get_tipo_esporte(){return tipo_esporte;}

        //SETS:
        void set_tipo_esporte(string te){tipo_esporte = te;}

        //SOBRESCREVER O MÉTODO DE EXIBIR INFORMAÇÕES:
        virtual void exibir_informacoes() override{
            Calcado::exibir_informacoes();
            cout << "Tipo de esporte: " << get_tipo_esporte() << endl;
        }

};

// 4. **sapato_social** (herança pública de calcado)
//    - Atributos: material (string).
//    - Métodos: construtor, getters e setters, sobrescrever o método de exibir 
//      informações.
class SapatoSocial : public Calcado{
    string material;

    public:
        SapatoSocial(string ma, string mo, string co, int ta, double pr, Fornecedor &f, string mat) : Calcado(ma, mo, co, ta, pr, f), material{mat} {}

        //GETS:
        string get_material(){return material;}

        //SETS:
        void set_material(string mat){material = mat;}

        //SOBRESCREVER O MÉTODO DE EXIBIR INFORMAÇÕES:
        virtual void exibir_informacoes() override{
            Calcado::exibir_informacoes();
            cout << "Material: " << get_material() << endl;
        }
};

// 5. **estoque**
//    - Atributos: lista de produtos em estoque (vector de calcado).
//    - Métodos: construtor, destrutor, adicionar e remover produtos ao/do estoque,
//      calcular o valor total do estoque, encontrar produtos no estoque.
class Estoque{
    vector<Calcado> produtos;

    public:
        Estoque() {}
        ~Estoque() {produtos.clear();}

        //ADICIONAR E REMOVER PRODUTOS AO/DO ESTOQUE:
        void adicionar_produto(Calcado &c){produtos.push_back(c);}

        void remover_produto(const string& marca, const string& modelo) {
            for (auto it = produtos.begin(); it != produtos.end(); ++it) {
                if (it->get_marca() == marca && it->get_modelo() == modelo) {
                    produtos.erase(it);
                    break;
                }
            }
        }


        //CALCULAR O VALOR TOTAL DO ESTOQUE:
        double calcular_valor_total(){
            double valor_total = 0;
            for(auto &calcado : produtos){
                valor_total += calcado.get_preco();
            }
            return valor_total;
        }

        //ENCONTRAR PRODUTOS NO ESTOQUE:
        void encontrar_produtos(string ma, string mo){
            for(auto &calcado : produtos){
                if(calcado.get_marca() == ma && calcado.get_modelo() == mo){
                    calcado.exibir_informacoes();
                }
            }
        }
};

// 6. **fabrica** (singleton)
//    - Atributos: fornecedores (map de fornecedor, string como chave), estoque 
//      (instância de estoque).
//    - Métodos: construtor, destrutor, adicionar e remover fornecedor, adicionar
//      e remover produto ao/do estoque, calcular o valor total do estoque, 
//      encontrar produtos no estoque.
class Fabrica{
Fabrica() {} //Construtor privado para o singleton.
static Fabrica *_instance;

    public:
    map<string, Fornecedor> fornecedores;
    Estoque estoque;
    ~Fabrica() {fornecedores.clear();}

    static Fabrica *get_instance(){
        if (_instance == NULL)
            _instance = new Fabrica();
        return _instance;
    }

    //ADICIONAR E REMOVER FORNECEDOR:
    void adicionar_fornecedor(Fornecedor &f){fornecedores.insert(pair<string, Fornecedor>(f.get_nome(), f));}
    void remover_fornecedor(Fornecedor &f){fornecedores.erase(f.get_nome());}

    //ADICIONAR E REMOVER PRODUTO AO/DO ESTOQUE:
    void adicionar_produto(Calcado &c){estoque.adicionar_produto(c);}
    void remover_produto(Calcado &c){estoque.remover_produto(c.get_marca(), c.get_modelo());}
    //CALCULAR O VALOR TOTAL DO ESTOQUE:
    double calcular_valor_total(){return estoque.calcular_valor_total();}
    //ENCONTRAR PRODUTOS NO ESTOQUE:
    void encontrar_produtos(string ma, string mo){estoque.encontrar_produtos(ma, mo);}
};
Fabrica *Fabrica::_instance = NULL; //Inicializando o singleton.



// Uso das classes: implemente um sistema com um menu que permita: cadastrar, 
// remover e listar fornecedores; cadastrar, remover e listar tênis e sapatos
// sociais no estoque; exibir valor total do estoque; buscar produtos no estoque;
int main() {
    Fabrica *fabrica = Fabrica::get_instance(); //Singleton

    while (true) {
        int opcao;
        cout << "Escolha uma opção:" << endl;
        cout << "1. Cadastrar fornecedor" << endl;
        cout << "2. Remover fornecedor" << endl;
        cout << "3. Listar fornecedores" << endl;
        cout << "4. Cadastrar tênis" << endl;
        cout << "5. Cadastrar sapato social" << endl;
        cout << "6. Remover produto do estoque" << endl;
        cout << "7. Exibir valor total do estoque" << endl;
        cout << "8. Buscar produtos no estoque" << endl;
        cout << "0. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string nome, cnpj;
                cout << "Nome do fornecedor: ";
                cin.ignore();
                getline(cin, nome);
                cout << "CNPJ do fornecedor: ";
                cin >> cnpj;
                Fornecedor fornecedor(nome, cnpj);
                fabrica->adicionar_fornecedor(fornecedor);
                cout << "Fornecedor cadastrado com sucesso." << endl;
                break;
            }
            case 2: {
                string nome;
                cout << "Nome do fornecedor a ser removido: ";
                cin.ignore();
                getline(cin, nome);
                auto it = fabrica->fornecedores.find(nome);
                if (it != fabrica->fornecedores.end()) {
                    fabrica->remover_fornecedor(it->second);
                    cout << "Fornecedor removido com sucesso." << endl;
                } else {
                    cout << "Fornecedor não encontrado." << endl;
                }
                break;
            }
            case 3: {
                cout << "Lista de fornecedores:" << endl;
                for (auto &pair : fabrica->fornecedores) {
                    cout << "Nome: " << pair.first << ", CNPJ: " << pair.second.get_cnpj() << endl;
                }
                break;
            }
            case 4: {
                string ma, mo, cor, tipo;
                int tamanho;
                double preco;
                cout << "Marca: ";
                cin.ignore();
                getline(cin, ma);
                cout << "Modelo: ";
                getline(cin, mo);
                cout << "Cor: ";
                getline(cin, cor);
                cout << "Tamanho: ";
                cin >> tamanho;
                cout << "Preço: ";
                cin >> preco;
                cout << "Tipo de esporte: ";
                cin.ignore();
                getline(cin, tipo);
                Fornecedor fornecedor("", "");  // Fornecedor vazio temporário
                Tenis tenis(ma, mo, cor, tamanho, preco, fornecedor, tipo);
                fabrica->estoque.adicionar_produto(tenis);
                cout << "Tenis cadastrado com sucesso." << endl;
                break;
            }
            case 5: {
                string ma, mo, cor, material;
                int tamanho;
                double preco;
                cout << "Marca: ";
                cin.ignore();
                getline(cin, ma);
                cout << "Modelo: ";
                getline(cin, mo);
                cout << "Cor: ";
                getline(cin, cor);
                cout << "Tamanho: ";
                cin >> tamanho;
                cout << "Preco: ";
                cin >> preco;
                cout << "Material: ";
                cin.ignore();
                getline(cin, material);
                Fornecedor fornecedor("", "");  // Fornecedor vazio temporário
                SapatoSocial sapato_social(ma, mo, cor, tamanho, preco, fornecedor, material);
                fabrica->estoque.adicionar_produto(sapato_social);
                cout << "Sapato social cadastrado com sucesso." << endl;
                break;
            }
            case 6: {
                string ma, mo;
                cout << "Marca do produto a ser removido: ";
                cin.ignore();
                getline(cin, ma);
                cout << "Modelo do produto a ser removido: ";
                getline(cin, mo);
                fabrica->estoque.remover_produto(ma, mo);
                cout << "Produto removido do estoque." << endl;
                break;
            }
            case 7: {
                double valor_total = fabrica->estoque.calcular_valor_total();
                cout << "Valor total do estoque: " << valor_total << endl;
                break;
            }
            case 8: {
                string ma, mo;
                cout << "Marca do produto a ser buscado: ";
                cin.ignore();
                getline(cin, ma);
                cout << "Modelo do produto a ser buscado: ";
                getline(cin, mo);
                fabrica->estoque.encontrar_produtos(ma, mo);
                break;
            }
            case 0: {
                delete fabrica;
                return 0;
            }
            default:
                cout << "Opção inalida. Tente novamente." << endl;
        }
    }
}