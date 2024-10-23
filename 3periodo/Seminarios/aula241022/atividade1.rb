# Crie um programa que descubra números pares/ímpares
# - Sistema pede número e fala se é par ou ímpares
# - O usuário demonstra quando quer parar
# - No final o sistema mostra quais números foram pares e quais foram ímpares
# * Durante o uso vai mostrando se o número for par ou ímpar

escolha = 1
numeros_pares = []
numeros_impares = []

until escolha == 0 

    p 'Digite um número para descobrirmos se é par ou ímpar = '
    numero_digitado = gets.chomp.to_i

    verificador = numero_digitado % 2
    if verificador == 0
        p "O número digitado é par"
        numeros_pares.push(numero_digitado)  
    else
        p "O número digitador é ímpar"
        numeros_impares.push(numero_digitado)  
    end

    p 'Deseja continuar? Digite [1] para SIM [0] para NÃO'
    escolha = gets.chomp.to_i

end

p "Números pares: #{numeros_pares}"
p "Números impares: #{numeros_impares}"
