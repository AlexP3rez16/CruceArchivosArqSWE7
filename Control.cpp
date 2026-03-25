//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int eofm = 0, eofp = 0;

string trabjador, grupo, empresa, planta, dept, OE, nombre, fech;
double salBase;

ifstream inMovimientosFile("mov.txt", ios::in);
ifstream inPersonalFile("per.txt", ios::in);
ofstream outReporteFile("Reporte.txt", ios::out);

//
void reportarMovInvalido(){

}

//
void insertRegistro(){
    
}

//
void leerRegistroMov(){
    
}

//
void leerRegistroPer(){
    
}

//
void leerArchivoPer(){

}

//
void generarReporte(){

}

//

void procActualizacion(){
    if (trab.M == trab.P){

        switch (opt){
        case "A":
            procCopia();
            reportarMovInvalido();
            break;

        case "B":
            procBaja();
            break;

        case "C":
            procCambio();
            break;

        default:
            break;
        }
            
    } else if (trab.M > trab.P){

        switch (opt){
        case "A":
            procAlta();
            reportarMovInvalido();
            break;

        case "B":
            reportarMovInvalido();
            leerRegistroMov();
            break;

        case "C":
            reportarMovInvalido();
            leerRegistroMov();
            break;

        default:
            break;
        }

    } else {
        reportarMovInvalido();
    }
    leerRegistroMov();
    leerRegistroPer();
}

//
void procCambio(){
    trab.R = trab.P;

    if(gpo.M == ""){
        gpo.R = gpo.P;
    }else{
        gpo.R = gpo.M;
    }

    if(emp.M == ""){
        emp.R = emp.P;
    }else{
        emp.R = gpo.M;
    }

    if(planta.M == ""){
        planta.R = planta.P;
    }else{
        planta.R = gpo.M;
    }

    if(dept.M == ""){
        dept.R = dept.P;
    }else{
        dept.R = gpo.M;
    }

    if(cve.M == ""){
        cve.R = cve.P;
    }else{
        cve.R = gpo.M;
    }

    if(nombre.M == ""){
        nombre.R = nombre.P;
    }else{
        nombre.R = gpo.M;
    }

    if(salBase.M == ""){
        salBase.R = salBase.P;
    }else{
        salBase.R = gpo.M;
    }

    if(fech.M == ""){
        fech.R = fech.P;
    }else{
        fech.R = gpo.M;
    }

    insertRegistro();
    generarReporte('CAMBIO');
}

//
void procAlta(){
    trab.R = trab.M;

    if(gpo.M == ""){
        gpo.R = "0000";
    }else{
        gpo.R = gpo.M;
    }

    if(emp.M == ""){
        emp.R = "0000";
    }else{
        emp.R = gpo.M;
    }

    if(planta.M == ""){
        planta.R = "0000";
    }else{
        planta.R = gpo.M;
    }

    if(dept.M == ""){
        dept.R = "0000";
    }else{
        dept.R = gpo.M;
    }

    if(cve.M == ""){
        cve.R = "0000";
    }else{
        cve.R = gpo.M;
    }

    if(nombre.M == ""){
        nombre.R = "0000";
    }else{
        nombre.R = gpo.M;
    }

    if(salBase.M == ""){
        salBase.R = 0.0;
    }else{
        salBase.R = gpo.M;
    }

    if(fech.M == ""){
        fech.R = "0000";
    }else{
        fech.R = gpo.M;
    }

    insertRegistro();
    generarReporte('ALTA');
}

//
void procBaja(){
    trab.R = trab.P;
    
    if(!(P=="")){
        generarReporte("BAJA");
    }else{
        reportarMovInvalido();
    }

}

//
void procCopia(){
    trab.R = trab.P;

    gpo.R = gpo.P;

    emp.R = emp.P;

    planta.R = planta.P;

    dept.R = dept.P;

    cve.R = cve.P;

    nombre.R = nombre.P;

    salBase.R = salBase.P;

    fech.R = fech.P;

    insertRegistro();
}

//
int main(){
    //lecturas
    while (!(per.fin && mov.fin)){
        procActualizacion();
    }
    //fin
}