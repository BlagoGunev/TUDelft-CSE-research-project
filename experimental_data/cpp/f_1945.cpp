#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

void resolver() {
    ll cantidad;
    cin >> cantidad;
    vector<ll> valoresOriginales(cantidad);
    vector<pair<ll, ll>> candidatos(cantidad);

    for (ll indice = 0; indice < cantidad; ++indice) {
        cin >> valoresOriginales[indice];
        candidatos[indice] = {valoresOriginales[indice], indice};
    }

    vector<ll> ordenQuemado(cantidad);
    for (auto& elemento : ordenQuemado) {
        cin >> elemento;
        --elemento;
    }

    sort(candidatos.rbegin(), candidatos.rend());

    ll mejorValor = candidatos[0].first;
    ll cantidadTomada = 1;

    ll valorActual;
    ll posicion = 1;
    vector<bool> quemado(cantidad);
    vector<bool> usado(cantidad);
    usado[candidatos[0].second] = true;

    for (ll paso = 0; paso + 1 < cantidad && posicion < cantidad; ++paso) {
        while (posicion < cantidad && quemado[candidatos[posicion].second]) {
            ++posicion;
        }

        if (posicion == cantidad) {
            break;
        }

        usado[candidatos[posicion].second] = true;
        valorActual = candidatos[posicion].first;
        ++posicion;

        quemado[ordenQuemado[paso]] = true;
        if (usado[ordenQuemado[paso]]) {
            while (posicion < cantidad && quemado[candidatos[posicion].second]) {
                ++posicion;
            }

            if (posicion == cantidad) {
                break;
            }

            usado[candidatos[posicion].second] = true;
            valorActual = candidatos[posicion].first;
            ++posicion;
        }

        if (mejorValor < valorActual * (paso + 2)) {
            cantidadTomada = paso + 2;
            mejorValor = valorActual * (paso + 2);
        }
    }

    cout << mejorValor << ' ' << cantidadTomada << '\n';
}

int32_t main() {
    ll numeroCasos;
    cin >> numeroCasos;
    while (numeroCasos--) {
        resolver();
    }
    return 0;
}