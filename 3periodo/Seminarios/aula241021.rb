puts "Vamos fazer uma operacao? Digite o primeiro numero: "
num1 = gets.chomp.to_i
puts "Escolha a operacao a ser realizada: "
operacao = gets.chomp
puts "Digite o segundo numero: "
num2 = gets.chomp.to_i

case operacao
    when "+"
        soma = num1 + num2
        puts "O resultado da soma de #{num1} mais #{num2} eh = #{soma}"
    when "-"
        subtracao = num1 - num2
        puts "O resultado da subtracao de #{num1} menos #{num2} eh = #{subtracao}"
    when "*"
        multiplicacao = num1 * num2
        puts "O resultado da multiplicacao de #{num1} vezes #{num2} eh = #{multiplicacao}" 
    when "/"
        unless num2 == 0 then
            puts "Ops, nao podemos fazer uma divisao por 0 ne paizao"
        else
            divisao = num1/num2
            puts "O resultado da divisao de #{num1} divido por #{num2} eh = #{divisao}"
        end
    else
        puts "Ops, operacao invalida"
end
