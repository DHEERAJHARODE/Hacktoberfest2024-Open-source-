/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package uasAndi;
public class Pajak_Andi {
    int nominal,denda,bulanbayar;
    int kode;
    Kendaraan_Andi data;
    Pajak_Andi next;
    Pajak_Andi(Kendaraan_Andi data,int kode,int nominal,int denda,int bulanbayar,Pajak_Andi next){
        this.data=data;
        this.kode=kode;
        this.nominal=nominal;
        this.denda=denda;
        this.bulanbayar=bulanbayar;
        this.next=next;
    }
}
