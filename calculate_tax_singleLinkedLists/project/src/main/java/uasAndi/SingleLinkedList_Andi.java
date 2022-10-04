/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package uasAndi;

import java.util.Scanner;

public class SingleLinkedList_Andi {
    Scanner sc=new Scanner(System.in);
    NodeKendaraan_Andi head;
    NodeKendaraan_Andi tail;
    Kendaraan_Andi k;
    Pajak_Andi kepala;
    Pajak_Andi ekor;
    int Tarif;
    int total;
    int kode=0;
    int denda;
    int totalakhir;
    boolean IsEmpty(){
        return head==null;
    }
    boolean IsEmptyPajak(){
        return kepala==null;
    }
    void addFirst(Kendaraan_Andi input){
        NodeKendaraan_Andi ndInput=new NodeKendaraan_Andi(input,null);
        if(IsEmpty()){
            head =ndInput;
            tail =ndInput;
        }else{
            ndInput.next=head;
            head=ndInput;
        }
    }
    void addLast(Kendaraan_Andi input){
        NodeKendaraan_Andi ndInput=new NodeKendaraan_Andi(input,null);
        if(IsEmpty()){
            head =ndInput;
            tail =ndInput;
        }else{
            tail.next=ndInput;
            tail=ndInput;
        }
    }
     void addLastPajak(Kendaraan_Andi input,int kode,int nominal,int denda,int bulanbayar){
        Pajak_Andi p=new Pajak_Andi(input,kode,nominal,denda,bulanbayar,null);
        if(IsEmptyPajak()){
            kepala =p;
            ekor =p;
        }else{
            ekor.next=p;
            ekor=p;
        }
    }
    void print(){
        if(!IsEmpty()){
            NodeKendaraan_Andi tmp=head;
            System.out.println("|TNKB\t"+ "|Nama\t"+ "|Jenis\t"+ "|cc\t "+"|Tahun\t"+"|Bulan\t");
            while(tmp!=null){
                System.out.print(tmp.data.tnkb+"\t");
                System.out.print(tmp.data.nama+"\t");
                System.out.print(tmp.data.jenis+"\t");
                System.out.print(tmp.data.cc+"\t");
                System.out.print(tmp.data.tahun+"\t");
                System.out.print(tmp.data.bulan+"\t");
                System.out.println("");
                tmp=tmp.next;
                
            }
            System.out.println("    ");
        }
        else{
            System.out.println("Linked List Masih Kosong");
        }
    }
    void tampilkanpajak(){
        if(!IsEmpty()){
            Pajak_Andi tmp=kepala;
            System.out.println("Data Pajak Transaksi :\t");
            System.out.print("TNKB\t");
            System.out.print("Kode\t");
            System.out.print("Nominal\t");
            System.out.print("bulan Bayar\t");
            while(tmp!=null){
                System.out.println("");
                System.out.print(tmp.data.tnkb+"\t");
                System.out.print(tmp.kode+"\t");
                System.out.print(tmp.nominal+"\t");
                System.out.print(tmp.bulanbayar+"\t");
                tmp=tmp.next;
                
            }
            System.out.println("    ");
        }
        else{
            System.out.println("Linked List Masih Kosong");
        }
    }
    boolean Denda(int tnkb){
        NodeKendaraan_Andi tmp=head;
        while(tmp!=null){ 
            if(tmp.data.tnkb==tnkb){
                kode++;
                System.out.println("Data Ada ");
            System.out.print("jenis kendaraan :");
                System.out.println("Roda "+tmp.data.jenis);
            System.out.print("CC Kendaraan :");
                System.out.println(tmp.data.cc+"CC");
            if(tmp.data.jenis==2){   
                if(tmp.data.cc<100){
                    System.out.println("Nominal pajak = 100000");
                    Tarif=100000;
                }else if(tmp.data.cc>=100&&tmp.data.cc<=250){
                    System.out.println("Nominal pajak = 250000");
                    Tarif=250000;
                }else if(tmp.data.cc>250){
                    System.out.println("Nominal pajak = 500000");
                    Tarif=500000;
                }
            }else if(tmp.data.jenis==4){
                  if(tmp.data.cc<1000){
                    System.out.println("Nominal pajak = 750000");
                    Tarif=750000;
                }else if(tmp.data.cc>=1000&&tmp.data.cc<=2500){
                    System.out.println("Nominal pajak = 1000000");
                    Tarif=1000000;
                }else if(tmp.data.cc>2500){
                    System.out.println("Nominal pajak = 1500000");
                    Tarif=1500000;
                }
            }
            System.out.println("Bulan : "+tmp.data.bulan);
            System.out.print("Bulan Bayar : ");
            int bayar=sc.nextInt();
            int b=bayar-tmp.data.bulan;
            System.out.println("Terlambat bayar selama "+b+" Bulan");
            if(b<=3){
                System.out.println("Denda Bayar 50000");
                denda=50000;
                total=Tarif+50000;
            }else{
                total=Tarif*50000;
            }
            addLastPajak(tmp.data,kode,Tarif,denda,bayar);
            totalakhir+=total;
                return true;
            }
            tmp=tmp.next;
        }
        System.out.println("Data kosong");
        return false;
    }
    
    
}