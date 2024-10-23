# programa com hash para armazenar informações dos alunos
# a chave do hash é o numero da matricula como identificador

# programa deve permitir cadastrar consultar e inserir

# informaçoes do aluno: matricula, nome, media das notas

def cadastra_aluno(hash_alunos)
    p "Preparando operação de cadastro"
    puts
    p "Digite a matricula do aluno"
    matricula = gets.chomp.to_i
    p "Digite o nome do aluno"
    nome = gets.chomp
    p "Digite a media do aluno"
    media = gets.chomp.to_f
    
    hash_alunos[matricula] = {nome: nome, media: media}
end

def consulta_aluno(hash_alunos)
    p "Preparando operação de consulta filtrada"
    puts

    p "Digite a matricula do aluno"
        matricula = gets.chomp.to_i
        puts
        hash_alunos.key?(matricula)
        aluno = hash_alunos[matricula]
        p 'Dados do aluno'
        p "================"
        p "Nome: #{aluno[:nome]}"
        p "Media: #{aluno[:media]}"
end

def consulta_geral(hash_alunos)
    p "Preparando operação de consulta completa"
    puts
    
    hash_alunos.each do |matricula, dados|
    p "Matricula: #{matricula} - Nome: #{dados[:nome]} - Média: #{dados[:media]}"
    end
end


matricula = 0
escolha_usuario = 0
flag_controla_programa = 1
nome = "coringa"
media = 0

#hash_alunos = {}
until flag_controla_programa == 0
    puts
    p "Sistema de Gerenciamento de Alunos - Menu de Operações"
    p "============================================="
    p "Qual operação você gostaria de realizar?"
    p "[1] Cadastrar novos alunos"
    p "[2] Consultar dados de um aluno"
    p "[3] Consultar toda lista de alunos"
    p "[0] Sair"
    puts
    escolha_usuario = gets.chomp.to_i
    puts
    case escolha_usuario
        when 0
            p "Até mais"
            flag_controla_programa = escolha_usuario
        when 1
            hash_alunos = cadastra_aluno(hash_alunos)
        when 2
            consulta_aluno(hash_alunos)
        when 3
            consulta_geral(hash_alunos)
        else
            p "Por favor, escolha uma operação válida"
        end
end
