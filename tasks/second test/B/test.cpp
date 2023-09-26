#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pessoa{
   string nome;
   int cpf;

   public:
      Pessoa(string nn, int cc) : nome{nn}, cpf{cc} {}
      ~Pessoa() {}

      virtual void exibir_detalhes() = 0;

      friend ostream& operator<<(ostream& out, Pessoa& pp){
         out << "\nNome: " << pp.nome << ", CPF: " << pp.cpf << endl;
         return out;
      }

      bool operator==(const Pessoa& pp){
         if (this->cpf == pp.cpf)
            return true;
         return false;
      }

      string get_nome(){return nome;}
      int get_cpf(){return cpf;}
};

class Passageiro : public Pessoa{
   int cartao_fidelidade;

   public:
      Passageiro(string nn, int cc, int cf) : Pessoa(nn, cc), cartao_fidelidade{cf} {}
      ~Passageiro() {}

      virtual void exibir_detalhes() override  {
         cout << "\nNome: " << this->get_nome() << "\nCPF: " << this->get_cpf() << "\nCartao Fidelidade: " << cartao_fidelidade;
      }

      friend ostream& operator<<(ostream& out, Passageiro& pp){
         out << "\nNome: " << pp.get_nome() << ", CPF: " << pp.get_cpf() << pp.cartao_fidelidade;
         return out;
      }
      bool operator==(Passageiro& p){
         if (this->get_cpf() == p.get_cpf())
            return true;
         return false;
      }
};


class Voo{
   int numero_voo;
   string origem;
   string destino;
   int data;
   int horario;

   public:
      Voo(int nv, string oo, string dd, int dt, int hh) : numero_voo{nv}, origem{oo}, destino{dd}, data{dt}, horario{hh} {}
      ~Voo() {}

      void exibir_detalhes(){
         cout << "\nNumero do voo: " << numero_voo << "\nOrigem: " << origem << "\nDestino: " << destino << "\nData: " << data << "\nHorario: " << horario;
      }
      friend ostream& operator<<(ostream& out, Voo& vv){
         out << "\nNumero do voo: " << vv.numero_voo << "\nOrigem: " << vv.origem << "\nDestino: " << vv.destino << "\nData: " << vv.data << "\nHorario: " << vv.horario;
         return out;
      }
};

class Reserva{
   Passageiro *passageiro;
   Voo *voo;
   string classe;
   string assento;

   public: 
      Reserva(Passageiro *pp, Voo *vv, string cc, string aa) : passageiro{pp}, voo{vv}, classe{cc}, assento{aa} {}
      ~Reserva() {
         delete passageiro;
         delete voo;
      }

      void exibir_detalhes(){
         cout << "Passageiro: ";
         passageiro->exibir_detalhes();
         cout << "\nVoo: ";
         voo->exibir_detalhes();
         cout << "Classe: " << classe << "\nAssento: " << assento;
      }
      friend ostream& operator<<(ostream& out, Reserva& rr){
         out << "------------\nPassageiro: " << rr.passageiro << "------------\nVoo: " << rr.voo << endl <<"Classe: " << rr.classe << "\nAssento: " << rr.assento;
         return out;
      }
      Passageiro *get_passageiro(){return passageiro;}
};

class Companhia_aerea{
   vector<Voo*> voos;
   vector<Reserva*> reservas;

   public:
      Companhia_aerea() {}
      ~Companhia_aerea() {
         voos.clear();
         reservas.clear();
      }

      void adicionar_voo(Voo* vv){
         voos.push_back(vv);
      }
      void fazer_reserva(Passageiro* pp, Voo* vv, string cc, string aa){
         for (int i = 0; i < reservas.size(); i++){
            if (reservas[i]->get_passageiro() == pp){
               cout << "Passageiro ja fez reserva" << endl;
            }
         }
         Reserva* rr = new Reserva(pp, vv, cc, aa);
         reservas.push_back(rr);
      }

      void listar_voos_disponiveis(){
         for (int i = 0; i < voos.size(); i++){
            voos[i]->exibir_detalhes();
            cout << endl;
         }
      }

      void listar_reservas(){
         for (int i = 0; i < reservas.size(); i++){
            reservas[i]->exibir_detalhes();
            cout << "\n\n";
         }
      }
};


int main(){
    /*Crie uma função `main()` que simule uma companhia aérea, com pelo menos 3 voos disponíveis e 2 reservas feitas por 
    passageiros diferentes. Utilize sobrecarga de operadores para facilitar a exibição das informações dos voos, reservas e passageiros.
    */
   Passageiro *p1 = new Passageiro("Davi", 111, 1);
   Passageiro *p2 = new Passageiro("Nasiasene", 222, 2);

   Voo *v1 = new Voo(1, "JP", "SP", 2021, 10);
   Voo *v2 = new Voo(2, "JP", "CG", 2021, 11);
   Voo *v3 = new Voo(3, "JP", "RJ", 2021, 12);

   Companhia_aerea *c1 = new Companhia_aerea();
   c1->adicionar_voo(v1);
   c1->adicionar_voo(v2);
   c1->adicionar_voo(v3);

   c1->fazer_reserva(p1, v1, "VIP", "A1");
   c1->fazer_reserva(p2, v2, "ECO", "A2");

   c1->listar_voos_disponiveis();
   cout << "\n------------------------------------\n";
   c1->listar_reservas();
}
