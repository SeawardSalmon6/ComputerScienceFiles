public class Aula
{
	private String nome;
	private String[] listaAlunos;
	private int qtdAlunos;
	private boolean ehPeriodoNoturno;
	
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
	
	public String[] getListaAlunos()
	{
		return this.listaAlunos;
	}
	
	public void setListaAlunos(String[] listaAlunos)
	{
		if(listaAlunos.length > 0) {
			this.listaAlunos = listaAlunos;
		} else {
			System.out.println("Valor é inválido!");
		}
	}
	
	public int getQtdAlunos()
	{
		return this.qtdAlunos;
	}
	
	public void setQtdAlunos(int qtdAlunos)
	{
		if(qtdAlunos > 0) {
			this.qtdAlunos = qtdAlunos;
		} else {
			System.out.println("Valor é inválido!");
		}
	}
	
	public boolean getEhPeriodoNoturno()
	{
		return this.ehPeriodoNoturno;
	}
	
	public void setEhPeriodoNoturno(boolean ehPeriodoNoturno)
	{
		this.ehPeriodoNoturno = ehPeriodoNoturno;
	}
}