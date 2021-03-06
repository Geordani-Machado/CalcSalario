#include <iostream>
using namespace std;

// Salario 16,78 por hora
// hora extras adicional de 1.5 *
// 6% pra providencia
// 14% federal - 5%estadual - R$ 10 por semanas
// adicional de R$ 35 por dependente acima de três

int Dependentes;
float valorHora, valorHoraExtra = 0, HorasExtra=0, Horas=0, PrevidenciaSocial=0, impostodeRenda=0, Salario=0, Estaduais=0, Sindicato, DescontoDependente, ImpostosTotais=0, SalarioLiquido=0;

int CalcSalarioLiquido (int Salario){
	SalarioLiquido = Salario - ImpostosTotais - DescontoDependente;
	return SalarioLiquido;
}
int CalcDependentes (int Dependentes){
	if(Dependentes >=3){
		return 35;
	}
  	else{
    	DescontoDependente = 0;
    	return 0;
  	}
  }

float CalcPrevidenciaSocial(float Salario){
	PrevidenciaSocial = (Salario*0.06);
  return PrevidenciaSocial;
}

float CalcImpostodeRenda(float Salario)
{
  impostodeRenda = Salario*0.14;
   return impostodeRenda; 
}

float CalcImpostosEstaduais (float Salario)
{ 
  Estaduais = Salario*0.05;
  return Estaduais;
}

float CalcSindicato(float Salario)
{
	Sindicato = 10;
  return Sindicato;
}

float CalcImpostosTotais (float Salario){
  ImpostosTotais = PrevidenciaSocial + impostodeRenda + Estaduais + Sindicato;
	return ImpostosTotais;
}

float CalcSalario (float Horas){
	int HorasExtra;
  float valorHoraExtra;
  valorHora = 16.78;
  valorHoraExtra = valorHora * 1.5;  
  	if (Horas > 44)
  	{
    	HorasExtra = Horas - 44; 
  	}
  Salario = (Horas * 16.78)+(HorasExtra * valorHoraExtra);
  return Salario;
}

int main() {
  cout << "Olá! Quantas horas foram trabalhadas nesta semana?\n";
	cin >> Horas;
  cout << "E quantos dependentes o trabalhador possui?\n";
	cin >> Dependentes;
	cout << "O Salario Bruto é " << CalcSalario(Horas) << endl; 

//Imprime os importos separadamente
  cout << "\nValor dos impostos:";
  cout << "\nPrevidência Social: " << CalcPrevidenciaSocial(Salario) << endl;
  cout << "Imposto de Renda: " << CalcImpostodeRenda(Salario) << endl;
  cout << "Estaduais: " << CalcImpostosEstaduais(Salario) << endl;
  cout << "Sindicato: " << CalcSindicato(Salario) << endl;
  cout << "Os impostos totais são: " << CalcImpostosTotais (Salario) << endl;
	// Calcula os dependentes acima de três
  cout << "\nO desconto de dependente é: " <<CalcDependentes(Dependentes) << endl; 
 // imprime o salario total e subtrai os impostos
	cout << "O Salario líquido é: " << CalcSalarioLiquido(Salario)  << endl; 
 return 0; 
} 


