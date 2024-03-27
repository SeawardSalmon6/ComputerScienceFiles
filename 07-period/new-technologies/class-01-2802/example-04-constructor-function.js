function Pessoa(nome) {
  this.nome = nome;
  this.falar = () => {
    console.log(`Meu nome é ${this.nome}`);
  }
}

const joao = new Pessoa('João');
joao.falar();

