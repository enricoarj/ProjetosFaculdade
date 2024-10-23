# Cálculo de média
# Desenvolva um sistema que calcula a média de uma lista de notas inserida pelo usuário

notas = []
escolha = 1

p 'Olá, vamos começar a inserir as notas no programa?'

while escolha != 0
    p 'Por favor, digite a nota a ser inserida: '
    notas.push(gets.chomp.to_f)
    p notas

    p 'Se deseja adicionar mais uma nota, digite [1], se deseja sair, digite [0]'
    escolha = gets.chomp.to_i

end

p "As notas foram: #{notas}"

somatorio = 0
contador = 0

notas.each do |nota|
    somatorio += nota
    contador += 1
end

media = somatorio / contador
p "Quntidade de notas #{contador}"
p "A média das notas foi de = #{media}"