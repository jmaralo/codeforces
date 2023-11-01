#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // si tiene longitud impar nunca va a tener solucion
    if (n % 2 != 0) {
        cout << "-1\n";
        return;
    }

    // Creamos dos deques (double ended queues), l y r.
    // a l le pusheamos por el front la mitad de los caracteres y a r
    // la otra mitad empezando por el final
    // la idea es que l y r siempre tengan la misma cantidad de elementos.
    deque<char> l, r;
    for (int i = 0; i < n / 2; i++) {
        l.push_front(s[i]);
        r.push_front(s[n - i - 1]);
    }

    // j lleva cuenta de cuantas veces aplicamos la operacion
    // i lleva cuenta de por que indice vamos
    int j = 0, i = 0;
    // ans guarda el resultado
    vector<int> ans;
    // iteras hasta que te quedes sin caracteres en las listas (se puede solucionar)
    // o aplicamos mas de 300 operaciones (no tiene solucion valida)
    while ((!l.empty() && !r.empty()) && j <= 300) {
        // pillamos el siguiente caracter a comparar
        char a = l.back(), b = r.back();

        // comprobamos si son iguales y a que equivalen
        if (a == '1' && b == '1') {
        // si son iguales a 1 hay que hacer la operacion en el extremo izquierdo (ponemos un cero al principio)
            // eliminamos un elemento de l y de r
            // como vamos a meter el string "01" en l, simplemente no metemos el 0 en l y ya
            r.pop_back();
            // anotamos la posicion donde insertamos y actualizamos j
            ans.push_back(i);
            j++;

            // por añadir el "01"
            l.push_back('1');

            // como ahora l y r estan "desbalanceados" (l tiene mas elementos que r), pasamos un elemnto a r
            r.push_front(l.front());
            l.pop_front();
            
            // actualizamos el numero de caracteres que tenemos
            n += 2;
        } else if (a == '0' && b == '0') {
        // si son iguales a 0 hay que hacer la operacion en el extremo derecho (ponemos un uno al final)
            // repetimos lo de antes pero poniendo "01" en r
            l.pop_back();
            ans.push_back(n - i);
            j++;
            r.push_back('0');
            l.push_front(r.front());
            r.pop_front();
            n += 2;
        } else {
        // si no son iguales esta bien y podemos eliminar los dos elementos
            l.pop_back();
            r.pop_back();
        }
        i++;
    }

    // comprobamos si el bucle ha determinado que no tiene solucion
    if (j > 300) {
        cout << "-1\n";
        return;
    }

    cout << j << "\n";
    for (int i = 0; i < j; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!TESTCASES) {
        solve(0);
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}