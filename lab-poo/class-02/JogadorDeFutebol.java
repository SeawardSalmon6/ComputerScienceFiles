public class JogadorDeFutebol
{
	private String nome;
	private String timeDoCoracao;
	private String timeAtual;
	private int idade;
	private float altura;
	private float peso;
	private boolean ehAposentado;
	
	public String getNome()
	{
		return this.nome;
	}
	
	public void setNome(String nome)
	{
		if(nome.length() > 0) {
			this.nome = nome;
		} else {
			System.out.println("Valor é inválido!");
		}
	}
	
	public String getTimeDoCoracao()
	{
		return this.timeDoCoracao;
	}
	
	public void setTimeDoCoracao(String timeDoCoracao)
	{
		if(timeDoCoracao.length() > 0) {
			this.timeDoCoracao = timeDoCoracao;
		} else {
			System.out.println("Valor é inválido!");
		}
	}
	
	public String getTimeAtual()
	{
		return this.timeAtual;
	}
	
	public void setTimeAtual(String timeAtual)
	{
		if(timeAtual.length() > 0) {
			this.timeAtual = timeAtual;
		} else {
			System.out.println("Valor é inválido!");
		}
	}
	
	public int getIdade()
	{
		return this.idade;
	}
	
	public void setIdade(int idade)
	{
		if(idade > 8) {
			this.idade = idade;
		} else {
			System.out.println("Valor é inválido!");
		}
	}
	
	public float getAltura()
	{
		return this.altura;
	}
	
	public void setAltura(float altura)
	{
		if(altura > 0) {
			this.altura = altura;
		} else {
			System.out.println("Valor é inválido!");
		}
	}
	
	public float getPeso()
	{
		return this.peso;
	}
	
	public void setPeso(float peso)
	{
		if(peso > 0) {
			this.peso = peso;
		} else {
			System.out.println("Valor é inválido!");
		}
	}
	
	public boolean getEhAposentado()
	{
		return this.ehAposentado;
	}
	
	public void setEhAposentado(boolean ehAposentado)
	{
		this.ehAposentado = ehAposentado;
	}
}