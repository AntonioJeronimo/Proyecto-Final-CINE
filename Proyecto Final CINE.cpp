//--------------------------------
//|Programa de Cine VIP by Winter|
//--------------------------------
// Equipo:
// - Antonio Jeronimo Ramirez
// - Ruben Ramirez Alba
// - Cesar Santiago Carrasco Puertos
// - Citlali Huacuja Contreras
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
const int FILAS = 6;
const int COLUMNAS = 5;
int asiDisp = FILAS * COLUMNAS;
int asiDispOri = FILAS * COLUMNAS;
void imprimirCine(vector < vector < char > > & cine) {
	cout << "     1   2   3   4   5" << endl;
	cout << "     -----------------" << endl;
	cout << "     |P A N T A L L A|" << endl;
	cout << "     -----------------" << endl;
    for (int i = 0; i < cine.size(); i++) {
        cout << setw(2) << char('A' + i) << " ";
        for (int j = 0; j < cine[i].size(); j++) {
            cout << setw(3) << cine[i][j] << " ";
        }
        cout << endl;
    }
}
bool verificarDisponibilidad(vector < vector < char > > & cine, int fila, int columna) {
    if (fila < 0 || fila >= cine.size() || columna < 0 || columna >= cine[0].size()) {
        cout << "Asiento inválido." << endl;
        return false;
    }
    if (cine[fila][columna] == 'X') {
        cout << "El asiento seleccionado ya está ocupado." << endl;
        return false;
    }
    return true;
}
float calcularPorcentajeOcupacion(vector < vector < char> > & cine) {
    int totalAsientos = cine.size() * cine[0].size();
    int asientosOcupados = 0;
    for (int i = 0; i < cine.size(); i++) {
        for (int j = 0; j < cine[i].size(); j++) {
            if (cine[i][j] == 'X') {
                asientosOcupados++;
            }
        }
    }
    return (static_cast<float>(asientosOcupados) / totalAsientos) * 100.0;
}
int main() {
    vector < vector < char > > cine(FILAS, vector < char> (COLUMNAS, '-'));
    float costoBoleto;
    int opcion, totalAPagar;
    system
	("title Codio de Winter");
    cout << "----------------------------------------------------------------" << endl;
    cout << "|           B i e n v e n i d o  a l  C i n e  V I P           |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "|       I n g r e s e  e l  c o s t o  d e l  b o l e t o      |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cin >> costoBoleto;
    system ("cls");
    do {
    	float porcentajeOcupacion = calcularPorcentajeOcupacion(cine);
        if(porcentajeOcupacion<=25){
        	system("color a");
		}
        else if(porcentajeOcupacion<=50){
        	system("color 9");
		}
        else if(porcentajeOcupacion<=75){
        	system("color e");
		}
        else if(porcentajeOcupacion<=100){
        	system("color c");
		}
		imprimirCine(cine);
        cout << "----------------------------------------------------------------" << endl;
        cout << "|                          M  E  N  U                          |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|         1 . -  C o m p r a r  b o l e t o s                  |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|         2 . -  H a c e r  c o r t e  d e  c a j a            |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|         3 . -  S a l i r  d e l  p r o g r a m a             |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|              I n g r e s e  u n a  o p c i o n               |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cin >> opcion;
        system ("cls");
        switch (opcion) {
            case 1: {
            	asiDispOri = asiDisp;
            	vector<vector<char> > cineReserva(cine);
            	int numBoletos;
				cout << "----------------------------------------------------------------" << endl;
                cout << "|N u m e r o  d e  b o l e t o s  a  c o m p r a r (0 = Salir) |" << endl;
                cout << "----------------------------------------------------------------" << endl;
				cin >> numBoletos;
				system("cls");
				if (numBoletos == 0) {
				    break;
				}
				if (numBoletos == asiDisp ){
                	for (int i = 0; i < FILAS; i++) {
				        for (int j = 0; j < COLUMNAS; j++) {
				            cine[i][j] = 'X';
				            asiDisp--;
				        }
				    }
				    float montoAPagar = costoBoleto * asiDispOri;
					char confirmacion;
					cout << "----------------------------------------------------------------" << endl;
	                cout << "|                       P A N T A L L A                        |" << endl;
	                cout << "----------------------------------------------------------------" << endl;
					imprimirCine(cine);
					cout << "----------------------------------------------------------------" << endl;
					cout << "|       ¿ s e g u r o  d e  l a  c o m p r a ? ( S / N )       |" << endl;
					cout << "----------------------------------------------------------------" << endl;
					cin >> confirmacion;
					if (toupper(confirmacion) != 'S') {
					    cine = cineReserva;
					    cout << "----------------------------------------------------------------" << endl;
					    cout << "|         C  o  m  p  r  a   c  a  n  c  e  l  a  d  a         |" << endl;
					    cout << "----------------------------------------------------------------" << endl;
					    asiDisp = asiDispOri;
					} else {
					    totalAPagar += numBoletos;
					    cout << "----------------------------------------------------------------" << endl;
		                cout << "|M o n t o  a  p a g a r  $" << montoAPagar << "|" << endl;
		                cout << "----------------------------------------------------------------" << endl;
					}
                	break;
				}
				if (numBoletos > asiDisp) {
				    cout << "----------------------------------------------------------------" << endl;
                    cout << "|      N o  h a y  s u f i c i e n t e s  a s i e n t o s      |" << endl;
                    cout << "----------------------------------------------------------------" << endl;
				    break;
				}
				for (int i = 0; i < numBoletos; i++) {
				    char fila;
				    int columna;
				    system("cls");
				    cout << "----------------------------------------------------------------" << endl;
	                cout << "|                       P A N T A L L A                        |" << endl;
	                cout << "----------------------------------------------------------------" << endl;
				    imprimirCine(cine);
				    cout << "----------------------------------------------------------------" << endl;
                    cout << "|I n g r e s e  e l  a s i e n t o -> " << (i + 1) << " <-(e j e m p l o : A 1)|" <<endl;
                    cout << "----------------------------------------------------------------" << endl;
				    cin >> fila >> columna;
				    asiDisp--;
				    fila = toupper(fila);
				    columna--;
				    int filaIndex = fila - 'A';
				    int columnaIndex = columna;
				    if (!verificarDisponibilidad(cine, filaIndex, columnaIndex)) {
				        i--;
				        continue;
				    }
				    cine[filaIndex][columnaIndex] = 'X';
				}
				float montoAPagar = costoBoleto * numBoletos;
				char confirmacion;
				system ("cls");
				cout << "----------------------------------------------------------------" << endl;
                cout << "|                       P A N T A L L A                        |" << endl;
                cout << "----------------------------------------------------------------" << endl;
				imprimirCine(cine);
				cout << "----------------------------------------------------------------" << endl;
				cout << "|       ¿ s e g u r o  d e  l a  c o m p r a ? ( S / N )       |" << endl;
				cout << "----------------------------------------------------------------" << endl;
				cin >> confirmacion;
				if (toupper(confirmacion) != 'S') {
				    cine = cineReserva;
				    cout << "----------------------------------------------------------------" << endl;
				    cout << "|         C  o  m  p  r  a   c  a  n  c  e  l  a  d  a         |" << endl;
				    cout << "----------------------------------------------------------------" << endl;
				    asiDisp=asiDispOri;
				} else {
				    totalAPagar += numBoletos;
				    cout << "----------------------------------------------------------------" << endl;
	                cout << "|M o n t o  a  p a g a r  $" << montoAPagar << "|" << endl;
	                cout << "----------------------------------------------------------------" << endl;
				}
				system ("pause");
                system("cls");
				break;
            } 
            case 2: {
                cout << "----------------------------------------------------------------" << endl;
                cout << "|        T o t a l  d e  b o l e t o s  v e n d i d o s        |" << endl;
                cout << "----------------------------------------------------------------" << endl;
                cout << totalAPagar << " Boletos vendidos" << endl;
                cout << "----------------------------------------------------------------" << endl;
                cout << "|          P o r c e n t a j e  d e  o c u p a c i ó n         |" << endl;
                cout << "----------------------------------------------------------------" << endl;
                cout << "--> "<<porcentajeOcupacion << "% <--" << endl;
                cout << "----------------------------------------------------------------" << endl;
                cout << "|                      V e n t a  t o t a l                    |" << endl;
                cout << "----------------------------------------------------------------" << endl;
                cout << totalAPagar * costoBoleto << endl;
                break;
            }
            case 3: {
            	cout << "----------------------------------------------------------------" << endl;
                cout << "|        S a l i e n d o  d e l  p r o g r a m a . . .         |" << endl;
                cout << "----------------------------------------------------------------" << endl;
                break;
            }
            default:
            	cout << "----------------------------------------------------------------" << endl;
                cout << "| O p c i ó n  i n v á l i d a. I n t e n t e  d e  n u e v o. |" << endl;
                cout << "----------------------------------------------------------------" << endl;
        }
    } while (opcion != 3);
    return 0;
}
