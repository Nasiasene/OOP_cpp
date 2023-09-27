#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pessoa{  //Classe abstrata Pessoa(mae)
    //Atributos privados da classe Pessoa
   string nome;
   int idade;

   public:
      //Construtores e Destrutores.
      Pessoa(string nn, int id) : nome{nn}, idade{id} {}
      ~Pessoa() {}


      //Metodo virtual puro.
      virtual void exibir_detalhes() = 0;

      //Sobrecarga do operador de output.
      friend ostream& operator<<(ostream& out, Pessoa& pp){
         out << "\nNome: " << pp.nome << ", Idade: " << pp.idade << endl;
         return out;
      }


      //GETS
      string get_nome(){return nome;}
      int get_idade(){return idade;}
};

class Paciente : public Pessoa{ //Classe Paciente herda publicamente de Pessoa.
   //Atributos privados da classe Paciente.
   int numero_paciente;
   string condicao;

   public:
      //Construtores e Destrutores.
      Paciente(string nn, int id, int np, string cc) : Pessoa(nn, id), numero_paciente{np}, condicao{cc} {}
      ~Paciente() {}

      //Metodo virtual sobrescrito.
      virtual void exibir_detalhes() override  {
         cout << "\nNome: " << this->get_nome() << "\nIdade: " << this->get_idade() << "\nNumero Paciente: " << numero_paciente << "\nCondicao: " << condicao << endl;
      }

        //Sobrecarga do operador de output.
      friend ostream& operator<<(ostream& out, Paciente& pp){
         out << "\nNome: " << pp.get_nome() << "\nIdade: " << pp.get_idade() << "\nNumero Paciente: " << pp.get_numero_paciente() << "\nCondicao: " << pp.get_condicao() << endl;
         return out;
      }

      //GETS
      int get_numero_paciente(){return numero_paciente;}
      string get_condicao(){return condicao;}
};

class Medico : public Pessoa{  //Classe Medico herda publicamente de Pessoa.
  //Atributos privados da classe Medico.
   string especialidade;
   string crm;

   public:
      //Construtores e Destrutores.
      Medico(string nn, int id, string ee, string cc) : Pessoa(nn, id), especialidade{ee}, crm{cc} {}
      ~Medico() {}

        //GETS
      string get_especialidade(){return especialidade;}
      string get_crm(){return crm;}

        //Metodo virtual sobrescrito.
      virtual void exibir_detalhes() override  {
         cout << "\nNome: " << this->get_nome() << "\nIdade: " << this->get_idade() << "\nEspecialidade: " << especialidade << "\nCRM: " << crm << endl;
      }

        //Sobrecarga do operador de output.
      friend ostream& operator<<(ostream& out, Medico& pp){
         out << "\nNome: " << pp.get_nome() << "\nIdade: " << pp.get_idade() << "\nEspecialidade: " << pp.get_especialidade() << "\nCRM: " << pp.get_crm() << endl;
         return out;
      }
};


class Procedimento{  //Classe Procedimento.
    //Atributos privados da classe Procedimento.
   string descricao;
   string data;

   public:
        //Construtores e Destrutores.
      Procedimento(string dd, string da) : descricao{dd}, data{da} {}
        ~Procedimento() {}


        //Metodo virtual sobrescrito.
        void exibir_detalhes(){
         cout << "\nDescricao: " << descricao << "\nData: " << data << endl;
        }

        //Sobrecarga do operador de output.
        friend ostream& operator<<(ostream& out, Procedimento& pp){
         out << "\nDescricao: " << pp.descricao << "\nData: " << pp.data << endl;
         return out;
        }
};

class Hospital{ //Classe Hospital.
   vector<Paciente*> pacientes;
   vector<Medico*> medicos;
   vector<Procedimento*> procedimentos;

   public:
     //Construtores e Destrutores.
      Hospital() {}
      ~Hospital() {
         pacientes.clear();
         medicos.clear();
         procedimentos.clear();
      }

        //SETS(append) 
      void adicionar_paciente(Paciente* pp){pacientes.push_back(pp);}
      void adicionar_medico(Medico* mm){medicos.push_back(mm);}
      void registrar_procedimento(Paciente* pp, Medico* mm, Procedimento* prr){
         

         procedimentos.push_back(prr);
      }

      //GETS(cout)
      void listar_procedimentos(){
         for (int i = 0; i < procedimentos.size(); i++){
            cout << *procedimentos[i] << endl;
         }
      }

      void listar_pacientes(){
         for (int i = 0; i < pacientes.size(); i++){
            cout << *pacientes[i] << endl;
         }
      }
      void listar_medicos(){
         for (int i = 0; i < medicos.size(); i++){
            cout << *medicos[i] << endl;
         }
      }
};


int main(){
    Paciente *p1 = new Paciente("Joao", 20, 1, "Normal");
    Paciente *p2 = new Paciente("Maria", 30, 2, "Normal");
    Paciente *p3 = new Paciente("Pedro", 40, 3, "Normal");

    Medico *m1 = new Medico("Jose", 40, "Cardiologista", "CRM1");
    Medico *m2 = new Medico("Ana", 50, "Clinico Geral", "CRM2");

   Hospital *h1 = new Hospital();

    h1->adicionar_paciente(p1);
    h1->adicionar_paciente(p2);
    h1->adicionar_paciente(p3);

    h1->adicionar_medico(m1);
    h1->adicionar_medico(m2);

    h1->listar_pacientes();
    cout << "\n------------------------\n";
    h1->listar_medicos();

    Procedimento *pr1 = new Procedimento("Exame de sangue", "01/01/2020");
    Procedimento *pr2 = new Procedimento("Exame de urina", "02/01/2020");

    h1->registrar_procedimento(p1, m1, pr1);
    h1->registrar_procedimento(p2, m2, pr2);

    cout << "\n------------------------\n";
    h1->listar_procedimentos();
}