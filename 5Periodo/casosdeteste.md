# Relatório de Execução de Testes: Plataforma Focus Map

## 1. Visão Geral da Aplicação
O componente web do projeto **Focus Map** foi desenvolvido com o objetivo de auxiliar profissionais no gerenciamento clínico. As principais funcionalidades da plataforma incluem a organização de pacientes, o mapeamento de pontos de interesse e o registro detalhado de sessões terapêuticas.

## 2. Metodologia de Testes
Para a validação funcional do sistema, adotou-se a estratégia de **Testes de Caixa Preta**. O objetivo primário foi verificar a conformidade de cada função principal em relação aos requisitos estabelecidos, garantindo a integridade das operações de entrada e saída de dados.

## 3. Análise de Resultados e Correções
Durante a fase de execução, foram identificadas inconsistências que demandaram refatoração do código. A análise permitiu isolar comportamentos inesperados e vulnerabilidades de validação.

### Estudo de Caso: Falha de Validação no Cadastro (CT06)
Um exemplo crítico identificado foi o caso de teste **CT06**, que avaliou a robustez do sistema contra cadastros com campos vazios.

* **Comportamento Esperado:** O sistema deveria bloquear a requisição e exibir uma mensagem de erro ao receber um formulário sem dados.
* **Comportamento Observado:** O sistema permitiu a submissão de dados nulos, sendo a operação interrompida apenas pela restrição de unicidade do banco de dados (usuário nulo duplicado), e não por validação no *front-end* ou *back-end* prévio.
* **Ação Corretiva:** Foram implementadas regras de validação obrigatória. Atualmente, a criação de novos registros exige o preenchimento válido dos campos `Nome`, `E-mail` e `Senha`.

## 4. Próximos Passos
O ciclo de desenvolvimento segue em andamento, com foco na correção das demais falhas apontadas na matriz de testes e na implementação de melhorias contínuas de usabilidade e segurança.

# Testes de Caixa Preta - Site Focus Map

| ID | Teste | Objetivo | Entradas | Passos Executados | Resultado Esperado | Resultado Obtido | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---: |
| **CT 01** | Login Válido | Realizar Login com dados válidos | `claudio.batista@hotmail.com`<br>`Batata@1` | Acesso ao Site, inserção dos dados, clicar em "Entrar" | Login efetuado com sucesso | Página Inicial Acessada | ✅ |
| **CT 02** | Login Inválido | Realizar Login com dados inválidos | `teste.invalido@teste.com`<br>`testeinv` | Acesso ao Site, inserção dos dados, clicar em "Entrar" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 03** | Login Inválido | Realizar Login vazio | *(Vazio)* | Acesso ao Site, clicar em "Entrar" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 04** | Criar Conta Válida | Realizar cadastro válido | `Enrico`<br>`enrico.araujo@sga.pucminas.br`<br>`teste04` | Clicar em "Faça seu Cadastro", inserir dados, "Criar Conta" | Acesso a página inicial | Página Inicial Acessada | ✅ |
| **CT 05** | Criar Conta Inválida | Cadastro com dados duplicados | `Teste 04`<br>`claudio.batista@hotmail.com`<br>`Batata@1` | Inserir dados já cadastrados, "Criar Conta" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 06** | Criar Conta Limite | Cadastro sem dados | *(Vazio)* | Clicar em "Faça seu Cadastro", clicar em "Criar Conta" | Mensagem de Erro | **Acesso à página inicial** | ❌ |
| **CT 07** | Criar Conta Limite | Cadastro com dados mínimos | `A`<br>`A@email.com`<br>`123456` | Inserir dados mínimos, "Criar Conta" | Mensagem de Erro | **Acesso à página inicial** | ❌ |
| **CT 08** | Cadastro Paciente Válido | Cadastrar paciente válido | `Teste 08`<br>`teste08@teste.com`<br>`Teste08!` | Inserir dados, "Cadastrar Paciente" | Mensagem de Sucesso | Cadastro Realizado (sem mensagem de sucesso) | ⚠️ |
| **CT 09** | Cadastro Paciente Inválido | Cadastrar paciente inválido | `Teste 09`<br>`teste09`<br>`teste09` | Inserir dados, "Cadastrar Paciente" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 10** | Cadastro Paciente Inválido | Cadastrar paciente vazio | *(Vazio)* | Clicar em "Cadastrar Paciente" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 11** | Cadastro Paciente Limite | Cadastrar paciente dados mínimos | `B`<br>`A@email.com`<br>`Tes11!` | Inserir dados, "Cadastrar Paciente" | Mensagem de Sucesso | Cadastro Realizado (sem mensagem de sucesso) | ⚠️ |
| **CT 12** | Recuperação de Senha | Recuperar senha | `enrico.araujo@sga.pucminas.br` | Clicar em "Esqueceu sua senha?", inserir e-mail | Mensagem de sucesso + e-mail | Mensagem de sucesso (falta envio de e-mail) | ⚠️ |
| **CT 13** | Acesso Pontos Interesse | Visualizar interesses | *(N/A)* | Clicar no símbolo azul na lista de pacientes | Lista de pontos de Interesse | Lista de pontos de Interesse | ✅ |
| **CT 14** | Cad. Ponto Interesse Válido | Cadastrar interesse válido | `Matemática` | Clicar "Novo Ponto", digitar, "Salvar" | Mensagem de Sucesso | **Aviso de Erro** | ⚠️ |
| **CT 15** | Cad. Ponto Interesse Mínimo | Cadastrar interesse mínimo | `A` | Clicar "Novo Ponto", digitar, "Salvar" | Mensagem de Sucesso | **Aviso de Erro** | ⚠️ |
| **CT 16** | Cad. Ponto Interesse Inválido | Cadastrar interesse vazio | *(Vazio)* | Clicar "Novo Ponto", digitar, "Salvar" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 17** | Exclusão Ponto Interesse | Excluir interesse | *(N/A)* | Clicar no lixo vermelho ao lado do ponto | Exclusão em tempo real | Exclusão em tempo real | ✅ |
| **CT 18** | Exclusão de Paciente | Excluir paciente | *(N/A)* | Clicar na lixeira vermelha ao lado do paciente | Exclusão em tempo real | **Paciente continua na lista** | ❌ |
| **CT 19** | Visualizar Sessão | Exportar dados sessão | *(N/A)* | "Histórico de Sessões" > "Visualizar" > "Exportar" | Baixar arquivo | Mensagem de exportação (falta implementar download) | ⚠️ |
| **CT 20** | Cadastro de Paciente Inválido | Cadastrar um paciente com dados já cadastrados | `Teste 20`<br>`teste08@teste.com`<br>`Teste20!` | Inserir dados, "Cadastrar Paciente"  | Mensagem de Erro | Atualização da página, como quando ocorre o cadastro. Não foi adicionado um paciente Teste 20, porém, não foi apresentada uma mensagem de erro | ⚠️ |

**Legenda:** ✅ Aprovado | ❌ Reprovado (Bug Crítico) | ⚠️ Atenção (Bug Menor/Melhoria)
