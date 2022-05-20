public class Carro
{
  private String nome;
  private String cor;
  private String marca;
  private int ano;
  private int qtdRodas;
  private float km;
  private float peso;
  private float valorDeVenda;
  
  public void setNome(String nome)
  {
	if(nome.length() > 0) {
		this.nome = nome;
	} else {
		System.out.println("Valor inválido!");
	}
  }
  
  public String getNome()
  {
	return this.nome;
  }
  
  public void setCor(String cor)
  {
	this.cor = cor;
  }
  
  public String getCor()
  {
	return this.cor;
  }
  
  public void setMarca(String marca)
  {
	this.marca = marca;
  }
  
  public String getMarca()
  {
	return this.marca;
  }
  
  public void setAno(int ano)
  {
	if((ano > 1900) && (ano <= 2022)) {
		this.ano = ano;
	} else {
		System.out.println("Valor inválido!");
	}
  }
  
  public int getAno()
  {
	return this.ano;
  }
  
  public void setKm(float km)
  {
	if(km >= 0) {
		this.km = km;
	} else {
		System.out.println("Valor inválido!");
	}
  }
  
  public int getQtdRodas()
  {
	return this.qtdRodas;
  }
  
  public void setQtdRodas(int qtdRodas)
  {
	if(qtdRodas > 2) {
		this.qtdRodas = qtdRodas;
	} else {
		System.out.println("Valor inválido!");
	}
  }
  
  public float getKm()
  {
	return this.km;
  }
  
  public void setPeso(float peso)
  {
	if(peso > 0) {
		this.peso = peso;
	} else {
		System.out.println("Valor inválido!");
	}
  }
  
  public float getPeso()
  {
	return this.peso;
  }
  
  public float getValorDeVenda()
  {
	return this.valorDeVenda;
  }
  
  public void setValorDeVenda(float valorDeVenda)
  {
	if(valorDeVenda > 0) {
		this.valorDeVenda = valorDeVenda;
	} else {
		System.out.println("Valor inválido!");
	}
  }
  
  // --> Metódos da Extra-Classe
  public void oCarroEhBonito()
  {
	if(this.nome == "Opala" || this.nome == "Fusca") {
		System.out.println("Ele é muito bonito!");
	} else {
		System.out.println("O carro já foi melhor...");
	}
  }
  
  public void ligarMotor()
  {
	System.out.println("Vrum vrum... vrum vrum VRUM!");
  }
}