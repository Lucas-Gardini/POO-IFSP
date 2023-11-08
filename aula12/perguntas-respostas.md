# Considere o código abaixo e responda as perguntas a seguir

```cpp
#include <iostream>
using namespace std;

namespace namespaceComUmNomeSuficientementeLongo {
    void umaFuncao() {
        cout << "Essa função faz alguma coisa" << endl;
    }

    namespace umNome {
        void umaFuncao() {
            cout << "Essa função faz alguma outra coisa" << endl;
        }
    }
}

namespace {
    void outraFuncao() {
        cout << "Essa é a outra função" << endl;
    }

    void aindaOutraFuncao() {
        cout << "Essa mais uma função" << endl;
    }
}

void aindaOutraFuncao() {
    cout << "Isso está ficando complicado..." << endl;
}
```

## 1. Explique em detalhe o que a instrução a seguir faz. O que é exibido?

`namespaceComUmNomeSuficientementeLongo::umaFuncao();`

O código acima chama a função `umaFuncao()` que está dentro do namespace `namespaceComUmNomeSuficientementeLongo`.

O que é exibido é a mensagem "Essa função faz alguma coisa".

## 2. Explique em detalhe o que as instruções a seguir fazem. O que é exibido?

```cpp
namespace sl = namespaceComUmNomeSuficientementeLongo;
sl::umaFuncao();
```

O código acima cria um alias para o namespace `namespaceComUmNomeSuficientementeLongo` chamado `sl`.

O que é exibido é a mensagem "Essa função faz alguma coisa".

## 3. Explique em detalhe o que as instruções a seguir fazem. O que é exibido?

```cpp
namespace sl = namespaceComUmNomeSuficientementeLongo;
using sl::umaFuncao;
umaFuncao();
```

O código acima cria um alias para o namespace `namespaceComUmNomeSuficientementeLongo` chamado `sl`.

O código utiliza a diretiva `using` para importar a função `umaFuncao()` que está dentro do namespace `sl`.

O que é exibido é a mensagem "Essa função faz alguma coisa".

## 4. Explique em detalhe o que as instruções a seguir fazem. O que é exibido?

```cpp
namespace sl = namespaceComUmNomeSuficientementeLongo;
using namespace sl::umNome;
umaFuncao();
```

O código acima cria um alias para o namespace `namespaceComUmNomeSuficientementeLongo` chamado `sl`.

O código utiliza a diretiva `using` para importar o namespace `umNome` que está dentro do namespace `sl`.

A partir daí, a função `umaFuncao()` pode ser chamada diretamente.

O que é exibido é a mensagem "Essa função faz alguma outra coisa".

## 5. Explique em detalhe o que as instruções a seguir fazem. O que é exibido?

```cpp
namespace sl = namespaceComUmNomeSuficientementeLongo;
using sl::umNome::umaFuncao;
umaFuncao();
```

O código acima cria um alias para o namespace `namespaceComUmNomeSuficientementeLongo` chamado `sl`.

O código utiliza a diretiva `using` para importar a função `umaFuncao()` que está dentro do namespace `umNome` que está dentro do namespace `sl`.

O que é exibido é a mensagem "Essa função faz alguma outra coisa".

## 6. O que ocorre se executarmos o seguinte código? Por quê?

```cpp
aindaOutraFuncao();
```

O código acima gera um erro de ambiguidade, pois existem duas funções com o mesmo nome, uma no namespace anônimo e outra no namespace global.

## 7. Como podemos corrigir o código acima para chamarmos aindaOutraFuncao() do espaço global de nomes? É possível chamarmos aindaOutraFuncao() do namespace anônimo?

É impossível chamar a função `aindaOutraFuncao()` do namespace anônimo, pois não há como criar um alias para um namespace anônimo.

Sendo assim, o compilador não consegue diferenciar qual das duas funções deve ser chamada.
