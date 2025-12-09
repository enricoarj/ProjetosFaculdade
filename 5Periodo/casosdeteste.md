# Casos de Teste - Projeto X

| ID | Teste | Objetivo | Entradas | Passos Executados | Resultado Esperado | Resultado Obtido | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---: |
| **CT 01** | Login Válido | Realizar Login com dados válidos | `claudio.batista@hotmail.com`<br>`Batata@1` | Acesso ao Site, inserção dos dados, clicar em "Entrar" | Login efetuado com sucesso | Página Inicial Acessada | ✅ |
| **CT 02** | Login Inválido | Realizar Login com dados inválidos | `teste.invalido@teste.com`<br>`testeinv` | Acesso ao Site, inserção dos dados, clicar em "Entrar" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 03** | Login Inválido | Realizar Login vazio | *(Vazio)* | Acesso ao Site, clicar em "Entrar" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 04** | Criar Conta Válida | Realizar cadastro válido | `Enrico`<br>`enrico.araujo@sga.pucminas.br`<br>`teste04` | Clicar em "Faça seu Cadastro", inserir dados, "Criar Conta" | Acesso a página inicial | Página Inicial Acessada | ✅ |
| **CT 05** | Criar Conta Inválida | Cadastro com dados duplicados | `Teste 04`<br>`teste04`<br>`teste 04` | Inserir dados já cadastrados, "Criar Conta" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 06** | Criar Conta Limite | Cadastro sem dados | *(Vazio)* | Clicar em "Faça seu Cadastro", clicar em "Criar Conta" | Mensagem de Erro | **Acesso à página inicial** | ❌ |
| **CT 07** | Criar Conta Limite | Cadastro com dados mínimos | `A`<br>`A@email.com`<br>`123456` | Inserir dados mínimos, "Criar Conta" | Mensagem de Erro | **Acesso à página inicial** | ❌ |
| **CT 08** | Cadastro Paciente Válido | Cadastrar paciente válido | `Teste 08`<br>`teste08@teste.com` | Inserir dados, "Cadastrar Paciente" | Mensagem de Sucesso | Cadastro Realizado (sem msg sucesso) | ⚠️ |
| **CT 09** | Cadastro Paciente Inválido | Cadastrar paciente inválido | `Teste 09`<br>`teste09` | Inserir dados, "Cadastrar Paciente" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 10** | Cadastro Paciente Inválido | Cadastrar paciente vazio | *(Vazio)* | Clicar em "Cadastrar Paciente" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 11** | Cadastro Paciente Limite | Cadastrar paciente dados mínimos | `A`<br>`B@email.com` | Inserir dados, "Cadastrar Paciente" | Mensagem de Sucesso | Cadastro Realizado (sem msg sucesso) | ⚠️ |
| **CT 12** | Recuperação de Senha | Recuperar senha | `enrico.araujo@sga.pucminas.br` | Clicar em "Esqueceu sua senha?", inserir e-mail | Msg sucesso + e-mail | Msg sucesso (falta envio de e-mail) | ⚠️ |
| **CT 13** | Acesso Pontos Interesse | Visualizar interesses | *(N/A)* | Clicar no símbolo azul na lista de pacientes | Lista de pontos de Interesse | Lista de pontos de Interesse | ✅ |
| **CT 14** | Cad. Ponto Interesse Válido | Cadastrar interesse válido | `Matemática` | Clicar "Novo Ponto", digitar, "Salvar" | Mensagem de Sucesso | **Aviso de Erro** | ⚠️ |
| **CT 15** | Cad. Ponto Interesse Mínimo | Cadastrar interesse mínimo | `A` | Clicar "Novo Ponto", digitar, "Salvar" | Mensagem de Sucesso | **Aviso de Erro** | ⚠️ |
| **CT 16** | Cad. Ponto Interesse Inválido | Cadastrar interesse vazio | *(Vazio)* | Clicar "Novo Ponto", digitar, "Salvar" | Mensagem de Erro | Mensagem de Erro | ✅ |
| **CT 17** | Exclusão Ponto Interesse | Excluir interesse | *(N/A)* | Clicar no lixo vermelho ao lado do ponto | Exclusão em tempo real | Exclusão em tempo real | ✅ |
| **CT 18** | Exclusão de Paciente | Excluir paciente | *(N/A)* | Clicar na lixeira vermelha ao lado do paciente | Exclusão em tempo real | **Paciente continua na lista** | ❌ |
| **CT 19** | Visualizar Sessão | Exportar dados sessão | *(N/A)* | "Histórico de Sessões" > "Visualizar" > "Exportar" | Baixar arquivo | Msg exportação (falta implementar download) | ⚠️ |

**Legenda:** ✅ Aprovado | ❌ Reprovado (Bug Crítico) | ⚠️ Atenção (Bug Menor/Melhoria)
