public class Principal
{
  public static void main(String[] args)
  {
    Carro fusca = new Carro();
	fusca.setNome("Fusca");
	fusca.setCor("Verde");
	fusca.setMarca("Ford");
	fusca.setAno(1978);
	fusca.setQtdRodas(4);
	fusca.setKm(0);
	fusca.setPeso(1000);
	fusca.setValorDeVenda(20000);
	
	System.out.println(fusca.getNome());
	System.out.println(fusca.getCor());
	System.out.println(fusca.getMarca());
	System.out.println(fusca.getAno());
	System.out.println(fusca.getQtdRodas());
	System.out.println(fusca.getKm());
	System.out.println(fusca.getPeso());
	System.out.println(fusca.getValorDeVenda());
	fusca.oCarroEhBonito();
	fusca.ligarMotor();
	
	Carro opala = new Carro();
	opala.setNome("Opala");
	opala.setCor("Azul");
	opala.setMarca("Chevrolet");
	opala.setAno(1956);
	opala.setQtdRodas(4);
	opala.setKm(18723);
	opala.setPeso(1583);
	opala.setValorDeVenda(22000);
	
	Carro camaro = new Carro();
	camaro.setNome("Camaro");
	camaro.setCor("Amarelo");
	camaro.setMarca("Chevrolet");
	camaro.setAno(2014);
	camaro.setQtdRodas(4);
	camaro.setKm(0);
	camaro.setPeso(1512);
	camaro.setValorDeVenda(50000);
  }
}