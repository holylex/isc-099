//Alexandre Perez
//2005-0427
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

class GestorConfiguracion {
private:
    string filename;
    fstream doc;
    bool actualizacionpendiente;
    map<string, string> pares;

    string cleanline(string sucia){
        string limpia;
        for(int i = 0; i < sucia.length(); i++) {
            if(sucia[i] == ' ') {
                continue;
            } else {
                limpia += sucia[i];
            }
        }
        return limpia;
    }

public:
    GestorConfiguracion(){
        std::fstream doc;
        actualizacionpendiente = false;
        std::map<string, string> pares;
        string filename;
    }

    void Cargar(string archivo){
        string linea;
        filename = archivo;
        doc.open (filename.c_str());

        while(getline(doc, linea)){
            linea = cleanline(linea);
            string delimiter = ":";
            string key = linea.substr(0, linea.find(delimiter));
            string value = linea.substr(linea.find(delimiter)+1);
            pares[key] = value;
        }

        actualizacionpendiente = false;
        doc.close();
    }

    string valorDe(string propiedad){
        return pares[propiedad];
    }

    string Actualizar(string propiedad, string valor){
        //Esta funcion pudo ser tipo void, mas el profesor nunca confirmo esto.
        pares[propiedad] = valor;
        actualizacionpendiente = true;
        return valor;
    }

    void Guardar(){
        ofstream doc(filename.c_str());
        map<string, string>::iterator iter;
        for (iter = pares.begin(); iter != pares.end(); ++iter) {
            doc << iter->first << ":" << iter->second << '\n';
        }
        doc.close();
        actualizacionpendiente = false;
    }

    bool ActualizacionPendiente(){
        return actualizacionpendiente;
    }
};



int main()
{
    GestorConfiguracion gc;
    gc.Cargar("conf.properties");
    cout << "IP: " << gc.valorDe("IP") << endl;
    gc.Actualizar("IP", "192.155.10.15");
    cout << "Cambios pendientes? " << gc.ActualizacionPendiente() << endl;
    gc.Guardar();
    cout << "Cambios pendientes? " << gc.ActualizacionPendiente() << endl;
}
