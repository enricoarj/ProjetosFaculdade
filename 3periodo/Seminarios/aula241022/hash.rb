# pessoa = { nome: "Aluan", idade: 35, cidade: "Poços de Caldas"}
# puts "Nome : #{pessoa[:nome]}"
# puts "Idade: #{pessoa[:idade]}"
# pessoa[:idade] = 36
# puts pessoa
# p "Adicionando novo campo"
# pessoa[:profissao] = "Engenheiro de Software"

p "Multiplo Hash"
hash_pessoa = {
    pessoas:[
        { nome: "Aluan", idade: 35, cidade: "Poços de Caldas"},
        { nome: "Enrico", idade: 20, cidade: "Poços de Caldas"},
         #amigos:[{ nome: "Marcus", idade: "Nao sei", cidade: "Quase Sao Paulo"}]},
         { nome: "Marcus", idade: "Nao sei", cidade: "Quase Sao Paulo"}
    ]
}

#p "Amigo do riku:"

hash_pessoa[:pessoas].each do |pessoa|
    p "Nome: #{pessoa[:nome]}"
    p "Idade: #{pessoa[:idade]}"
    p "Cidade: #{pessoa[:cidade]}"
end