class Pessoa
    attr_accessor :nome
    def initialize(nome, idade)
        @nome = nome
        @idade = idade
    end

    def apresentar
        puts "Olá, meu nome é #{@nome} e tenho #{@idade} anos"
    end

    def falar
        puts "Olá, eu sou uma pessoa"
    end

    def falar_babusera
        puts "guilerme toma banho comigo"
    end
end

pessoa = Pessoa.new("Gui tomando banho", 2141)
pessoa.falar_babusera
pessoa.apresentar
pessoa.nome = "Guilherme Calma Calabreso da Silva :P"
pessoa.apresentar