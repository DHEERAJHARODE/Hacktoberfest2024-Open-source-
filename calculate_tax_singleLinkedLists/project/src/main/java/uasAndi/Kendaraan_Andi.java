/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package uasAndi;

public class Kendaraan_Andi {

    String nama, tahun;
    int bulan, cc, jenis, tnkb;

    Kendaraan_Andi(int tnkb, String nama, int jenis, int cc, String tahun, int bulan) {

        this.tnkb = tnkb;
        this.nama = nama;
        this.jenis = jenis;
        this.cc = cc;
        this.tahun = tahun;
        this.bulan = bulan;

    }
}
