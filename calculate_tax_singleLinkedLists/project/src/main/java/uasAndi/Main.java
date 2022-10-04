/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package uasAndi;

import java.util.Scanner;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Kendaraan_Andi kendAndi;
        int tnkb;
        boolean file;
        int menu;
        SingleLinkedList_Andi SLL = new SingleLinkedList_Andi();
        System.out.println("Data Kendaraan Roda 2");
        kendAndi = new Kendaraan_Andi(1, "Andi", 2, 250, "2003", 3);
        SLL.addFirst(kendAndi);
        kendAndi = new Kendaraan_Andi(2, "Vader", 2, 100, "2009", 3);
        SLL.addLast(kendAndi);
        kendAndi = new Kendaraan_Andi(3, "Anakin", 2, 200, "2005", 3);
        SLL.addLast(kendAndi);
        SLL.print();
        
        System.out.println("Data Kendaraan Roda 2 dan Roda 4");
        kendAndi = new Kendaraan_Andi(4, "Yoda", 4, 1000, "2008", 5);
        SLL.addLast(kendAndi);
        kendAndi = new Kendaraan_Andi(5, "Kylo", 4, 2500, "2009", 5);
        SLL.addLast(kendAndi);
        kendAndi = new Kendaraan_Andi(6, "Snoke", 4, 3000, "2007", 5);
        SLL.addLast(kendAndi);
        SLL.print();
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("----------------------------");
            System.out.println("      Pajak Kendaraan       ");
            System.out.println("----------------------------");
            System.out.println("1. Data Kendaraan");
            System.out.println("2. Tampilkan transaksi ");
            System.out.println("3. Urutkan transaksi");
            System.out.println("4. Keluar ");
            System.out.print("Input Nomer : ");
            menu = sc.nextInt();
            switch (menu) {
                case 1: {
                    System.out.println("----------------------------");
                    System.out.println("      Pajak Kendaraan       ");
                    System.out.println("----------------------------");
                    do {
                        System.out.print("Masukkan TNBK : ");
                        tnkb = sc.nextInt();
                        file = SLL.Denda(tnkb);
                    } while (file == false);
                }
                break;
                case 2: {
                    SLL.tampilkanpajak();
                    System.out.println("Akumulasi Denda : Rp." + SLL.totalakhir);
                break;
                }
                case 3: {

                }
            }
        } while (menu > 0 && menu < 4);

    }
}
